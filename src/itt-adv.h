// Separate function definitions from itt-adv.c.

#ifndef ITT_ADV_H
#define ITT_ADV_H

//#include "category.h"
#include "item.h"

// Sprite manipulation.
void initialiseGame(void);
void initialiseSprites(void);
void moveSprite(OAMEntry* sp, u8 x, u8 y);
void showSprite(u8 spriteID);
void hideSprite(u8 spriteID);

// Memory manipulation.
void copyOAM(void);

// Sprite display functions.
void displayItem(u8 spriteID, u16 itemID);
void setText(const char* text);
void setProgress(u16 newUnlocks);
void setChar(u8 textID, char newChar);

// Menu navigation functions.
void chooseCategory(u8 categoryID);
void returnToCategories();

// Crafting functions.
void userChooseItem(u16 itemID);
void invalidCraft(void);
void validCraft(u16 itemID);

// Progress functions.
void unlockItem(u16 itemID);

#endif
