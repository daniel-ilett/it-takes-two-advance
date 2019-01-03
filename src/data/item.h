// List of all items.

#ifndef ITEM_H
#define ITEM_H

typedef enum ItemName
{
	// Null item
	None,

	// Core.
	Earth,
	Fire,
	Water,
	Air,

	// Earth Minerals.
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
	Sulphur,

	// Metals.
	Iron,
	Copper,
	Lead,
	Gold,
	Silver,
	Electrum,
	Uranium,
	Mercury,
	Mithril,

	// Gems.
	Ruby,
	Sapphire,
	Emerald,
	Topaz,
	Onyx,
	Opal,
	Diamond,

	// Life.
	Life,
	Bacteria,
	Algae,
	Mushroom,
	Lichen,

	// Plant Kingdom.
	Seeds,
	Tree,
	Bush,
	Flower,
	Moss,
	Grass,
	Vine,
	Reeds,
	Papyrus,
	Wheat,

	// Animal Kingdom.
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
	Horse,

	// Sealife.
	Fish,
	Pufferfish,
	Coral,
	Seaweed,
	Squid,

	// Almost Human.
	Death,
	Golem,
	Zombie,
	Vampire,
	Ghost,

	// Plant Products.
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
	Alcohol,

	// Animal Products.
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
	Ink,

	// Biomes.
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
	Desert,

	// Forces of Nature.
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
	Eruption,

	// Seasons.
	Spring,
	Summer,
	Autumn,
	Winter,

	// Industrial.
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
	RocketFuel,

	// Raw Materials.
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
	Gunpowder,

	// Artisan Goods.
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
	Cake,

	// Weaponry.
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
	SiegeRam,

	// Transport.
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
	Spaceship,

	// Buildings.
	House,
	Mansion,
	Skyscraper,
	Town,
	City,
	Church,
	Cathedral,
	Farmhouse,
	Barn,

	// Outer Space.
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
	Satellite,

	// Magic.
	Magic,
	PhilosophersStone,
	Rune,
	Staff,
	Wizard,

	// Knowledge.
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
} ItemName;

// String names for each item.
const char *itemStrings[] = 
{
	"Not Unlocked",

	"Earth",
	"Fire",
	"Water",
	"Air",

	"Lava",
	"Steam",
	"Dust",
	"Mud",
	"Soil",
	"Rock",
	"Ore",
	"Flintstone",
	"Gemstone",
	"Sand",
	"Clay",
	"Ice",
	"Salt",
	"Sulphur",

	"Iron",
	"Copper",
	"Lead",
	"Gold",
	"Silver",
	"Electrum",
	"Uranium",
	"Mercury",
	"Mithril",

	"Ruby",
	"Sapphire",
	"Emerald",
	"Topaz",
	"Onyx",
	"Opal",
	"Diamond",

	"Life",
	"Bacteria",
	"Algae",
	"Mushroom",
	"Lichen",

	"Seeds",
	"Tree",
	"Bush",
	"Flower",
	"Moss",
	"Grass",
	"Vine",
	"Reeds",
	"Papyrus",
	"Wheat",

	"Bird",
	"Duck",
	"Phoenix",
	"Mammal",
	"Monkey",
	"Human",
	"Sheep",
	"Pig",
	"Cow",
	"Chicken",
	"Horse",

	"Fish",
	"Pufferfish",
	"Coral",
	"Seaweed",
	"Squid",

	"Death",
	"Golem",
	"Zombie",
	"Vampire",
	"Ghost",

	"Apple",
	"Chestnut",
	"Stick",
	"Bark",
	"Berries",
	"Flour",
	"Chili",
	"Tea",
	"Coffee",
	"Truffles",
	"Alcohol",

	"Feather",
	"Meat",
	"Blood",
	"Skin",
	"Leather",
	"Lard",
	"Egg",
	"Milk",
	"Cheese",
	"Wool",
	"Ink",

	"Mountain",
	"Volcano",
	"Geyser",
	"Crater",
	"River",
	"Stream",
	"Sea",
	"Beach",
	"Lake",
	"Swamp",
	"Marsh",
	"Field",
	"Hill",
	"Forest",
	"Farmland",
	"Glacier",
	"Desert",

	"Sky",
	"Sun",
	"Cloud",
	"Rain",
	"Snow",
	"Storm",
	"Lightning",
	"Tornado",
	"Fire Tornado",
	"Wind",
	"Rainbow",
	"Earthquake",
	"Flood",
	"Tsunami",
	"Hurricane",
	"Eruption",

	"Spring",
	"Summer",
	"Autumn",
	"Winter",

	"Spark",
	"Anvil",
	"Kiln",
	"Blast Furnace",
	"Machine",
	"Loom",
	"Oil",
	"Coal",
	"Magnet",
	"Gear",
	"Wire",
	"Petrol",
	"Rocket Fuel",

	"Wood",
	"Charcoal",
	"Ash",
	"Lye",
	"Brick",
	"Concrete",
	"Rubber",
	"Cotton",
	"Fibre",
	"String",
	"Elastic",
	"Cloth",
	"Ceramic",
	"Glass",
	"Paper",
	"Plastic",
	"Fertiliser",
	"Saltpetre",
	"Gunpowder",

	"Rope",
	"Wheel",
	"Soap",
	"Clothes",
	"Crown",
	"Hay Bale",
	"Quill",
	"Pencil",
	"Letter",
	"Book",
	"Money",
	"Light Bulb", 
	"Iron Bar",
	"Iron Ball",
	"Sawblade",
	"Tracks",
	"Balloon",
	"Cake",

	"Sword",
	"Bow",
	"Axe",
	"Pickaxe",
	"Chainsaw",
	"Arrow",
	"Spear",
	"Knife",
	"Shears",
	"Handgun",
	"Rifle",
	"Submachine Gun",
	"Bayonet",
	"TNT",
	"Cannon",
	"Missile",
	"Nuclear Warhead",
	"Poison",
	"Depth Charge",
	"Torpedo",
	"Trebuchet",
	"Siege Ram",

	"Steam Engine",
	"Combustion Engine",
	"Biplane",
	"Aeroplane",
	"Boat",
	"Ship",
	"Pirate Ship",
	"Steam Ship",
	"Galleon",
	"Aircraft Carrier",
	"Submarine",
	"Cart",
	"Chariot",
	"Car",
	"Bicycle",
	"Motorcycle",
	"Train",
	"Rocket",
	"Spaceship",

	"House",
	"Mansion",
	"Skyscraper",
	"Town",
	"City",
	"Church",
	"Cathedral",
	"Farmhouse",
	"Barn",

	"Space",
	"Time",
	"Meteor",
	"Meteor Shower",
	"Asteroid",
	"Comet",
	"World",
	"Moon",
	"Stars",
	"Galaxy",
	"Supernova",
	"Dark Matter",
	"Universe",
	"Void",
	"Black Hole",
	"Light",
	"Dark",
	"Satellite",

	"Magic",
	"Philosopher's Stone",
	"Rune",
	"Staff",
	"Wizard",

	"Science",
	"Technology",
	"Engineering",
	"Geography",
	"Geology",
	"Alchemy",
	"Religion",
	"History",
	"Language",
	"Art"
};

/*
// Structure containing data about the item.
typedef struct ItemData
{
	char name[22];
} ItemData;
*/

#endif