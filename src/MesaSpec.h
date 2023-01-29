#ifndef MesaSpec
#define MesaSpec

#include "customBiomes.h"

static TerrainBaseTypeOdds mesaLimestone = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.001,
    .size = S,
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

static TerrainBaseTypeOdds mesaClay = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.05,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 8,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 6,
    .steepnessTo = 60,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = { "clay" }
};

static TerrainBaseTypeOdds mesaDesertSand = {
    .terrainBaseTypeIndex = "desertSand",
    .odds = 0.09,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 10,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 1,
    .riverDistanceFrom = 1.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds mesaDesertRedSand = {
    .terrainBaseTypeIndex = "desertRedSand",
    .odds = 0.03,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 3,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds mesaRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.01,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 80,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 3,
    .steepnessTo = 260,
    .minSteepness = 0.05,
    .maxSteepness = 1,
    .riverDistanceFrom = 40,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.002,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100000,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds mesaRichDirt = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.001,
    .size = XS,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 0.0001,
    .steepnessTo = 0.00000001,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 30,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.00035,
    .digFillOffsetFrom = 0.00001,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = {
        "savannaGrass",
    }
};

static TerrainBaseTypeOdds mesaPoorDirt = {
    .terrainBaseTypeIndex = "poorDirt",
    .odds = 0.4,
    .size = L,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 0.0001,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 0.1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0.1,
    .maxRiverDistance = 1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {
    }
};

static TerrainBaseTypeOdds mesaDirt = {
    .terrainBaseTypeIndex = "dirt",
    .odds = 0.009,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 0.8,
    .steepnessTo = 0.0005,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {
    }
};



static TerrainBaseTypeOdds* mesaTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &mesaDesertSand,
    &mesaDesertRedSand,
    &mesaRock,
    &mesaClay,
    &mesaLimestone,
    &mesaRichDirt,
    &mesaPoorDirt,
    &mesaDirt,
};
static TerrainBaseDistribution mesaTerrainDistribution = {
    Mesa,
    10,
    mesaTerrainBaseTypeOdds,
};

static FloraOdds mesaRockPebble = {
    .indexCount = 3,
    .floraIndices = {
        "rock",
        "rockSmall",
        "rockLarge",
    },
    .level = 19,

    .odds = 0.05,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 20,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaRedRock = {
    .indexCount = 3,
    .floraIndices = {
        "redRock",
        "redRockSmall",
        "redRockLarge",
    },
    .level = 18,

    .odds = 0.017,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 5,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 8,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaGreenRock = {
    .indexCount = 3,
    .floraIndices = {
        "greenRock",
        "greenRockSmall",
        "greenRockLarge",
    },
    .level = 18,

    .odds = 0.021,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 12,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaLimestoneRock = {
    .indexCount = 3,
    .floraIndices = {
        "limestoneRock",
        "limestoneRockSmall",
        "limestoneRockLarge",
    },
    .level = 19,

    .odds = 0.04,
    .density = 6,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 15,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaFlint = {
    .indexCount = 1,
    .floraIndices = {
        "flint",
    },
    .level = 20,

    .odds = 0.09,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaClayBall = {
    .indexCount = 1,
    .floraIndices = {
        "clay",
    },
    .level = 19,

    .odds = 0.05,
    .density = 4,

    .altitudeFrom = 1,
    .altitudeTo = 0.7,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaBone = {
    .indexCount = 1,
    .floraIndices = {
        "bone",
    },
    .level = 19,

    .odds = 0.0075,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 1,
    .maxAltitude = 1,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds* mesaFloraOdds[] = {
    &mesaRockPebble,
    &mesaRedRock,
    &mesaGreenRock,
    &mesaLimestoneRock,
    &mesaFlint,
    &mesaClayBall,
    &defaultDeadAlpaca,
    &mesaBone,
    &defaultGingerPlant,
    &defaultAloePlant,
    &defaultMarigoldPlant,
    &defaultTurmericPlant,
    &defaultPineBranch,
};
static FloraDistribution mesaFloraDistribution = {
    Mesa,
    13,
    mesaFloraOdds
};

double getMesaHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance);

double getMonumentValleyHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance
);

static Biome MonumentValleyBiome = {
    .type = MonumentValley,
    .tag = "monumentValley",
    .odds = 0.5,
    .terrainBaseDistribution = &mesaTerrainDistribution,
    .floraDistribution = &mesaFloraDistribution,
    .getHeight = &getMonumentValleyHeight,
    .subBiomesSize = 0,
    .subBiomes = {}
};

static Biome MesaBiome = {
    .type = Mesa,
    .tag = "mesa",
    .odds = 0.125,
    .terrainBaseDistribution = &mesaTerrainDistribution,
    .floraDistribution = &mesaFloraDistribution,
    .getHeight = &getMesaHeight,
    .subBiomesSize = 0,
    .subBiomes = {}
};


static Biome MesaBiomeFewer = {
    .type = Mesa,
    .tag = "mesa",
    .odds = 0.125,
    .terrainBaseDistribution = &mesaTerrainDistribution,
    .floraDistribution = &mesaFloraDistribution,
    .getHeight = &getMesaHeight,
    .subBiomesSize = 0,
    .subBiomes = {}
};

#endif