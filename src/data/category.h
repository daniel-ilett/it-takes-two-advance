// A list of all categories.

#ifndef CATEGORY_H
#define CATEGORY_H

typedef enum CategoryName
{
	C_None,
	C_Core,
	C_EarthMinerals,
	C_Metals,
	C_Gems,
	C_Life,
	C_PlantKingdom,
	C_AnimalKingdom,
	C_Sealife,
	C_AlmostHuman,
	C_PlantProducts,
	C_AnimalProducts,
	C_Biomes,
	C_ForcesOfNature,
	C_Seasons,
	C_Industrial,
	C_RawMaterials,
	C_ArtisanGoods,
	C_Weaponry,
	C_Transport,
	C_Buildings,
	C_OuterSpace,
	C_Magic,
	C_Knowledge
} CategoryName;

// String names for each category.
const char *categoryStrings[] =
{
	"Null Category",
	"Core Elements",
	"Earth Minerals",
	"Metals",
	"Gems",
	"Life",
	"Plant Kingdom",
	"Animal Kingdom",
	"Sealife",
	"Almost Human",
	"Plant Products",
	"Animal Products",
	"Biomes",
	"Forces of Nature",
	"Seasons",
	"Industrial",
	"Raw Materials",
	"Artisan Goods",
	"Weaponry",
	"Transport",
	"Buildings",
	"Outer Space",
	"Magic",
	"Knowledge"
};

#endif
