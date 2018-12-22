// The main game loop is written here.

#include "gba.h"
#include "bg.h"
#include "ball.h"
#include "bar.h"

#include "pong.h"

OAMEntry sprites[128];

u16 xball = 30;
u16 yball = 50;
u8 ballDir = 0;

u16 xbar = 10;
u16 ybar = 10;

u8 xMin = 8;
u8 yMin = 8;
u8 xMax = 224;
u8 yMax = 144;

int main()
{
	u16 loop;

	SetMode(MODE_4 | BG2_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);

	// Transfer the ball palette into palette memory.
	for(loop = 0; loop < 256; ++loop)
	{
		OBJ_PaletteMem[loop] = ballPalette[loop];
	}

	// Transfer background palette data to palette memory.
	for(loop = 0; loop < 256; ++loop)
	{
		BG_PaletteMem[loop] = bgPalette[loop];
	}

	// Transfer background pixel data into VRAM.
	for(loop = 0; loop < (120 * 160); ++loop)
	{
		FrontBuffer[loop] = bgData[loop];
	}

	// Copy the ball pixel data to the first location in sprite data.
	memcpy((u16*)0x06014000, &ballData, sizeof(ballData));
	memcpy((u16*)0x06014100, &barData,  sizeof(barData));

	// Now create the sprite.
	sprites[0].attribute0 = COLOR_256 | SQUARE | yball;
	sprites[0].attribute1 = SIZE_8 | xball;
	sprites[0].attribute2 = 512;

	sprites[1].attribute0 = COLOR_256 | TALL | ybar;
	sprites[1].attribute1 = SIZE_16 | xbar;
	sprites[1].attribute2 = 512 + 8;

	// Start the game loop.
	while(1)
	{
		MoveBall();
		MoveBar();
		MoveSprite(&sprites[0], xball, yball);
		MoveSprite(&sprites[1], xbar, ybar);
		WaitForVsync();
		CopyOAM();
	}

	return 0;
}

// Initialise and move sprites to (240, 160) so they are hidden at start.
void InitialiseSprites(void)
{
	u16 loop;

	for(loop = 0; loop < 128; ++loop)
	{
		sprites[loop].attribute0 = 160;
		sprites[loop].attribute1 = 240;
	}
}

// Copy data for each sprite to OAM memory.
void CopyOAM(void)
{
	u16 loop;
	u16* temp;
	temp = (u16*)sprites;

	for(loop = 0; loop < 128 * 4; ++loop)
	{
		OAM_Mem[loop] = temp[loop];
	}
}

// Move a sprite by an amount.
void MoveSprite(OAMEntry* sp, int x, int y)
{
	sp->attribute1 = sp->attribute1 & 0xFE00;
	sp->attribute1 = sp->attribute1 | x;

	sp->attribute0 = sp->attribute0 & 0xFF00;
	sp->attribute0 = sp->attribute0 | y;
}

// Move the ball sprite.
void MoveBall(void)
{
	if(ballDir == 0)
	{
		if(xball >= xMax)
		{
			ballDir = 3;
		}
		else if(yball >= yMax)
		{
			ballDir = 1;
		}
		else
		{
			xball += 3;
			yball += 2;
		}
	}
	
	if(ballDir == 1)
	{
		if(xball >= xMax)
		{
			ballDir = 2;
		}
		else if(yball <= yMin)
		{
			ballDir = 0;
		}
		else
		{
			xball += 3;
			yball -= 2;
		}
	}
	
	if(ballDir == 2)
	{
		if(xball <= xMin)
		{
			ballDir = 1;
		}
		else if(yball <= yMin)
		{
			ballDir = 3;
		}
		else if(xball == xbar + 8 && yball >= ybar && yball <= ybar + 32)
		{
			ballDir = 1;
		}
		else
		{
			xball -= 3;
			yball -= 2;
		}
	}
	
	if(ballDir == 3)
	{
		if(xball <= xMin)
		{
			ballDir = 0;
		}
		else if(yball >= yMax)
		{
			ballDir = 2;
		}
		else if(xball == xbar + 8 && yball >= ybar && yball <= ybar + 32)
		{
			ballDir = 0;
		}
		else
		{
			xball -= 3;
			yball += 2;
		}
	}
}

// Move the bar sprite.
void MoveBar(void)
{
	if(keyDown(KEY_DOWN) && ybar < yMax - 24)
	{
		ybar += 3;
	}
	else if(keyDown(KEY_UP) && ybar > yMin)
	{
		ybar -= 3;
	}
}
