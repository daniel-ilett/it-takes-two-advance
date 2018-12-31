// Define register addresses.
#ifndef GBA_REGS_H
#define GBA_REGS_H

#include "gba_types.h"

#define OAM_Mem			((u16*)0x7000000)			// Sprites - 128. Coordinates and size.
#define OBJ_PaletteMem	((u16*)0x5000200)			// Sprite palette - 256/16 colours.
#define OAM_Data		((u16*)0x6010000)			// Bitmap sprite data.

#define FrontBuffer		((u16*)0x6000000)			// Display memory (in mode 3-5).
#define BG_PaletteMem	((u16*)0x5000000)			// Background palette - 256/16 colours.

#define REG_DISPCNT		*(u16*)0x4000000			// Display control mode.
#define REG_VCOUNT		*(volatile u16*)0x4000006	// Vertical control sync.

#define WaitForVsync()	while(REG_VCOUNT != 160);

#endif
