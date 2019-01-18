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

// Struct that holds data about a category.
typedef struct CategoryData
{
	const char categoryString[23];
	const ItemName headItem;
	const ItemName items[23];
	const u8 itemCount;
} CategoryData;

// Define each category's item list and primary item.
const CategoryData categoryData[] = 
{
	{ "Null Category", None, { }, 0 },
	{ "Core Elements", Fire,
		{
			Earth,
			Fire,
			Water,
			Air
		}, 4
	},
	{ "Earth Minerals", Rock,
		{
			Lava,
			Steam,
			Dust,
			Mud,
			Soil,
			Rock,
			Ore,
			Flintstone,
			Gemstone,
			Sand,
			Clay,
			Ice,
			Salt,
			Sulphur
		}, 14
	},
	{ "Metals",	Electrum,
		{
			Iron,
			Copper,
			Lead,
			Gold,
			Silver,
			Electrum,
			Uranium,
			Mercury,
			Mithril
		}, 9
	},
	{ "Gems", Diamond,
		{
			Ruby,
			Sapphire,
			Emerald,
			Topaz,
			Onyx,
			Opal,
			Diamond
		}, 7
	},
	{ "Life", Life,
		{
			Life,
			Bacteria,
			Algae,
			Mushroom,
			Lichen
		}, 5
	},
	{ "Plant Kingdom", Tree,
		{
			Seeds,
			Tree,
			Bush,
			Flower,
			Moss,
			Grass,
			Vine,
			Reeds,
			Papyrus,
			Wheat
		}, 10
	},
	{ "Animal Kingdom", Duck,
		{
			Bird,
			Duck,
			Phoenix,
			Mammal,
			Monkey,
			Human,
			Sheep,
			Pig,
			Cow,
			Chicken,
			Horse
		}, 11
	},
	{ "Sealife", Fish,
		{
			Fish,
			Pufferfish,
			Coral,
			Seaweed,
			Squid
		}, 5
	},
	{ "Almost Human", Zombie,
		{
			Death,
			Golem,
			Zombie,
			Vampire,
			Ghost
		}, 5
	},
	{ "Plant Products", Apple,
		{
			Apple,
			Chestnut,
			Stick,
			Bark,
			Berries,
			Flour,
			Chili,
			Tea,
			Coffee,
			Truffles,
			Alcohol
		}, 11
	},
	{ "Animal Products", Meat,
		{
			Feather,
			Meat,
			Blood,
			Skin,
			Leather,
			Lard,
			Egg,
			Milk,
			Cheese,
			Wool,
			Ink
		}, 11
	},
	{ "Biomes", Swamp,
		{
			Mountain,
			Volcano,
			Geyser,
			Crater,
			River,
			Stream,
			Sea,
			Beach,
			Lake,
			Swamp,
			Marsh,
			Field,
			Hill,
			Forest,
			Farmland,
			Glacier,
			Desert
		}, 17
	},
	{ "Forces of Nature", Storm,
		{
			Sky,
			Sun,
			Cloud,
			Rain,
			Snow,
			Storm,
			Lightning,
			Tornado,
			FireTornado,
			Wind,
			Rainbow,
			Earthquake,
			Flood,
			Tsunami,
			Hurricane,
			Eruption
		}, 16
	},
	{ "Seasons", Autumn,
		{
			Spring,
			Summer,
			Autumn,
			Winter
		}, 4
	},
	{ "Industrial", Anvil,
		{
			Spark,
			Anvil,
			Kiln,
			BlastFurnace,
			Machine,
			Loom,
			Oil,
			Coal,
			Magnet,
			Gear,
			Wire,
			Petrol,
			RocketFuel
		}, 13
	},
	{ "Raw Materials", Brick,
		{
			Wood,
			Charcoal,
			Ash,
			Lye,
			Brick,
			Concrete,
			Rubber,
			Cotton,
			Fibre,
			String,
			Elastic,
			Cloth,
			Ceramic,
			Glass,
			Paper,
			Plastic,
			Fertiliser,
			Saltpetre,
			Gunpowder
		}, 19
	},
	{ "Artisan Goods", Sawblade,
		{
			Rope,
			Wheel,
			Soap,
			Clothes,
			Crown,
			HayBale,
			Quill,
			Pencil,
			Letter,
			Book,
			Money,
			LightBulb,
			IronBar,
			IronBall,
			Sawblade,
			Tracks,
			Balloon,
			Cake
		}, 18
	},
	{ "Weaponry", Handgun,
		{
			Sword,
			Bow,
			Axe,
			Pickaxe,
			Chainsaw,
			Arrow,
			Spear,
			Knife,
			Shears,
			Handgun,
			Rifle,
			SubmachineGun,
			Bayonet,
			TNT,
			Cannon,
			Missile,
			NuclearWarhead,
			Poison,
			DepthCharge,
			Torpedo,
			Trebuchet,
			SiegeRam
		}, 22
	},
	{ "Transport", Train,
		{
			SteamEngine,
			CombustionEngine,
			Biplane,
			Aeroplane,
			Boat,
			Ship,
			PirateShip,
			SteamShip,
			Galleon,
			AircraftCarrier,
			Submarine,
			Cart,
			Chariot,
			Car,
			Bicycle,
			Motorcycle,
			Train,
			Rocket,
			Spaceship
		}, 19
	},
	{ "Buildings", Mansion,
		{
			House,
			Mansion,
			Skyscraper,
			Town,
			City,
			Church,
			Cathedral,
			Farmhouse,
			Barn
		}, 9
	},
	{ "Outer Space", Moon,
		{
			Space,
			Time,
			Meteor,
			MeteorShower,
			Asteroid,
			Comet,
			World,
			Moon,
			Stars,
			Galaxy,
			Supernova,
			DarkMatter,
			Universe,
			Void,
			BlackHole,
			Light,
			Dark,
			Satellite
		}, 18
	},
	{ "Magic", Magic,
		{
			Magic,
			PhilosophersStone,
			Rune,
			Staff, 
			Wizard
		}, 5
	},
	{ "Knowledge", Science,
		{
			Science,
			Technology,
			Engineering,
			Geography,
			Geology,
			Alchemy,
			Religion,
			History,
			Language,
			Art
		}, 10
	},
};

#endif
