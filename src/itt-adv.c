// Where the action happens.

#include "gba/gba.h"
#include "itt-adv.h"

// Include sprites.
#include "sprite/font.h"
#include "sprite/cursor.h"

#include "recipe.h"
#include "item.h"
#include "category.h"

#include "sprite_obj.h"
#include "state.h"

OAMEntry sprites[128];

// Program state variables.
u8 unlocked[261];
u16 unlockedCount = 0;

State programState = CategorySelect;

u8 cursor_pos = 0;

CategoryName activeCategory = 0;
u8 items_chosen = 0;

const u8 frame_delay = 10;
u8 frame_count = 0;

u16 itemA = 0;
u16 itemB = 0;

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

	// Initialise item slot sprites.
	for(loop = 0; loop < 23; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_16 | 0;
		sprites[loop].attribute2 = 512 + loop * 8;
	}

	// Initialise item name text slot sprites.
	for(loop = 23; loop < 45; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_8 | 0;
		sprites[loop].attribute2 = sprites[22].attribute2 + (loop - 22) * 8;
	}

	// Initialise progress text slot sprites.
	for(loop = 45; loop < 52; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_8 | 0;
		sprites[loop].attribute2 = sprites[43].attribute2 + (loop - 43) * 8;
	}

	// Initialise chosen item sprites.
	for(loop = 52; loop < 54; ++loop)
	{
		sprites[loop].attribute0 = COLOR_256 | SQUARE | 0;
		sprites[loop].attribute1 = SIZE_16 | 0;
		sprites[loop].attribute2 = sprites[51].attribute2 + (loop - 51) * 8;
	}

	// Initialise cursor sprite.
	sprites[54].attribute0 = COLOR_256 | WIDE | 0;
	sprites[54].attribute1 = SIZE_16 | 0;
	sprites[54].attribute2 = sprites[53].attribute2 + 8;

	// Put the cursor sprite in the correct memory location.
	memcpy((u16*)0x06017500, &tx_CursorData, sizeof(tx_CursorData));

	initialiseSprites();
	initialiseGame();

	// Start the game loop.
	while(1)
	{
		if(frame_count == 0)
		{
			update();
		}
		else
		{
			--frame_count;
		}

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

	setProgress(4);
	setState(CategorySelect);
}

