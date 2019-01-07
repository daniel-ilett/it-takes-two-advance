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

//#include "data/item.h"
//#include "data/recipe.h"

#include "sprite_obj.h"

OAMEntry sprites[128];

SpriteObj sprite_data[] = 
{
	// Row 1 of item palette.
	{ .posX = 0, 	.posY = 0, 	.startPosX = 16, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 40, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 64, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 88, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 112, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 136, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 160, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 184, 	.startPosY = 80 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 208, 	.startPosY = 80 },

	// Row 2 of item palette.
	{ .posX = 0, 	.posY = 0, 	.startPosX = 16, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 40, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 64, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 88, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 112, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 136, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 160, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 184, 	.startPosY = 108 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 208, 	.startPosY = 108 },

	// Row 3 of item palette.
	{ .posX = 0, 	.posY = 0, 	.startPosX = 76, 	.startPosY = 132 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 100, 	.startPosY = 132 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 124, 	.startPosY = 132 },
	{ .posX = 0, 	.posY = 0, 	.startPosX = 148, 	.startPosY = 132 },
};

// Application entry point.
int main()
{
	initialiseSprites();

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
	memcpy((u16*)0x06014000, &tx_EarthData, sizeof(tx_EarthData));
	memcpy((u16*)0x06014100, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014200, &tx_WaterData, sizeof(tx_WaterData));
	memcpy((u16*)0x06014300, &tx_OreData, sizeof(tx_OreData));
	memcpy((u16*)0x06014400, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014500, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014600, &tx_VampireData, sizeof(tx_VampireData));
	memcpy((u16*)0x06014700, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014800, &tx_FireData, sizeof(tx_FireData));

	memcpy((u16*)0x06014900, &tx_BirdData, sizeof(tx_BirdData));
	memcpy((u16*)0x06014a00, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014b00, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014c00, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014d00, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014e00, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06014f00, &tx_ZombieData, sizeof(tx_ZombieData));
	memcpy((u16*)0x06015000, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06015100, &tx_AlcoholData, sizeof(tx_AlcoholData));

	memcpy((u16*)0x06015200, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06015300, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06015400, &tx_FireData, sizeof(tx_FireData));
	memcpy((u16*)0x06015500, &tx_FireData, sizeof(tx_FireData));

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

	// First row of item tray sprites.
	sprites[0].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[0].attribute1 = SIZE_16 | 2 * 8;
	sprites[0].attribute2 = 512;

	sprites[1].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[1].attribute1 = SIZE_16 | 5 * 8;
	sprites[1].attribute2 = 512 + 8;

	sprites[2].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[2].attribute1 = SIZE_16 | 8 * 8;
	sprites[2].attribute2 = 512 + 8 * 2;

	sprites[3].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[3].attribute1 = SIZE_16 | 11 * 8;
	sprites[3].attribute2 = 512 + 8 * 3;

	sprites[4].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[4].attribute1 = SIZE_16 | 14 * 8;
	sprites[4].attribute2 = 512 + 8 * 4;

	sprites[5].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[5].attribute1 = SIZE_16 | 17 * 8;
	sprites[5].attribute2 = 512 + 8 * 5;

	sprites[6].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[6].attribute1 = SIZE_16 | 20 * 8;
	sprites[6].attribute2 = 512 + 8 * 6;

	sprites[7].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[7].attribute1 = SIZE_16 | 23 * 8;
	sprites[7].attribute2 = 512 + 8 * 7;

	sprites[8].attribute0 = COLOR_256 | SQUARE | 10 * 8;
	sprites[8].attribute1 = SIZE_16 | 26 * 8;
	sprites[8].attribute2 = 512 + 8 * 8;

	// Second row of item tray sprites.
	sprites[9].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[9].attribute1 = SIZE_16 | 2 * 8;
	sprites[9].attribute2 = 512 + 8 * 9;

	sprites[10].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[10].attribute1 = SIZE_16 | 5 * 8;
	sprites[10].attribute2 = 512 + 8 * 10;

	sprites[11].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[11].attribute1 = SIZE_16 | 8 * 8;
	sprites[11].attribute2 = 512 + 8 * 11;

	sprites[12].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[12].attribute1 = SIZE_16 | 11 * 8;
	sprites[12].attribute2 = 512 + 8 * 12;

	sprites[13].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[13].attribute1 = SIZE_16 | 14 * 8;
	sprites[13].attribute2 = 512 + 8 * 13;

	sprites[14].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[14].attribute1 = SIZE_16 | 17 * 8;
	sprites[14].attribute2 = 512 + 8 * 14;

	sprites[15].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[15].attribute1 = SIZE_16 | 20 * 8;
	sprites[15].attribute2 = 512 + 8 * 15;

	sprites[16].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[16].attribute1 = SIZE_16 | 23 * 8;
	sprites[16].attribute2 = 512 + 8 * 16;

	sprites[17].attribute0 = COLOR_256 | SQUARE | 13 * 8;
	sprites[17].attribute1 = SIZE_16 | 26 * 8;
	sprites[17].attribute2 = 512 + 8 * 17;

	// Third row of item tray sprites.
	sprites[18].attribute0 = COLOR_256 | SQUARE | 16 * 8;
	sprites[18].attribute1 = SIZE_16 | 76;
	sprites[18].attribute2 = 512 + 8 * 18;

	sprites[19].attribute0 = COLOR_256 | SQUARE | 16 * 8;
	sprites[19].attribute1 = SIZE_16 | 100;
	sprites[19].attribute2 = 512 + 8 * 19;

	sprites[20].attribute0 = COLOR_256 | SQUARE | 16 * 8;
	sprites[20].attribute1 = SIZE_16 | 124;
	sprites[20].attribute2 = 512 + 8 * 20;

	sprites[21].attribute0 = COLOR_256 | SQUARE | 16 * 8;
	sprites[21].attribute1 = SIZE_16 | 148;
	sprites[21].attribute2 = 512 + 8 * 21;

	// Start the game loop.
	while(1)
	{
		//MoveSprite(&sprites[0], 80, 80);
		//MoveSprite(&sprites[1], 100, 80);

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
