// Struct that holds the starting position data for sprites.

#ifndef SPRITE_OBJ_H
#define SPRITE_OBJ_H

typedef struct SpriteObj
{
	u8 startPosX;
	u8 startPosY;
} SpriteObj;

// Set the default positions of each sprite.
SpriteObj sprite_data[] = 
{
	// Row 1 of item palette. (x9)
	{ .startPosX = 16, 	.startPosY = 80 },
	{ .startPosX = 40, 	.startPosY = 80 },
	{ .startPosX = 64, 	.startPosY = 80 },
	{ .startPosX = 88, 	.startPosY = 80 },
	{ .startPosX = 112, .startPosY = 80 },
	{ .startPosX = 136, .startPosY = 80 },
	{ .startPosX = 160, .startPosY = 80 },
	{ .startPosX = 184, .startPosY = 80 },
	{ .startPosX = 208, .startPosY = 80 },

	// Row 2 of item palette. (x9)
	{ .startPosX = 16, 	.startPosY = 104 },
	{ .startPosX = 40, 	.startPosY = 104 },
	{ .startPosX = 64, 	.startPosY = 104 },
	{ .startPosX = 88, 	.startPosY = 104 },
	{ .startPosX = 112, .startPosY = 104 },
	{ .startPosX = 136, .startPosY = 104 },
	{ .startPosX = 160, .startPosY = 104 },
	{ .startPosX = 184, .startPosY = 104 },
	{ .startPosX = 208, .startPosY = 104 },

	// Row 3 of item palette. (x5)
	{ .startPosX = 64, 	.startPosY = 128 },
	{ .startPosX = 88, 	.startPosY = 128 },
	{ .startPosX = 112, .startPosY = 128 },
	{ .startPosX = 136, .startPosY = 128 },
	{ .startPosX = 160, .startPosY = 128 },

	// Picked item sprites. (x2)
	{ .startPosX = 100, .startPosY = 24  },
	{ .startPosX = 124, .startPosY = 24  },

	// Cursor slot. (x1)
	{ .startPosX = 16, 	.startPosY = 96  },

	// Text slots. (x22)
	{ .startPosX = 32, 	.startPosY = 56  },
	{ .startPosX = 40, 	.startPosY = 56  },
	{ .startPosX = 48, 	.startPosY = 56  },
	{ .startPosX = 56, 	.startPosY = 56  },
	{ .startPosX = 64, 	.startPosY = 56  },
	{ .startPosX = 72, 	.startPosY = 56  },
	{ .startPosX = 80, 	.startPosY = 56  },
	{ .startPosX = 88, 	.startPosY = 56  },
	{ .startPosX = 96, 	.startPosY = 56  },
	{ .startPosX = 104, .startPosY = 56  },
	{ .startPosX = 112, .startPosY = 56  },
	{ .startPosX = 120, .startPosY = 56  },
	{ .startPosX = 128, .startPosY = 56  },
	{ .startPosX = 136, .startPosY = 56  },
	{ .startPosX = 144, .startPosY = 56  },
	{ .startPosX = 152, .startPosY = 56  },
	{ .startPosX = 160, .startPosY = 56  },
	{ .startPosX = 168, .startPosY = 56  },
	{ .startPosX = 176, .startPosY = 56  },
	{ .startPosX = 184, .startPosY = 56  },
	{ .startPosX = 192, .startPosY = 56  },
	{ .startPosX = 200, .startPosY = 56  },

	// Progress text slots. (x7)
	{ .startPosX = 176, .startPosY = 8   },
	{ .startPosX = 184, .startPosY = 8   },
	{ .startPosX = 192, .startPosY = 8   },
	{ .startPosX = 200, .startPosY = 8   },
	{ .startPosX = 208, .startPosY = 8   },
	{ .startPosX = 216, .startPosY = 8   },
	{ .startPosX = 224, .startPosY = 8   },

	// Heading text slots. (x19)
	{ .startPosX = 8, 	.startPosY = 8   },
	{ .startPosX = 16, 	.startPosY = 8   },
	{ .startPosX = 24, 	.startPosY = 8   },
	{ .startPosX = 32, 	.startPosY = 8   },
	{ .startPosX = 40, 	.startPosY = 8   },
	{ .startPosX = 48, 	.startPosY = 8   },
	{ .startPosX = 56, 	.startPosY = 8   },
	{ .startPosX = 64, 	.startPosY = 8   },
	{ .startPosX = 72, 	.startPosY = 8   },
	{ .startPosX = 80, 	.startPosY = 8   },
	{ .startPosX = 88, 	.startPosY = 8   },
	{ .startPosX = 96, 	.startPosY = 8   },
	{ .startPosX = 104, .startPosY = 8   },
	{ .startPosX = 112, .startPosY = 8   },
	{ .startPosX = 120, .startPosY = 8   },
	{ .startPosX = 128, .startPosY = 8   },
	{ .startPosX = 136, .startPosY = 8   },
	{ .startPosX = 144, .startPosY = 8   },
	{ .startPosX = 152, .startPosY = 8   },
};

#endif