// Move all sprites to their starting positions.
void initialiseSprites(void)
{
	u16 loop;

	for(loop = 0; loop < 128; ++loop)
	{
		if(loop < 55)
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

// Run this function once per frame.
void update(void)
{
	switch(programState)
	{
		// We may pick a category.
		case CategorySelect:
			moveCursor();
			if(keyDown(KEY_A))
			{
				activeCategory = cursor_pos;
				chooseCategory();
				frame_count = frame_delay;
			}
			break;
		// We may pick an item.
		case ItemSelect:
			moveCursor();
			if(keyDown(KEY_A))
			{
				chooseItem(categoryData[activeCategory].items[cursor_pos]);
				frame_count = frame_delay;

			}
			else if(keyDown(KEY_B))
			{
				setState(CategorySelect);
				frame_count = frame_delay;
			}
			break;
		// We may return to the Category screen.
		case ValidCraft:
			if(keyDown(KEY_A))
			{
				showSprite(54);
				setState(CategorySelect);
				frame_count = frame_delay;
			}
			break;
		// We may return to the Category screen.
		case InvalidCraft:
			if(keyDown(KEY_A))
			{
				setState(CategorySelect);
				frame_count = frame_delay;
			}
			break;
	}
}

// Poll for inputs to move the cursor.
void moveCursor(void)
{
	u8 old_pos = cursor_pos;

	u8 max_pos = 0;

	if(programState == CategorySelect)
	{
		max_pos = 23;
	}
	else if(programState == ItemSelect)
	{
		max_pos = categoryData[activeCategory + 1].itemCount;
	}

	if(keyDown(KEY_LEFT) && cursor_pos > 0)
	{
		cursor_pos--;
	}
	else if(keyDown(KEY_RIGHT))
	{
		cursor_pos++;
	}
	else if(keyDown(KEY_UP) && cursor_pos >= 9)
	{
		cursor_pos -= 9;
	}
	else if(keyDown(KEY_DOWN))
	{
		cursor_pos += 9;
	}

	if(cursor_pos >= max_pos)
	{
		cursor_pos = max_pos - 1;
	}

	// If the cursor has changed position, place it in the new position.
	if(old_pos != cursor_pos)
	{
		setCursorPos();
		frame_count = frame_delay;
	}
}

// Place the cursor at a sprite position.
void setCursorPos(void)
{
	u8 x = sprite_data[cursor_pos].startPosX;
	u8 y = sprite_data[cursor_pos].startPosY + 16;

	moveSprite(&sprites[53], x, y);
}

// Set the program state.
void setState(State state)
{
	programState = state;

	switch(state)
	{
		case CategorySelect:
			setCategoryView();
			break;
		case ItemSelect:
			cursor_pos = 0;
			setCursorPos();
			break;
	}
}

// Choose the text which should appear.
void setCursorText(void)
{
	if(programState == CategorySelect)
	{

	}
	else if(programState == ItemSelect)
	{

	}
}

// Display the chosen item in the relevant position.
void displayItem(u8 spriteID, u16 itemID, u8 ignoreUnlocked)
{
	// If the itemID is invalid, do not place a sprite.
	if(itemID <= 261)
	{
		showSprite(spriteID);

		// Check if item is unlocked. If so, place its sprite.
		if(unlocked[itemID] || ignoreUnlocked)
		{
			memcpy((u16*)(0x06014000 + 0x100 * spriteID), itemData[itemID].itemSprite, itemSpriteSize);
		}
		// If not, select the empty sprite.
		else
		{
 			memcpy((u16*)(0x06014000 + 0x100 * spriteID), tx_LockedData, itemSpriteSize);
		}
	}
	else
	{
		hideSprite(spriteID);
	}
}

// Display text for the current item.
void setText(const char *text)
{
	int len = strlen(text);

	u8 index;
	for(index = 0; index < 22; ++index)
	{
		if(index < len)
		{
			setChar(index, text[index]);
		}
		else
		{
			hideSprite(22 + index);
		}
	}
}

// Update the progress bar text.
void setProgress(u16 newUnlocks)
{
	unlockedCount += newUnlocks;

	// Exploit integer division.
	u8 hundreds = unlockedCount / 100;
	u8 tens = unlockedCount / 10 - hundreds * 10;
	u8 units = unlockedCount - tens * 10 - hundreds * 100;

	char progressString[8];

	// Exploit int<->char equivalence.
	progressString[0] = hundreds + '0';
	progressString[1] = tens + '0';
	progressString[2] = units + '0';
	progressString[3] = '/';
	progressString[4] = '2';
	progressString[5] = '6';
	progressString[6] = '0';
	progressString[7] = '\0';

	// It's all just exploits all the way down.

	u8 index;

	for(index = 0; index < 7; ++index)
	{
		setChar(22 + index, progressString[index]);
	}
}

// Set the character shown by a specific character spot.
void setChar(u8 textID, char newChar)
{
	showSprite(22 + textID);

	switch(newChar)
	{
		case ' ':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_TextSpaceData, sizeof(tx_TextSpaceData));
			break;
		case '\'':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_ApostropheData, sizeof(tx_ApostropheData));
			break;
		case '/':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_FSlashData, sizeof(tx_FSlashData));
			break;
		case 'A':
		case 'a':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_AData, sizeof(tx_AData));
			break;
		case 'B':
		case 'b':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_BData, sizeof(tx_BData));
			break;
		case 'C':
		case 'c':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_CData, sizeof(tx_CData));
			break;
		case 'D':
		case 'd':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_DData, sizeof(tx_DData));
			break;
		case 'E':
		case 'e':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_EData, sizeof(tx_EData));
			break;
		case 'F':
		case 'f':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_FData, sizeof(tx_FData));
			break;
		case 'G':
		case 'g':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_GData, sizeof(tx_GData));
			break;
		case 'H':
		case 'h':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_HData, sizeof(tx_HData));
			break;
		case 'I':
		case 'i':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_IData, sizeof(tx_IData));
			break;
		case 'J':
		case 'j':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_JData, sizeof(tx_JData));
			break;
		case 'K':
		case 'k':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_KData, sizeof(tx_KData));
			break;
		case 'L':
		case 'l':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_LData, sizeof(tx_LData));
			break;
		case 'M':
		case 'm':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_MData, sizeof(tx_MData));
			break;
		case 'N':
		case 'n':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_NData, sizeof(tx_NData));
			break;
		case 'O':
		case 'o':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_OData, sizeof(tx_OData));
			break;
		case 'P':
		case 'p':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_PData, sizeof(tx_PData));
			break;
		case 'Q':
		case 'q':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_QData, sizeof(tx_QData));
			break;
		case 'R':
		case 'r':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_RData, sizeof(tx_RData));
			break;
		case 'S':
		case 's':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_SData, sizeof(tx_SData));
			break;
		case 'T':
		case 't':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_TData, sizeof(tx_TData));
			break;
		case 'U':
		case 'u':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_UData, sizeof(tx_UData));
			break;
		case 'V':
		case 'v':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_VData, sizeof(tx_VData));
			break;
		case 'W':
		case 'w':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_WData, sizeof(tx_WData));
			break;
		case 'X':
		case 'x':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_XData, sizeof(tx_XData));
			break;
		case 'Y':
		case 'y':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_YData, sizeof(tx_YData));
			break;
		case 'Z':
		case 'z':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_ZData, sizeof(tx_ZData));
			break;
		case '0':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_0Data, sizeof(tx_0Data));
			break;
		case '1':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_1Data, sizeof(tx_1Data));
			break;
		case '2':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_2Data, sizeof(tx_2Data));
			break;
		case '3':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_3Data, sizeof(tx_3Data));
			break;
		case '4':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_4Data, sizeof(tx_4Data));
			break;
		case '5':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_5Data, sizeof(tx_5Data));
			break;
		case '6':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_6Data, sizeof(tx_6Data));
			break;
		case '7':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_7Data, sizeof(tx_7Data));
			break;
		case '8':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_8Data, sizeof(tx_8Data));
			break;
		case '9':
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_9Data, sizeof(tx_9Data));
			break;
		default:
			memcpy((u16*)(0x06015700 + 0x100 * textID), &tx_0Data, sizeof(tx_0Data));
	}
}

