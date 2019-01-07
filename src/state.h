// Enumerate the states the program can be in.

#ifndef STATE_H
#define STATE_H

typedef enum State
{
	CategorySelect,	// We are selecting a category.
	ItemSelect,		// We are selecting an item inside a category.
	ValidCraft,		// We have correctly crafted an item.
	InvalidCraft	// We have selected invalid crafting ingredients.
} State;

#endif
