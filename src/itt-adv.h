// Separate function definitions from itt-adv.c.

#ifndef ITT_ADV_H
#define ITT_ADV_H

#include "state.h"
#include "item.h"

// Sprite manipulation.
void initialiseGame(void);
void initialiseSprites(void);
void moveSprite(OAMEntry* sp, u8 x, u8 y);
void showSprite(u8 spriteID);
void hideSprite(u8 spriteID);

// Memory manipulation.
void copyOAM(void);

// Game parameters.
void update(void);
void moveCursor(void);
void setCursorPos(void);
void setState(State state);

// Sprite display functions.
void displayItem(u8 spriteID, u16 itemID, u8 ignoreUnlocked);
void setText(const char* text);
void setProgress(u16 newUnlocks);
void setChar(u8 textID, char newChar);

// Menu navigation functions.
void setCategoryView(void);
void chooseCategory(void);

// Crafting functions.
void chooseItem(u16 itemID);
void attemptCraft(void);
void invalidCraft(void);
void validCraft(ItemName *craftedItems, u8 craftCount);

// Progress functions.
void unlockItem(u16 itemID);

#endif
