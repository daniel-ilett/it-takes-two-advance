// Separate function definitions from pong.c.
#ifndef PONG_H
#define PONG_H

#include "items.h"

void InitialiseSprites(void);
void CopyOAM(void);
void MoveSprite(OAMEntry* sp, int x, int y);

void MoveBall(void);
void MoveBar(void);
void MoveAI(void);

// Sprite display functions.
void displayItem(int position, ItemName item);
void setItemText(ItemName item);
void drawResultBox(int visible);

// Menu navigation functions.
//void chooseCategory(CategoryName category);

// Crafting functions.
void userChooseItem(ItemName item);
void invalidCraft(void);
void validCraft(ItemName result);

#endif
