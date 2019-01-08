// Separate function definitions from itt-adv.c.

#ifndef ITT_ADV_H
#define ITT_ADV_H

//#include "category.h"
#include "item.h"

// Sprite manipulation.
void initialiseSprites(void);
void moveSprite(OAMEntry* sp, int x, int y);
void hideSprite(int spriteID);

// Memory manipulation.
void copyOAM(void);

// Sprite display functions.
void displayItem(int position, u16 itemID);
void setItemText(u16 itemID);
void drawResultBox(int visible);

// Menu navigation functions.
void chooseCategory(u16 categoryID);
void returnToCategories();

// Crafting functions.
void userChooseItem(u16 itemID);
void invalidCraft(void);
void validCraft(u16 itemID);

// Progress functions.
void unlockItem(u16 itemID);

#endif
