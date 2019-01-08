// Where the action happens.

#include "gba/gba.h"
#include "itt-adv.h"

// Include sprites.
#include "sprite/numbers.h"
//#include "sprite/item_sprites.h"

//#include "recipe.h"
#include "item.h"

#include "sprite_obj.h"
#include "state.h"

OAMEntry sprites[128];

u8 unlocked[261];

State program_state = CategorySelect;

SpriteObj sprite_data[] = 
{
	// Row 1 of item palette. (x9)
	{ .startPosX = 16, 	.startPosY = 80 },
	{ .startPosX = 40, 	.startPosY = 80 },
	{ .startPosX = 64, 	.startPosY = 80 },
	{ .startPosX = 88, 	.startPosY = 80 },
	{ .startPosX = 112, .startPosY = 80 },
	{ .startPosX = 136, .startPosY = 80 },
	{ .startPosX = 160, .startPosY = 80 },
	{ .startPosX = 184, .startPosY = 80 },
	{ .startPosX = 208, .startPosY = 80 },

	// Row 2 of item palette. (x9)
	{ .startPosX = 16, 	.startPosY = 108 },
	{ .startPosX = 40, 	.startPosY = 108 },
	{ .startPosX = 64, 	.startPosY = 108 },
	{ .startPosX = 88, 	.startPosY = 108 },
	{ .startPosX = 112, .startPosY = 108 },
	{ .startPosX = 136, .startPosY = 108 },
	{ .startPosX = 160, .startPosY = 108 },
	{ .startPosX = 184, .startPosY = 108 },
	{ .startPosX = 208, .startPosY = 108 },

	// Row 3 of item palette. (x4)
	{ .startPosX = 76, 	.startPosY = 132 },
	{ .startPosX = 100, .startPosY = 132 },
	{ .startPosX = 124, .startPosY = 132 },
	{ .startPosX = 148, .startPosY = 132 },

	// Text slots. (x22)
	{ .startPosX = 32, 	.startPosY = 56  },
	{ .startPosX = 40, 	.startPosY = 56  },
	{ .startPosX = 48, 	.startPosY = 56  },
	{ .startPosX = 56, 	.startPosY = 56  },
	{ .startPosX = 64, 	.startPosY = 56  },
	{ .startPosX = 72, 	.startPosY = 56  },
	{ .startPosX = 80, 	.startPosY = 56  },
	{ .startPosX = 88, 	.startPosY = 56  },
	{ .startPosX = 96, 	.startPosY = 56  },
	{ .startPosX = 104, .startPosY = 56  },
	{ .startPosX = 112, .startPosY = 56  },
	{ .startPosX = 120, .startPosY = 56  },
	{ .startPosX = 128, .startPosY = 56  },
	{ .startPosX = 136, .startPosY = 56  },
	{ .startPosX = 144, .startPosY = 56  },
	{ .startPosX = 152, .startPosY = 56  },
	{ .startPosX = 160, .startPosY = 56  },
	{ .startPosX = 168, .startPosY = 56  },
	{ .startPosX = 176, .startPosY = 56  },
	{ .startPosX = 184, .startPosY = 56  },
	{ .startPosX = 192, .startPosY = 56  },
	{ .startPosX = 200, .startPosY = 56  },

	// Progress text slots. (x7)
	{ .startPosX = 176, .startPosY = 8   },
	{ .startPosX = 184, .startPosY = 8   },
	{ .startPosX = 192, .startPosY = 8   },
	{ .startPosX = 200, .startPosY = 8   },
	{ .startPosX = 208, .startPosY = 8   },
	{ .startPosX = 216, .startPosY = 8   },
	{ .startPosX = 224, .startPosY = 8   },

	// Picked item sprites. (x2)
	{ .startPosX = 100, .startPosY = 24  },
	{ .startPosX = 124, .startPosY = 24  },

	// Cursor slot. (x1)
	{ .startPosX = 16, 	.startPosY = 96  },
};

