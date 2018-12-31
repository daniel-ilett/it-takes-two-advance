// Set up video memory parameters.
#ifndef GBA_VIDEO_H
#define GBA_VIDEO_H

#include "gba_types.h"
#include "gba_regs.h"

// The screen width and height are constant.
#define SCREEN_WIDTH	240
#define SCREEN_HEIGHT	160

// Define screen modes 0 through 5.
#define MODE_0	0x0
#define MODE_1	0x1
#define MODE_2	0x2
#define MODE_3	0x3
#define MODE_4	0x4
#define MODE_5	0x5

#define BackBuffer	0x10	// Define a second buffer for double buffering.

#define H_BLANK_OAM	0x20	// Allow Object Attribute Memory to be updated
							// during horizontal blank?

#define OBJ_MAP_2D	0x00	// Store sprite data in a 2D array.
#define OBJ_MAP_1D	0x40	// Store sprite data in a 1D array. Preferred.

#define BG0_ENABLE	0x100	// Enable background 0.
#define BG1_ENABLE	0x200	// Enable background 1.
#define BG2_ENABLE	0x400	// Enable background 2.
#define BG3_ENABLE	0x800	// Enable background 3.
#define OBJ_ENABLE	0x1000	// Enable sprites.

// Set the mode(s) you wish to use, using logical-OR, eg:
// SetMode(MODE_2 | OBJ_ENABLE | OBJ_MAP_1D);
#define SetMode(mode)	REG_DISPCNT = (mode)

#endif
