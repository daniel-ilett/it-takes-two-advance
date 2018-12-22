// The main game loop is written here.

#include "gba.h"
#include "bg.h"

int main()
{
	u16 loop;

	SetMode(MODE_4 | BG2_ENABLE);

	// Transfer background palette data to palette memory.
	for(loop = 0; loop < 256; ++loop)
	{
		BG_PaletteMem[loop] = bgPalette[loop];
	}

	// Transfer background pixel data into VRAM.
	for(loop = 0; loop < (120 * 160); ++loop)
	{
		FrontBuffer[loop] = bgData[loop];
	}

	return 0;
}