// Application entry point.
int main()
{
	u16 loop;

	SetMode(MODE_4 | BG2_ENABLE | OBJ_ENABLE | OBJ_MAP_1D);

	// Transfer the item palette into palette memory.
	for(loop = 0; loop < 256; ++loop)
	{
		OBJ_PaletteMem[loop] = BG_PaletteMem[loop] = itemPalette[loop];
	}

	// Transfer background pixel data into VRAM.
	// 0x3838 represents full-white.
	for(loop = 0; loop < (120 * 160); ++loop)
	{
		FrontBuffer[loop] = 0x3838;
	}

	// Copy the ball pixel data to the first location in sprite data.
	//memcpy((u16*)0x06014000, &tx_LockedData, sizeof(tx_LockedData));
	memcpy((u16*)0x06014000, itemData[0].itemSprite, itemSpriteSize);
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

	// Initialise item slot sprites.
	for(loop = 0; loop < 22; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_16 | 0;
		sprites[loop].attribute2 = 512 + loop * 8;
	}

	// Initialise item name text slot sprites.
	for(loop = 22; loop < 44; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_8 | 0;
		sprites[loop].attribute2 = sprites[21].attribute2 + (loop - 21) * 8;
	}

	// Initialise progress text slot sprites.
	for(loop = 44; loop < 51; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_8 | 0;
		sprites[loop].attribute2 = sprites[43].attribute2 + (loop - 43) * 8;
	}

	// Initialise chosen item sprites.
	for(loop = 51; loop < 53; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_16 | 0;
		sprites[loop].attribute2 = sprites[50].attribute2 + (loop - 50) * 8;
	}

	// Initialise cursor sprite.
	sprites[53].attribute0 = COLOR_256 | WIDE | 0;
	sprites[53].attribute1 = SIZE_16 | 0;
	sprites[53].attribute2 = sprites[52].attribute2 + 8;

	initialiseGame();
	initialiseSprites();

	for(loop = 0; loop < 22; ++loop)
	{
		displayItem(loop, loop);
	}

	// Start the game loop.
	while(1)
	{
		WaitForVsync();
		copyOAM();
	}

	return 0;
}

// Set the start state of all game elements.
void initialiseGame(void)
{
	u16 loop;

	// Lock all items.
	for(loop = 0; loop < 261; ++loop)
	{
		unlocked[loop] = 0;
	}

	// Then unlock Air, Earth, Fire and Water.
	for(loop = 1; loop < 5; ++loop)
	{
		unlocked[loop] = 1;
	}
}

// Move all sprites to their starting positions.
void initialiseSprites(void)
{
	u16 loop;

	for(loop = 0; loop < 128; ++loop)
	{
		if(loop < 54)
		{
			moveSprite(&sprites[loop], sprite_data[loop].startPosX, sprite_data[loop].startPosY);
		}
		else
		{
			hideSprite(loop);
		}
	}
}

// Move a sprite by an amount.
void moveSprite(OAMEntry* sp, u8 x, u8 y)
{
	sp->attribute1 = sp->attribute1 & 0xFE00;
	sp->attribute1 = sp->attribute1 | x;

	sp->attribute0 = sp->attribute0 & 0xFF00;
	sp->attribute0 = sp->attribute0 | y;
}

// Move a sprite to its default position.
void showSprite(u8 spriteID)
{
	moveSprite(&sprites[spriteID], sprite_data[spriteID].startPosX, sprite_data[spriteID].startPosY);
}

// Move a sprite to (240, 160);
void hideSprite(u8 spriteID)
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
void displayItem(u8 spriteID, u16 itemID)
{
	// If the itemID is -1, do not place a sprite.
	if(itemID <= 261)
	{
		showSprite(spriteID);

		// Check if item is unlocked. If so, place its sprite.
		if(unlocked[itemID])
		{
			memcpy((u16*)(0x06014000 + 0x100 * itemID), itemData[itemID].itemSprite, itemSpriteSize);
		}
		// If not, select the empty sprite.
		else
		{
 			memcpy((u16*)(0x06014000 + 0x100 * itemID), tx_LockedData, itemSpriteSize);
		}
	}
	else
	{
		hideSprite(spriteID);
	}
}

// Display text for the current item.
void setText(char* text)
{

}

// Set the category of items to display to the player.
void chooseCategory(u8 categoryID)
{

}

// The user picks an item to try crafting.
void userChooseItem(u16 itemID)
{
	// Do something to pick the item currently hovered.

	// Check if both items are picked.
}

// The crafting was unsuccessful.
void invalidCraft(void)
{

}

// The crafting was successful so we can display a result.
void validCraft(u16 itemResult)
{

}
