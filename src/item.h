// List of all items.

#ifndef ITEM_H
#define ITEM_H

#include "sprite/item_sprites.h"

// Define a struct to hold together all data related to an item.
typedef struct ItemData
{
	const char itemName[23];
	const u16 *itemSprite;
} ItemData;

// Keep all item data together in one place.
const ItemData itemData[] = 
{
	{ "Not Unlocked", tx_NoneData },

	{ "Earth", tx_EarthData },
	{ "Fire", tx_FireData },
	{ "Water", tx_WaterData },
	{ "Air", tx_AirData },

	{ "Lava", tx_LavaData },
	{ "Steam", tx_SteamData },
	{ "Dust", tx_DustData },
	{ "Mud", tx_MudData },
	{ "Soil", tx_SoilData },
	{ "Rock", tx_RockData },
	{ "Ore", tx_OreData },
	{ "Flintstone", tx_FlintstoneData },
	{ "Gemstone", tx_GemstoneData },
	{ "Sand", tx_SandData },
	{ "Clay", tx_ClayData },
	{ "Ice", tx_IceData },
	{ "Salt", tx_SaltData },
	{ "Sulphur", tx_SulphurData },

	{ "Iron", tx_IronData },
	{ "Copper", tx_CopperData },
	{ "Lead", tx_LeadData },
	{ "Gold", tx_GoldData },
	{ "Silver", tx_SilverData },
	{ "Electrum", tx_ElectrumData },
	{ "Uranium", tx_UraniumData },
	{ "Mercury", tx_MercuryData },
	{ "Mithril", tx_MithrilData },

	{ "Ruby", tx_RubyData },
	{ "Sapphire", tx_SapphireData },
	{ "Emerald", tx_EmeraldData },
	{ "Topaz", tx_TopazData },
	{ "Onyx", tx_OnyxData },
	{ "Opal", tx_OpalData },
	{ "Diamond", tx_DiamondData },

	{ "Life", tx_LifeData },
	{ "Bacteria", tx_BacteriaData },
	{ "Algae", tx_AlgaeData },
	{ "Mushroom", tx_MushroomData },
	{ "Lichen", tx_LichenData },

	{ "Seeds", tx_SeedsData },
	{ "Tree", tx_TreeData },
	{ "Bush", tx_BushData },
	{ "Flower", tx_FlowerData },
	{ "Moss", tx_MossData },
	{ "Grass", tx_GrassData },
	{ "Vine", tx_VineData },
	{ "Reeds", tx_ReedsData },
	{ "Papyrus", tx_PapyrusData },
	{ "Wheat", tx_WheatData },

	{ "Bird", tx_BirdData },
	{ "Duck", tx_DuckData },
	{ "Phoenix", tx_PhoenixData },
	{ "Mammal", tx_MammalData },
	{ "Monkey", tx_MonkeyData },
	{ "Human", tx_HumanData },
	{ "Sheep", tx_SheepData },
	{ "Pig", tx_PigData },
	{ "Cow", tx_CowData },
	{ "Chicken", tx_ChickenData },
	{ "Horse", tx_HorseData },

	{ "Fish", tx_FishData },
	{ "Pufferfish", tx_PufferfishData },
	{ "Coral", tx_CoralData },
	{ "Seaweed", tx_SeaweedData },
	{ "Squid", tx_SquidData },

	{ "Death", tx_DeathData },
	{ "Golem", tx_GolemData },
	{ "Zombie", tx_ZombieData },
	{ "Vampire", tx_VampireData },
	{ "Ghost", tx_GhostData },

	{ "Apple", tx_AppleData },
	{ "Chestnut", tx_ChestnutData },
	{ "Stick", tx_StickData },
	{ "Bark", tx_BarkData },
	{ "Berries", tx_BerriesData },
	{ "Flour", tx_FlourData },
	{ "Chili", tx_ChiliData },
	{ "Tea", tx_TeaData },
	{ "Coffee", tx_CoffeeData },
	{ "Truffles", tx_TrufflesData },
	{ "Alcohol", tx_AlcoholData },

	{ "Feather", tx_FeatherData },
	{ "Meat", tx_MeatData },
	{ "Blood", tx_BloodData },
	{ "Skin", tx_SkinData },
	{ "Leather", tx_LeatherData },
	{ "Lard", tx_LardData },
	{ "Egg", tx_EggData },
	{ "Milk", tx_MilkData },
	{ "Cheese", tx_CheeseData },
	{ "Wool", tx_WoolData },
	{ "Ink", tx_InkData },

	{ "Mountain", tx_MountainData },
	{ "Volcano", tx_VolcanoData },
	{ "Geyser", tx_GeyserData },
	{ "Crater", tx_CraterData },
	{ "River", tx_RiverData },
	{ "Stream", tx_StreamData },
	{ "Sea", tx_SeaData },
	{ "Beach", tx_BeachData },
	{ "Lake", tx_LakeData },
	{ "Swamp", tx_SwampData },
	{ "Marsh", tx_MarshData },
	{ "Field", tx_FieldData },
	{ "Hill", tx_HillData },
	{ "Forest", tx_ForestData },
	{ "Farmland", tx_FarmlandData },
	{ "Glacier", tx_GlacierData },
	{ "Desert", tx_DesertData },

	{ "Sky", tx_SkyData },
	{ "Sun", tx_SunData },
	{ "Cloud", tx_CloudData },
	{ "Rain", tx_RainData },
	{ "Snow", tx_SnowData },
	{ "Storm", tx_StormData },
	{ "Lightning", tx_LightningData },
	{ "Tornado", tx_TornadoData },
	{ "Fire Tornado", tx_FireTornadoData },
	{ "Wind", tx_WindData },
	{ "Rainbow", tx_RainbowData },
	{ "Earthquake", tx_EarthquakeData },
	{ "Flood", tx_FloodData },
	{ "Tsunami", tx_TsunamiData },
	{ "Hurricane", tx_HurricaneData },
	{ "Eruption", tx_EruptionData },

	{ "Spring", tx_SpringData },
	{ "Summer", tx_SummerData },
	{ "Autumn", tx_AutumnData },
	{ "Winter", tx_WinterData },

	{ "Spark", tx_SparkData },
	{ "Anvil", tx_AnvilData },
	{ "Kiln", tx_KilnData },
	{ "Blast Furnace", tx_BlastFurnaceData },
	{ "Machine", tx_MachineData },
	{ "Loom", tx_LoomData },
	{ "Oil", tx_OilData },
	{ "Coal", tx_CoalData },
	{ "Magnet", tx_MagnetData },
	{ "Gear", tx_GearData },
	{ "Wire", tx_WireData },
	{ "Petrol", tx_PetrolData },
	{ "Rocket Fuel", tx_RocketFuelData },

	{ "Wood", tx_WoodData },
	{ "Charcoal", tx_CharcoalData },
	{ "Ash", tx_AshData },
	{ "Lye", tx_LyeData },
	{ "Brick", tx_BrickData },
	{ "Concrete", tx_ConcreteData },
	{ "Rubber", tx_RubberData },
	{ "Cotton", tx_CottonData },
	{ "Fibre", tx_FibreData },
	{ "String", tx_StringData },
	{ "Elastic", tx_ElasticData },
	{ "Cloth", tx_ClothData },
	{ "Ceramic", tx_CeramicData },
	{ "Glass", tx_GlassData },
	{ "Paper", tx_PaperData },
	{ "Plastic", tx_PlasticData },
	{ "Fertiliser", tx_FertiliserData },
	{ "Saltpetre", tx_SaltpetreData },
	{ "Gunpowder", tx_GunpowderData },

	{ "Rope", tx_RopeData },
	{ "Wheel", tx_WheelData },
	{ "Soap", tx_SoapData },
	{ "Clothes", tx_ClothesData },
	{ "Crown", tx_CrownData },
	{ "Hay Bale", tx_HayBaleData },
	{ "Quill", tx_QuillData },
	{ "Pencil", tx_PencilData },
	{ "Letter", tx_LetterData },
	{ "Book", tx_BookData },
	{ "Money", tx_MoneyData },
	{ "Light Bulb", tx_LightBulbData },
	{ "Iron Bar", tx_IronBarData },
	{ "Iron Ball", tx_IronBallData },
	{ "Sawblade", tx_SawbladeData },
	{ "Tracks", tx_TracksData },
	{ "Balloon", tx_BalloonData },
	{ "Cake", tx_CakeData },

	{ "Sword", tx_SwordData },
	{ "Bow", tx_BowData },
	{ "Axe", tx_AxeData },
	{ "Pickaxe", tx_PickaxeData },
	{ "Chainsaw", tx_ChainsawData },
	{ "Arrow", tx_ArrowData },
	{ "Spear", tx_SpearData },
	{ "Knife", tx_KnifeData },
	{ "Shears", tx_ShearsData },
	{ "Handgun", tx_HandgunData },
	{ "Rifle", tx_RifleData },
	{ "Submachine Gun", tx_SubmachineGunData },
	{ "Bayonet", tx_BayonetData },
	{ "TNT", tx_TNTData },
	{ "Cannon", tx_CannonData },
	{ "Missile", tx_MissileData },
	{ "Nuclear Warhead", tx_NuclearWarheadData },
	{ "Poison", tx_PoisonData },
	{ "Depth Charge", tx_DepthChargeData },
	{ "Torpedo", tx_TorpedoData },
	{ "Trebuchet", tx_TrebuchetData },
	{ "Siege Ram", tx_SiegeRamData },

	{ "Steam Engine", tx_SteamEngineData },
	{ "Combustion Engine", tx_CombustionEngineData },
	{ "Biplane", tx_BiplaneData },
	{ "Aeroplane", tx_AeroplaneData },
	{ "Boat", tx_BoatData },
	{ "Ship", tx_ShipData },
	{ "Pirate Ship", tx_PirateShipData },
	{ "Steam Ship", tx_SteamShipData },
	{ "Galleon", tx_GalleonData },
	{ "Aircraft Carrier", tx_AircraftCarrierData },
	{ "Submarine", tx_SubmarineData },
	{ "Cart", tx_CartData },
	{ "Chariot", tx_ChariotData },
	{ "Car", tx_CarData },
	{ "Bicycle", tx_BicycleData },
	{ "Motorcycle", tx_MotorcycleData },
	{ "Train", tx_TrainData },
	{ "Rocket", tx_RocketData },
	{ "Spaceship", tx_SpaceshipData },

	{ "House", tx_HouseData },
	{ "Mansion", tx_MansionData },
	{ "Skyscraper", tx_SkyscraperData },
	{ "Town", tx_TownData },
	{ "City", tx_CityData },
	{ "Church", tx_ChurchData },
	{ "Cathedral", tx_CathedralData },
	{ "Farmhouse", tx_FarmhouseData },
	{ "Barn", tx_BarnData },

	{ "Space", tx_SpaceData },
	{ "Time", tx_TimeData },
	{ "Meteor", tx_MeteorData },
	{ "Meteor Shower", tx_MeteorShowerData },
	{ "Asteroid", tx_AsteroidData },
	{ "Comet", tx_CometData },
	{ "World", tx_WorldData },
	{ "Moon", tx_MoonData },
	{ "Stars", tx_StarsData },
	{ "Galaxy", tx_GalaxyData },
	{ "Supernova", tx_SupernovaData },
	{ "Dark Matter", tx_DarkMatterData },
	{ "Universe", tx_UniverseData },
	{ "Void", tx_VoidData },
	{ "Black Hole", tx_BlackHoleData },
	{ "Light", tx_LightData },
	{ "Dark", tx_DarkData },
	{ "Satellite", tx_SatelliteData },

	{ "Magic", tx_MagicData },
	{ "Philosopher's Stone", tx_PhilosophersStoneData },
	{ "Rune", tx_RuneData },
	{ "Staff", tx_StaffData },
	{ "Wizard", tx_WizardData },

	{ "Science", tx_ScienceData },
	{ "Technology", tx_TechnologyData },
	{ "Engineering", tx_EngineeringData },
	{ "Geography", tx_GeographyData },
	{ "Geology", tx_GeologyData },
	{ "Alchemy", tx_AlchemyData },
	{ "Religion", tx_ReligionData },
	{ "History", tx_HistoryData },
	{ "Language", tx_LanguageData },
	{ "Art", tx_ArtData }
};

// Enumerate the name of each item.
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

#endif
