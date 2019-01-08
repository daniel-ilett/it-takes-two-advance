// Separate function definitions from itt-adv.c.

#ifndef ITT_ADV_H
#define ITT_ADV_H

#include "category.h"
#include "item.h"

// Sprite manipulation.
void initialiseSprites(void);
void moveSprite(OAMEntry* sp, int x, int y);
void hideSprite(int spriteID);

// Memory manipulation.
void copyOAM(void);

// Sprite display functions.
void displayItem(int position, ItemName item);
void setItemText(ItemName item);
void drawResultBox(int visible);

// Menu navigation functions.
void chooseCategory(CategoryName category);
void returnToCategories();

// Crafting functions.
void userChooseItem(ItemName item);
void invalidCraft(void);
void validCraft(ItemName result);

// Progress functions.
void unlockItem(ItemName itemName);

#endif