// Set the game to the category select.
void setCategoryView(void)
{
	u8 index;

	for(index = 1; index < 24; ++index)
	{
		displayItem(index - 1, categoryData[index].headItem, 1);
	}

	cursor_pos = activeCategory;
	setCursorPos();
}

// Set the category of items to display to the player.
void chooseCategory(void)
{
	u8 index;

	for(index = 0; index < 22; ++index)
	{
		if(categoryData[activeCategory + 1].items[index] != 0)
		{
			displayItem(index, categoryData[activeCategory + 1].items[index], 0);
		}
		else
		{
			hideSprite(index);
		}
	}

	hideSprite(22);

	setState(ItemSelect);
}

// The user picks an item to try crafting.
void chooseItem(u16 itemID)
{
	// Do something to pick the item currently hovered.
	if(items_chosen == 0)
	{
		// Set the first item.
		itemA = categoryData[activeCategory + 1].items[cursor_pos];
		items_chosen = 1;
	}
	else if(items_chosen == 1)
	{
		// Set the second item.
		itemB = categoryData[activeCategory + 1].items[cursor_pos];

		// When both items are picked, attempt to craft them.
		attemptCraft();
	}
}

// Try to craft both items together.
void attemptCraft(void)
{
	items_chosen = 0;

	ItemName craftedItems[5];
	u8 craftCount = 0;

	u16 loop;

	// Loop through all 311 recipes.
	for(loop = 0; loop < 311; ++loop)
	{
		ItemName result = None;

		if(recipes[loop].itemA == itemA)
		{
			if(recipes[loop].itemB == itemB)
			{
				result = recipes[loop].result;
			}
		}
		else if(recipes[loop].itemB == itemA)
		{
			if(recipes[loop].itemA == itemB)
			{
				result = recipes[loop].result;
			}
		}

		if(result != None)
		{
			craftedItems[craftCount++] = result;
		}
	}

	if(craftCount == 0)
	{
		invalidCraft();
	}
	else
	{
		validCraft(craftedItems, craftCount);
	}
}

// The crafting was unsuccessful.
void invalidCraft(void)
{
	setState(InvalidCraft);
}

// The crafting was successful so we can display a result.
void validCraft(ItemName *craftedItems, u8 craftCount)
{
	setState(ValidCraft);
	hideSprite(54);

	u8 loop;

	for(loop = 0; loop < 23; ++loop)
	{
		if(loop < craftCount)
		{
			displayItem(loop, craftedItems[loop], 1);

			if(unlocked[craftedItems[loop]] == 0)
			{
				unlocked[craftedItems[loop]] = 1;
				setProgress(1);
			}
		}
		else
		{
			hideSprite(loop);
		}	
	}
}
