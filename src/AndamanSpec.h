#ifndef AndamanSpec
#define AndamanSpec

#include "customBiomes.h"

static TerrainBaseTypeOdds andamanRichDirt = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.006,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 5,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 1,
    .steepnessTo = 0.001,
    .minSteepness = 0.4,
    .maxSteepness = 1,
    .riverDistanceFrom = 700,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.2,
    .digFillOffsetFrom = 0.00001,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = {
        "temperateGrassPlentiful",
    }
};

static TerrainBaseTypeOdds andamanBeachSand = {
    .terrainBaseTypeIndex = "beachSand",
    .odds = 0.000001,
    .size = S,
    .baseAltitudeFrom = 1000000,
    .baseAltitudeTo = 0,
    .minBaseAltitude = -0.0001,
    .maxBaseAltitude = 0.000003,
    .steepnessFrom = 100,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0.6,
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

static TerrainBaseTypeOdds andamanRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.004,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 100,
    .minSteepness = 0.4,
    .maxSteepness = 1,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100000,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds andamanClay = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.0015,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 40,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 0.00001,
    .minSteepness = 0.4,
    .maxSteepness = 1,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100000,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds andamanLimestone = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.0003,
    .size = XS,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 10,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 120,
    .minSteepness = 0.4,
    .maxSteepness = 1,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 100000,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds* andamanTerrainBaseTypeOdds[] = {
    &andamanBeachSand,
    &andamanRichDirt,
    &andamanRock,
    &andamanClay,
    &andamanLimestone,
    &dirtDefault,
};
static TerrainBaseDistribution andamanTerrainDistribution = {
    Andaman,
    6,
    andamanTerrainBaseTypeOdds,
};

static FloraOdds andamanBananaTree = {
    .indexCount = 1,
    .floraIndices = {
        "bananaTree"
    },
    .level = 17,

    .odds = 0.03,
    .density = 25,

    .altitudeFrom = 0.1,
    .altitudeTo = 100,
    .minAltitude = 0,
    .maxAltitude = 0.0001,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0.4,
    .maxSteepness = 1,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.00001,
};

static FloraOdds andamanCoconutTree = {
    .indexCount = 1,
    .floraIndices = {
        "coconutTree"
    },
    .level = 17,

    .odds = 0.02,
    .density = 35,

    .altitudeFrom = 0.1,
    .altitudeTo = 130,
    .minAltitude = 0,
    .maxAltitude = 0.0001,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0.4,
    .maxSteepness = 1,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.00001,
};

static FloraOdds andamanAspen = {
    .indexCount= 3,
    .floraIndices = {
        "aspen1",
        "aspen2",
        "aspen3"
    },
    .level = 16,

    .odds = 0.01,
    .density = 6,

    .altitudeFrom = 1,
    .altitudeTo = 100,
    .minAltitude = 0,
    .maxAltitude = 0.0001,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0.4,
    .maxSteepness = 1,

    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds andamanRockObject = {
    .indexCount = 3,
    .floraIndices = {
        "rock",
        "rockSmall",
        "rockLarge",
    },
    .level = 18,

    .odds = 0.002,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 10,
    .minAltitude = 0,
    .maxAltitude = 0.0001,

    .steepnessFrom = 1,
    .steepnessTo = 100,
    .minSteepness = 0,
    .maxSteepness = 1,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds andamanGreenRockObject = {
    .indexCount = 3,
    .floraIndices = {
        "greenRock",
        "greenRockSmall",
        "greenRockLarge",
    },
    .level = 18,

    .odds = 0.00001,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.0001,

    .steepnessFrom = 1,
    .steepnessTo = 1000,
    .minSteepness = 0,
    .maxSteepness = 1,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds* andamanFloraOdds[] = {
    &andamanAspen,
    &andamanBananaTree,
    &andamanCoconutTree,
    &andamanRockObject,
    &andamanGreenRockObject,
    &defaultAloePlant,
    &defaultGingerPlant,
    &defaultMarigoldPlant,
    &defaultTurmericPlant,
    &defaultEchinaceaPlant,
    &defaultFlaxPlant,
    &defaultWheatPlant,
    &defaultDeadAlpaca,
    &defaultPineBranch
};
static FloraDistribution andamanFloraDistribution = {
    Andaman,
    14,
    andamanFloraOdds
};

double getAndamanHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance
);

static Biome AndamanBiome = {
    .type = Andaman,
    .tag = "andaman",
    .odds = 0.375,
    .terrainBaseDistribution = &andamanTerrainDistribution,
    .floraDistribution = &andamanFloraDistribution,
    .getHeight = getAndamanHeight,
    .subBiomesSize = 0,
    .subBiomes = {},
};

#endif