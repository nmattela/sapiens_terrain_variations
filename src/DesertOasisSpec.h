#ifndef DesertOasisSpec
#define DesertOasisSpec

#include "customBiomes.h"

static Biome DesertOasisBiome = {
    .type = DesertOasis,
    .odds = 0.375,
    .subBiomes = {},
};


static TerrainBaseTypeOdds desertOasisLimestone = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.001,
    .size = XS,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 40,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 100,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 10,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = { "limestone" },
};


static TerrainBaseTypeOdds desertOasisRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.003,
    .size = XS,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 8,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 3,
    .steepnessTo = 200,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100000,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds desertOasisRichDirt = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.000001,
    .size = S,
    .baseAltitudeFrom = 99999999,
    .baseAltitudeTo = 0,
    .minBaseAltitude = -0.00001,
    .maxBaseAltitude = 0.0000005,
    .steepnessFrom = 0.0001,
    .steepnessTo = 0.00000001,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 100,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 0.00001,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "temperateGrass",
        // "temperateGrassPlentiful",
        // "temperateGrassWinter",
        // "taigaGrass",
        // "mediterraneanGrass",
        // "mediterraneanGrassPlentiful",
        // "steppeGrass",
        // "tropicalRainforestGrass",
        // "tropicalRainforestGrassPlentiful",
        // "savannaGrass",
        // "tundraGrass",
    }
};

static TerrainBaseTypeOdds desertOasisPoorDirt = {
    .terrainBaseTypeIndex = "poorDirt",
    .odds = 0.0001,
    .size = S,
    .baseAltitudeFrom = 99999,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0.0000005,
    .maxBaseAltitude = 0.000001,
    .steepnessFrom = 0.001,
    .steepnessTo = 0.00001,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 10,
    .minRiverDistance = 0.1,
    .maxRiverDistance = 10,
    .digFillOffsetFrom = 0.00001,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "mediterraneanGrass",
        // "temperateGrassPlentiful",
        // "temperateGrassWinter",
        // "taigaGrass",
        // "mediterraneanGrass",
        // "mediterraneanGrassPlentiful",
        // "steppeGrass",
        // "tropicalRainforestGrass",
        // "tropicalRainforestGrassPlentiful",
        // "savannaGrass",
        // "tundraGrass",
    }
};

static TerrainBaseTypeOdds desertOasisDirt = {
    .terrainBaseTypeIndex = "dirt",
    .odds = 0.00001,
    .size = S,
    .baseAltitudeFrom = 999999,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0000008,
    .steepnessFrom = 0.8,
    .steepnessTo = 0.0005,
    .minSteepness = 0.2,
    .maxSteepness = 2,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 0.01,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "savannaGrass",
        // "temperateGrassPlentiful",
        // "temperateGrassWinter",
        // "taigaGrass",
        // "mediterraneanGrass",
        // "mediterraneanGrassPlentiful",
        // "steppeGrass",
        // "tropicalRainforestGrass",
        // "tropicalRainforestGrassPlentiful",
        // "savannaGrass",
        // "tundraGrass",
    }
};

static TerrainBaseTypeOdds desertOasisDesertRedSand = {
    .terrainBaseTypeIndex = "desertRedSand",
    .odds = 0.2,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 0,
    .digFillOffsetTo = 100,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds desertOasisDesertSand = {
    .terrainBaseTypeIndex = "desertSand",
    .odds = 0.4,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 200,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 1.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 0,
    .digFillOffsetTo = 100,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};


static TerrainBaseTypeOdds* desertOasisTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &desertOasisLimestone,
    &desertOasisRock,
    &desertOasisRichDirt,
    &desertOasisPoorDirt,
    &desertOasisDirt,
    &desertOasisDesertSand,
    &desertOasisDesertRedSand,
};
static BiomeTerrainBaseDistribution desertOasisTerrainDistribution = {
    DesertOasis,
    9,
    desertOasisTerrainBaseTypeOdds,
};



static FloraOdds desertOasisBananaTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "bananaTree"
    },
    .level = 19,

    .odds = 0,
    .density = 3,

    .altitudeFrom = 0.32,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.0000002,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.00001,
};

static FloraOdds desertOasisCoconutTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "coconutTree"
    },
    .level = 18,

    .odds = 0,
    .density = 6,

    .altitudeFrom = 0.4,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.0000002,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.00001,
};

static FloraOdds* desertOasisFloraOdds[] = {
    &defaultRock,
    &defaultGreenRock,
    &defaultRedRock,
    &defaultAloePlant,
    &defaultMarigoldPlant,
    &defaultGingerPlant,
    &defaultTurmericPlant,
    &mesaBone,
    &defaultDeadAlpaca,
    &desertOasisBananaTree,
    &desertOasisCoconutTree
};
static FloraDistribution desertOasisFloraDistribution = {
    DesertOasis,
    11,
    desertOasisFloraOdds
};

#endif