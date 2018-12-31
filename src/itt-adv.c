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

#include "data/item.h"
#include "data/recipe.h"

#include "sprite/item_sprites.h"

OAMEntry sprites[128];

// Application entry point.
int main()
{
	initialiseSprites();

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
	memcpy((u16*)0x06014000, &ballData, 	sizeof(ballData));

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

	// Create the sprite for the ball.
	sprites[0].attribute0 = COLOR_256 | SQUARE | 0;
	sprites[0].attribute1 = SIZE_8 | 0;
	sprites[0].attribute2 = 512;

	// Create the sprite for the player paddle.
	sprites[1].attribute0 = COLOR_256 | TALL | 0;
	sprites[1].attribute1 = SIZE_16 | 0;
	sprites[1].attribute2 = 512 + 8;

	// Create the sprite for the AI paddle.
	sprites[2].attribute0 = COLOR_256 | TALL | 0;
	sprites[2].attribute1 = SIZE_16 | 0;
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

	// Start the game loop.
	while(1)
	{
		moveSprite(&sprites[0], 0, 0);
		moveSprite(&sprites[1], 0, 0);
		moveSprite(&sprites[2], 0, 0);
		WaitForVsync();
		copyOAM();
	}

	return 0;
}

// Move all sprites to (240, 160) so they are hidden at start.
void initialiseSprites(void)
{
	u16 loop;

	for(loop = 0; loop < 128; ++loop)
	{
		hideSprite(loop);
	}
}

// Move a sprite by an amount.
void moveSprite(OAMEntry* sp, int x, int y)
{
	sp->attribute1 = sp->attribute1 & 0xFE00;
	sp->attribute1 = sp->attribute1 | x;

	sp->attribute0 = sp->attribute0 & 0xFF00;
	sp->attribute0 = sp->attribute0 | y;
}

// Move a sprite to (240, 160);
void hideSprite(int spriteID)
{
	moveSprite(&sprites[spriteID], 240, 160);
}

// Copy data for each sprite to OAM memory.
void copyOAM(void)
{
	u16 loop;
	u16* temp;
	temp = (u16*)sprites;

	for(loop = 0; loop < 128 * 4; ++loop)
	{
		OAM_Mem[loop] = temp[loop];
	}
}

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
