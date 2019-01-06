// Where the action happens.

#include "gba/gba.h"
#include "itt-adv.h"

// Include backgrounds.
#include "sprite/bg.h"

// Include sprites.
#include "sprite/ball.h"
#include "sprite/bar.h"
#include "sprite/crack.h"
#include "sprite/numbers.h"
#include "sprite/item_sprites.h"

#include "test.h"

//#include "data/item.h"
//#include "data/recipe.h"

OAMEntry sprites[128];

u16 xball = 30;
u16 yball = 15;
u8 xspeed = 4;
u8 yspeed = 2;
u8 ballDir = 0;

u16 xbar = 10;
u16 ybar = 10;

u16 xai = 222;
u16 yai = 10;

u8 xMin = 8;
u8 yMin = 8;
u8 xMax = 224;
u8 yMax = 144;

u8 playerScore = 0;
u8 aiScore = 0;

// Application entry point.
int main()
{
	//initialiseSprites();

	u16 loop;

	SetMode(MODE_4 | BG2_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);

	// Transfer the item palette into palette memory.
	for(loop = 0; loop < 256; ++loop)
	{
		OBJ_PaletteMem[loop] = itemPalette[loop];
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
	memcpy((u16*)0x06014000, &ballData, 	sizeof(ballData));

	memcpy((u16*)0x06014100, &testData2, 	sizeof(testData2));

	/*
	memcpy((u16*)0x06014100, &barData,  	sizeof(barData));
	memcpy((u16*)0x06014300, &crackData, 	sizeof(crackData));
	memcpy((u16*)0x06014400, &number0Data, 	sizeof(number0Data));
	memcpy((u16*)0x06014500, &number1Data, 	sizeof(number1Data));
	memcpy((u16*)0x06014600, &number2Data, 	sizeof(number2Data));
	memcpy((u16*)0x06014700, &number3Data, 	sizeof(number3Data));
	memcpy((u16*)0x06014800, &number4Data, 	sizeof(number4Data));
	memcpy((u16*)0x06014900, &number5Data, 	sizeof(number5Data));
	memcpy((u16*)0x06014a00, &number6Data, 	sizeof(number6Data));
	memcpy((u16*)0x06014b00, &number7Data, 	sizeof(number7Data));
	memcpy((u16*)0x06014c00, &number8Data, 	sizeof(number8Data));
	memcpy((u16*)0x06014d00, &number9Data, 	sizeof(number9Data));
	*/
	

	// Create the sprite for the ball.
	sprites[0].attribute0 = COLOR_256 | SQUARE | yball;
	sprites[0].attribute1 = SIZE_8 | xball;
	sprites[0].attribute2 = 512;

	// Create the sprite for the player paddle.
	sprites[1].attribute0 = COLOR_256 | TALL | ybar;
	sprites[1].attribute1 = SIZE_16 | xbar;
	sprites[1].attribute2 = 512 + 8;

	// Create the sprite for the AI paddle.
	sprites[2].attribute0 = COLOR_256 | TALL | yai;
	sprites[2].attribute1 = SIZE_16 | xai;
	sprites[2].attribute2 = 512 + 8;

	// Create the sprite for the crack.
	sprites[3].attribute0 = COLOR_256 | SQUARE | 160;
	sprites[3].attribute1 = SIZE_8 | 240;
	sprites[3].attribute2 = 512 + 24;

	// Create the sprite for the player score.
	sprites[4].attribute0 = COLOR_256 | SQUARE | 0;
	sprites[4].attribute1 = SIZE_8 | 36;
	sprites[4].attribute2 = 512 + 32;

	// Create the sprite for the AI score.
	sprites[5].attribute0 = COLOR_256 | SQUARE | 0;
	sprites[5].attribute1 = SIZE_8 | 196;
	sprites[5].attribute2 = 512 + 32;

	// Create a test sprite for the Fire sprite.
	sprites[6].attribute0 = COLOR_256 | SQUARE | 80;
	sprites[6].attribute1 = SIZE_16 | 80;
	sprites[6].attribute2 = 512 + 8;

	u16 value;

	value = 0;
	// Start the game loop.
	while(1)
	{
		//specialcpy((u16*)0x06014100, &testDataOld, sizeof(testDataOld), value / 15);
		//++value;

		MoveBall();
		MoveBar();
		MoveAI();
		MoveSprite(&sprites[0], xball, yball);
		MoveSprite(&sprites[1], xbar, ybar);
		MoveSprite(&sprites[2], xai, yai);
		MoveSprite(&sprites[6], 80, 80);
		WaitForVsync();
		CopyOAM();
	}

	return 0;
}

// Move all sprites to (240, 160) so they are hidden at start.
void InitialiseSprites(void)
{
	u16 loop;

	for(loop = 0; loop < 128; ++loop)
	{
		//hideSprite(loop);

		sprites[loop].attribute0 = 160;
		sprites[loop].attribute1 = 240;
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

// Move a sprite to (240, 160);
void hideSprite(int spriteID)
{
	MoveSprite(&sprites[spriteID], 240, 160);
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

/*
// Display the chosen item in the relevant position.
void displayItem(int position, ItemName item)
{
	// Check if item is unlocked. If so, place its sprite.

	// If not, select the empty sprite.
}
// Display text for the current item.
void setItemText(ItemName item)
{

}

// Display the results box?
void drawResultBox(int visible)
{

}

// Set the category of items to display to the player.
void chooseCategory(CategoryName category)
{

}

// The user picks an item to try crafting.
void userChooseItem(ItemName item)
{
	// Do something to pick the item currently hovered.

	// Check if both items are picked.
}

// The crafting was unsuccessful.
void invalidCraft(void)
{

}

// The crafting was successful so we can display a result.
void validCraft(ItemName result)
{

}
*/

// Move the ball sprite.
void MoveBall(void)
{
	if(ballDir == 0)
	{
		if(xball >= xMax)
		{
			ballDir = 5;
		}
		else if(yball >= yMax)
		{
			ballDir = 1;
		}
		else if(xball >= xai - 6 && yball >= yai && yball <= yai + 32)
		{
			ballDir = 3;
		}
		else
		{
			xball += xspeed;
			yball += yspeed;
		}
	}
	
	if(ballDir == 1)
	{
		if(xball >= xMax)
		{
			ballDir = 5;
		}
		else if(yball <= yMin)
		{
			ballDir = 0;
		}
		else if(xball >= xai - 6 && yball >= yai && yball <= yai + 32)
		{
			ballDir = 2;
		}
		else
		{
			xball += xspeed;
			yball -= yspeed;
		}
	}
	
	if(ballDir == 2)
	{
		if(xball <= xMin)
		{
			ballDir = 4;
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
			xball -= xspeed;
			yball -= yspeed;
		}
	}
	
	if(ballDir == 3)
	{
		if(xball <= xMin)
		{
			ballDir = 4;
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
			xball -= xspeed;
			yball += yspeed;
		}
	}

	if(ballDir == 4)
	{
		if(++aiScore == 10)
		{
			aiScore = 0;
		}

		sprites[5].attribute2 = 512 + 32 + (aiScore * 8);

		sprites[3].attribute0 = COLOR_256 | SQUARE | yball;
		sprites[3].attribute1 = SIZE_8 | 0;

		ballDir = 6;
	}
	else if(ballDir == 5)
	{
		if(++playerScore == 10)
		{
			playerScore = 0;
		}

		sprites[4].attribute2 = 512 + 32 + ((playerScore % 10) * 8);

		sprites[3].attribute0 = COLOR_256 | SQUARE | yball;
		sprites[3].attribute1 = SIZE_8 | 232;

		ballDir = 7;
	}
}

// Move the bar sprite.
void MoveBar(void)
{
	if(ballDir == 6 || ballDir == 7)
	{
		if(keyDown(KEY_A))
		{
			if(ballDir == 6)
			{
				ballDir = 0;	
			}
			else if(ballDir = 7)
			{
				ballDir = 3;
			}
			
			sprites[3].attribute0 = COLOR_256 | SQUARE | 160;
			sprites[3].attribute1 = SIZE_8 | 240;
		}
	}
	else
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
	
	
}

void MoveAI(void)
{
	if(xball > (88 + rand() % 8))
	{
		if(yai + 12 < yball && yai && yai < yMax - 24)
		{
			yai += 3;
		}
		else if(yai > yball && yai)
		{
			yai -= 3;
		}
	}
}
