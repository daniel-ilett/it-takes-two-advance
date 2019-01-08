// Data for all item sprites.

#ifndef ITEM_SPRITES_H
#define ITEM_SPRITES_H

#include "group_core.h"
#include "group_earthminerals.h"
#include "group_metals.h"
#include "group_gems.h"
#include "group_life.h"
#include "group_plantkingdom.h"
#include "group_animalkingdom.h"
#include "group_sealife.h"
#include "group_unhuman.h"
#include "group_plantproducts.h"
#include "group_animalproducts.h"
#include "group_biomes.h"
#include "group_forcesofnature.h"
#include "group_seasons.h"
#include "group_industrial.h"
#include "group_rawmaterials.h"
#include "group_artisangoods.h"
#include "group_weapons.h"
#include "group_transport.h"
#include "group_buildings.h"
#include "group_outerspace.h"
#include "group_magic.h"
#include "group_knowledge.h"

// Include definition of a locked item.
const u16 tx_LockedData[] = {
     0x0138, 0x0101, 0x0101, 0x0101,
     0x3901, 0x3901, 0x0139, 0x3939,
     0x0101, 0x3939, 0x3901, 0x0139,
     0x3901, 0x0139, 0x3939, 0x3701,
     0x3901, 0x3901, 0x0139, 0x3937,
     0x0101, 0x3939, 0x3701, 0x0139,
     0x3901, 0x0139, 0x3739, 0x3901,
     0x3901, 0x3901, 0x3739, 0x3737,
     0x0101, 0x0101, 0x0101, 0x3801,
     0x3901, 0x0139, 0x3939, 0x0101,
     0x3939, 0x3901, 0x0139, 0x0139,
     0x0137, 0x3939, 0x3901, 0x0139,
     0x3701, 0x0139, 0x3939, 0x0101,
     0x3939, 0x3937, 0x0139, 0x0139,
     0x0139, 0x3937, 0x3901, 0x0139,
     0x3737, 0x0137, 0x3939, 0x0101,
     0x0101, 0x3939, 0x3701, 0x3737,
     0x3901, 0x0139, 0x3739, 0x0137,
     0x3901, 0x3901, 0x3739, 0x3737,
     0x0101, 0x3939, 0x3701, 0x3737,
     0x3901, 0x0139, 0x3939, 0x3901,
     0x3901, 0x3901, 0x0139, 0x3939,
     0x0101, 0x3939, 0x3901, 0x0139,
     0x0138, 0x0101, 0x0101, 0x0101,
     0x3737, 0x3937, 0x0139, 0x0139,
     0x3701, 0x3937, 0x3901, 0x0139,
     0x3737, 0x0137, 0x3939, 0x0101,
     0x3737, 0x3937, 0x0139, 0x0139,
     0x0139, 0x3939, 0x3901, 0x0139,
     0x3901, 0x0139, 0x3939, 0x0101,
     0x3939, 0x3901, 0x0139, 0x0139,
     0x0101, 0x0101, 0x0101, 0x3801,
};

// Include definition of a hidden or invalid item.
const u16 tx_NoneData[] = {
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
     0x3838, 0x3838, 0x3838, 0x3838,
};

// Include the palette only once instead of in each sprite file.
const u16 itemPalette[] = {
     0x0000, 0x2020, 0x0424, 0x1445, 0x0882, 0x0449, 0x0C63, 0x1883, 
     0x400B, 0x4081, 0x10A5, 0x18C6, 0x0D02, 0x0874, 0x3C54, 0x10AE, 
     0x401F, 0x34CA, 0x7CE2, 0x205C, 0x1509, 0x089C, 0x2D62, 0x11A6, 
     0x7CBA, 0x318C, 0x1173, 0x2975, 0x3240, 0x0D7D, 0x0281, 0x5579, 
     0x7E22, 0x5A27, 0x0E8C, 0x4EC3, 0x4A52, 0x3274, 0x7EE2, 0x3741,
     0x72C9, 0x0A7F, 0x2E9D, 0x4E9C, 0x72BE, 0x7FA2, 0x6318, 0x53AC, 
     0x0BEC, 0x7B8E, 0x0B7F, 0x5BB5, 0x7796, 0x2B9D, 0x539E, 0x13FF, 
     0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
     0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// Define the size of an item sprite so we dont need to recalculate it.
const u16 itemSpriteSize = sizeof(tx_LockedData);

#endif
