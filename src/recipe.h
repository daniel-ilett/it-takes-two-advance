// Define the structure used for recipes.
#ifndef RECIPE_H
#define RECIPE_H

#include "item.h"

typedef struct Recipe
{
	ItemName result;
	ItemName itemA;
	ItemName itemB;
} Recipe;

// Create list of all recipes.
Recipe recipes[] = 
{
	{ Air, Knife, Balloon },

	{ Lava, Earth, Fire },
	{ Steam, Fire, Water },
	{ Dust, Earth, Air },
	{ Dust, Earth, Wind },
	{ Mud, Earth, Water },
	{ Soil, Mud, Fire },
	{ Soil, Mud, Sun },
	{ Rock, Lava, Water },
	{ Ore, Lava, Water },
	{ Flintstone, Rock, Air },
	{ Flintstone, Rock, Wind },
	{ Gemstone, Machine, Rock },
	{ Gemstone, Machine, Flintstone },
	{ Sand, Water, Flintstone },
	{ Clay, Water, Rock },
	{ Clay, Water, Soil },
	{ Ice, Rock, Water },
	{ Salt, Rock, Pickaxe },
	{ Salt, Rock, Machine },
	{ Sulphur, Lava, Flintstone },

	{ Iron, BlastFurnace, Ore },
	{ Iron, Fire, Ore },
	{ Copper, BlastFurnace, Ore },
	{ Lead, BlastFurnace, Ore },
	{ Gold, Lead, PhilosophersStone },
	{ Gold, Mercury, PhilosophersStone },
	{ Silver, Gold, Spark },
	{ Electrum, Gold, Silver },
	{ Uranium, Science, Iron },
	{ Mercury, Water, Iron },
	{ Mithril, Magic, Iron },

	{ Ruby, Gemstone, Fire },
	{ Sapphire, Gemstone, Water },
	{ Emerald, Gemstone, Life },
	{ Topaz, Gemstone, Spark },
	{ Topaz, Gemstone, Lightning },
	{ Onyx, Gemstone, Dark },
	{ Opal, Gemstone, Light },
	{ Diamond, Gemstone, Air },
	{ Diamond, Gemstone, Wind },

	{ Life, Spark, Sea },
	{ Bacteria, Life, Sea },
	{ Algae, Water, Bacteria },
	{ Algae, River, Bacteria },
	{ Mushroom, Swamp, Life },
	{ Mushroom, Marsh, Life },
	{ Lichen, Algae, Moss },

	{ Seeds, Soil, Life },
	{ Tree, Soil, Seeds },
	{ Bush, Soil, Seeds },
	{ Flower, Grass, Sun },
	{ Moss, Swamp, Algae },
	{ Grass, Soil, Moss },
	{ Vine, Grass, Rope },
	{ Reeds, Grass, Marsh },
	{ Papyrus, Reeds, Marsh },
	{ Wheat, Farmland, Seeds },

	{ Bird, Air, Life },
	{ Duck, River, Bird },
	{ Phoenix, Fire, Bird },
	{ Mammal, Fish, Earth },
	{ Monkey, Mammal, Tree },
	{ Monkey, Mammal, Forest },
	{ Human, Monkey, House },
	{ Sheep, Mammal, Cloud },
	{ Pig, Mammal, Mud },
	{ Cow, Mammal, Field },
	{ Chicken, Bird, Barn },
	{ Horse, Mammal, HayBale },

	{ Fish, Water, Life },
	{ Fish, Sea, Life },
	{ Pufferfish, Fish, Balloon },
	{ Coral, Sea, Life },
	{ Seaweed, Sea, Grass },
	{ Squid, Sea, Life },

	{ Death, Human, Time },
	{ Golem, Life, Clay },
	{ Zombie, Death, Life },
	{ Vampire, Human, Blood },
	{ Ghost, Death, Life },

	{ Apple, Summer, Tree },
	{ Chestnut, Autumn, Tree },
	{ Stick, Wood, Machine },
	{ Bark, Tree, Knife },
	{ Berries, Spring, Tree },
	{ Berries, Spring, Bush },
	{ Flour, Wheat, Machine },
	{ Chili, Fire, Bush },
	{ Tea, Bush, Water },
	{ Coffee, Berries, Water },
	{ Coffee, Seeds, Water },
	{ Truffles, Pig, Earth },
	{ Truffles, Pig, Tree },
	{ Alcohol, Berries, Time },
	{ Alcohol, Apple, Time },

	{ Feather, Chicken, Axe },
	{ Feather, Chicken, Sword },
	{ Feather, Bird, Axe },
	{ Feather, Bird, Sword },
	{ Meat, Mammal, Axe },
	{ Meat, Mammal, Sword },
	{ Blood, Chicken, Axe },
	{ Blood, Chicken, Sword },
	{ Blood, Mammal, Axe },
	{ Blood, Mammal, Sword },
	{ Blood, Bird, Axe },
	{ Blood, Bird, Sword },
	{ Skin, Cow, Knife },
	{ Leather, Skin, Bark },
	{ Lard, Pig, Axe },
	{ Lard, Pig, Sword },
	{ Egg, Chicken, Barn },
	{ Milk, Cow, Grass },
	{ Cheese, Milk, Time },
	{ Wool, Sheep, Shears },
	{ Ink, Squid, Water },
	{ Ink, Squid, Sea },

	{ Mountain, Rock, Rock },
	{ Volcano, Mountain, Lava },
	{ Geyser, Volcano, Steam },
	{ Crater, Meteor, Earth },
	{ Crater, Asteroid, Earth },
	{ River, Water, Water },
	{ Stream, Mountain, River },
	{ Sea, Salt, Water },
	{ Beach, Sand, Sea },
	{ Lake, Crater, Water },
	{ Swamp, Mud, Water },
	{ Marsh, Mud, Salt },
	{ Field, Soil, Grass },
	{ Hill, Soil, Field },
	{ Forest, Field, Tree },
	{ Farmland, Soil, Fertiliser },
	{ Glacier, Mountain, Ice },
	{ Desert, Sand, Rock },

	{ Sky, Air, Air },
	{ Sun, Fire, Sky },
	{ Cloud, Water, Air },
	{ Rain, Sky, Water },
	{ Rain, Cloud, Water },
	{ Snow, Ice, Rain },
	{ Storm, Spark, Rain },
	{ Lightning, Spark, Storm },
	{ Tornado, Storm, Wind },
	{ FireTornado, Fire, Tornado },
	{ Wind, Sky, Air },
	{ Rainbow, Sun, Rain },
	{ Earthquake, Earth, Storm },
	{ Flood, River, Rain },
	{ Tsunami, Sea, Earthquake },
	{ Hurricane, Sea, Storm },
	{ Eruption, Lava, Volcano },

	{ Spring, Tree, Time },
	{ Summer, Sun, Time },
	{ Autumn, Truffles, Time },
	{ Autumn, Mushroom, Time },
	{ Winter, Ice, Time },
	{ Winter, Snow, Time },

	{ Spark, Iron, Flintstone },
	{ Anvil, Iron, Iron },
	{ Kiln, Brick, Fire },
	{ BlastFurnace, Brick, Charcoal },
	{ BlastFurnace, Brick, Coal },
	{ Machine, Gear, Magnet },
	{ Loom, Wood, Wheel },
	{ Oil, Fish, Time },
	{ Coal, Tree, Time },
	{ Coal, Forest, Time },
	{ Magnet, Iron, Iron },
	{ Gear, Iron, Anvil },
	{ Wire, Plastic, Copper },
	{ Petrol, Oil, Machine },
	{ RocketFuel, Petrol, Machine },

	{ Wood, Tree, Axe },
	{ Wood, Tree, Chainsaw },
	{ Wood, Tree, Sword },
	{ Charcoal, Wood, Fire },
	{ Ash, Wood, Fire },
	{ Ash, Charcoal, Fire },
	{ Ash, Coal, Fire },
	{ Lye, Ash, Water },
	{ Brick, Clay, Fire },
	{ Concrete, Flintstone, Ash },
	{ Rubber, Tree, Knife },
	{ Rubber, Balloon, Knife },
	{ Cotton, Bush, Knife },
	{ Fibre, Loom, Cotton },
	{ String, Fibre, Fibre },
	{ Elastic, Rubber, String },
	{ Elastic, Rubber, Rope },
	{ Cloth, Cotton, Fibre },
	{ Ceramic, Kiln, Clay },
	{ Glass, Sand, Fire },
	{ Glass, Sand, Kiln },
	{ Paper, Wood, Papyrus },
	{ Paper, Papyrus, Papyrus },
	{ Plastic, Oil, Machine },
	{ Fertiliser, Cow, Grass },
	{ Saltpetre, Fertiliser, Salt },
	{ Gunpowder, Sulphur, Saltpetre },

	{ Rope, String, String },
	{ Wheel, Wood, IronBar },
	{ Soap, Lard, Lye },
	{ Clothes, Human, Cloth },
	{ Crown, Gold, Gemstone },
	{ Crown, Gold, Diamond },
	{ HayBale, Grass, Sun },
	{ Quill, Feather, Ink },
	{ Pencil, Wood, Quill },
	{ Letter, Pencil, Paper },
	{ Letter, Quill, Paper },
	{ Book, Leather, Paper },
	{ Money, Paper, Gold },
	{ LightBulb, Wire, Glass },
	{ IronBar, Iron, Stick },
	{ IronBall, Iron, Machine },
	{ Sawblade, Iron, Anvil },
	{ Tracks, Wood, Iron },
	{ Balloon, Rubber, Air },
	{ Cake, Egg, Flour },

	{ Sword, Iron, Anvil },
	{ Bow, Stick, String },
	{ Axe, Wood, Flintstone },
	{ Pickaxe, Wood, Iron },
	{ Chainsaw, Sawblade, Machine },
	{ Arrow, Stick, Feather },
	{ Spear, Iron, Arrow },
	{ Knife, Spear, Iron },
	{ Shears, Knife, Knife },
	{ Handgun, Iron, Gunpowder },
	{ Rifle, Iron, Handgun },
	{ SubmachineGun, Machine, Rifle },
	{ Bayonet, Rifle, Knife },
	{ TNT, Gunpowder, Plastic },
	{ Cannon, Gunpowder, IronBall },
	{ Missile, Iron, TNT },
	{ NuclearWarhead, Missile, Uranium },
	{ Poison, Pufferfish, Knife },
	{ DepthCharge, Submarine, TNT },
	{ Torpedo, Submarine, Missile },
	{ Trebuchet, Wood, Rope },
	{ SiegeRam, Wood, Rock },

	{ SteamEngine, Steam, Iron },
	{ CombustionEngine, Petrol, SteamEngine },
	{ Biplane, Air, Wood },
	{ Aeroplane, Biplane, Iron },
	{ Boat, Water, Wood },
	{ Ship, Boat, Iron },
	{ PirateShip, Cannon, Ship },
	{ SteamShip, SteamEngine, Ship },
	{ Galleon, Gold, Ship },
	{ AircraftCarrier, Aeroplane, Ship },
	{ Submarine, Sea, Ship },
	{ Cart, Wheel, Wood },
	{ Chariot, Cart, Horse },
	{ Car, CombustionEngine, Iron },
	{ Bicycle, Wheel, Iron },
	{ Motorcycle, CombustionEngine, Bicycle },
	{ Train, Car, Tracks },
	{ Rocket, RocketFuel, Plastic },
	{ Spaceship, Space, Rocket },

	{ House, Brick, Concrete },
	{ Mansion, House, Money },
	{ Skyscraper, House, Glass },
	{ Town, House, House },
	{ City, Town, Skyscraper },
	{ Church, House, Religion },
	{ Cathedral, Church, Gold },
	{ Cathedral, Church, Money },
	{ Farmhouse, Farmland, House },
	{ Barn, Mammal, House },

	{ Space, Sun, Sky },
	{ Time, Sun, Sky },
	{ Meteor, Sky, Rock },
	{ MeteorShower, Meteor, Rain },
	{ Asteroid, Rock, Space },
	{ Comet, Ice, Meteor },
	{ Comet, Ice, Asteroid },
	{ World, Earth, Space },
	{ Moon, World, Rock },
	{ Stars, Space, Sun },
	{ Galaxy, Stars, Stars },
	{ Supernova, Stars, Time },
	{ DarkMatter, Space, Universe },
	{ Universe, Space, Time },
	{ Void, Universe, DarkMatter },
	{ BlackHole, Universe, Crater },
	{ Light, Space, Stars },
	{ Dark, Space, Void },
	{ Satellite, World, Iron },
	{ Satellite, Moon, Iron },

	{ Magic, Science, Rainbow },
	{ PhilosophersStone, Magic, Flintstone },
	{ PhilosophersStone, Alchemy, Flintstone },
	{ Rune, Magic, Rock },
	{ Staff, Magic, Stick },
	{ Wizard, Human, Staff },

	{ Science, Rocket, Universe },
	{ Science, Rocket, Space },
	{ Technology, Spark, Plastic },
	{ Engineering, Science, Wheel },
	{ Engineering, Science, SteamEngine },
	{ Engineering, Science, CombustionEngine },
	{ Geography, World, Plastic },
	{ Geology, Rock, Flintstone },
	{ Alchemy, Science, Magic },
	{ Religion, Book, Human },
	{ History, Religion, Sword },
	{ Language, Human, Human },
	{ Art, Ink, Paper }
};

// Cycle through all recipes to find the crafting result.
ItemName checkRecipe(ItemName itemA, ItemName itemB)
{
	int i;
	for(i = 0; i < 311; ++i)
	{
		if(recipes[i].itemA == itemA)
		{
			if(recipes[i].itemB == itemB)
			{
				return recipes[i].result;
			}
		}
		else if(recipes[i].itemB == itemA)
		{
			if(recipes[i].itemA == itemB)
			{
				return recipes[i].result;
			}
		}
	}

	return None;
}

#endif
