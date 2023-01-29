#ifndef AlpsSpec
#define AlpsSpec

#include "customBiomes.h"

static TerrainBaseTypeOdds alpsDirt = {
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
    .maxSteepness = 2,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = {
        "temperateGrass",
    }
};

static TerrainBaseTypeOdds alpsDirtSnow = {
    .terrainBaseTypeIndex = "dirt",
    .odds = 0.000001,
    .size = M,
    .baseAltitudeFrom = 0,
    .baseAltitudeTo = 1000000,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 0.6,
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
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "temperateGrass",
    }
};

static TerrainBaseTypeOdds alpsRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.0001,
    .size = M,
    .baseAltitudeFrom = 0,
    .baseAltitudeTo = 1000,
    .minBaseAltitude = 0.00005,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 1,
    .steepnessTo = 10,
    .minSteepness = 0.4,
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
    .variations = {}
};

static TerrainBaseTypeOdds alpsLimestone = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.00006,
    .size = M,
    .baseAltitudeFrom = 0,
    .baseAltitudeTo = 700,
    .minBaseAltitude = 0.00005,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 1,
    .steepnessTo = 10,
    .minSteepness = 0.4,
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
    .variations = {}
};

static TerrainBaseTypeOdds alpsClay = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.00006,
    .size = M,
    .baseAltitudeFrom = 0,
    .baseAltitudeTo = 700,
    .minBaseAltitude = 0.00005,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 2,
    .steepnessTo = 7,
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
    .variations = {}
};

static TerrainBaseTypeOdds alpsRockSnow = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.000001,
    .size = M,
    .baseAltitudeFrom = 0,
    .baseAltitudeTo = 1000000,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 10,
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
    .variationCount = 1,
    .variations = {
        "snow",
    }
};

static TerrainBaseTypeOdds* alpsTerrainBaseTypeOdds[] = {
    &alpsDirt,
    &alpsDirtSnow,
    &alpsRock,
    &alpsRockSnow,
    &alpsLimestone,
    &alpsClay,
};
static TerrainBaseDistribution alpsTerrainDistribution = {
    Alps,
    6,
    alpsTerrainBaseTypeOdds,
};

static FloraOdds alpsPine = {
    .indexCount= 4,
    .floraIndices = {
        "pine1",
        "pine2",
        "pine3",
        "pine4",
    },
    .level = 16,

    .odds = 0.0001,
    .density = 75,

    .altitudeFrom = 5000,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.0002,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 1,

    .riverDistanceFrom = 0,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds alpsPineBig = {
    .indexCount = 1,
    .floraIndices = {
        "pineBig1"
    },
    .level = 16,

    .odds = 0.00001,
    .density = 1,

    .altitudeFrom = 5000,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.0002,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 1,

    .riverDistanceFrom = 0,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds alpsMedicinalPlants = {
    .indexCount = 5,
    .floraIndices = {
        "poppyPlant",
        "echinaceaPlant",
        "marigoldPlant",
        "gingerPlant",
        "garlicPlant"
    },
    .level = 19,

    .odds = 0.0027,
    .density = 15,

    .altitudeFrom = 1,
    .altitudeTo = 100,
    .minAltitude = 0.0001,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0.1,
    .minSteepness = 0.2,
    .maxSteepness = 1,

    .riverDistanceFrom = 0,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0001,
};

static FloraOdds alpsDeadMammoth = {
    .indexCount = 1,
    .floraIndices = {
        "deadMammoth",
    },
    .level = 19,

    .odds = 0.000125,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 100,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 1,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds alpsRockObject = {
    .indexCount = 3,
    .floraIndices = {
        "rock",
        "rockSmall",
        "rockLarge",
    },
    .level = 18,

    .odds = 0.05,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 75,
    .minAltitude = 0.0001,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 7,
    .minSteepness = 0,
    .maxSteepness = 1,

    .riverDistanceFrom = 100000,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0001,
};

static FloraOdds* alpsFloraOdds[] = {
    &alpsPine,
    &alpsPineBig,
    &alpsMedicinalPlants,
    &alpsDeadMammoth,
    &alpsRockObject,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultClay,
    &defaultFlint,
    &defaultAppleTree,
    &defaultElderBerryTree,
    &defaultRaspberryBush,
    &defaultGooseberryBush,
    &defaultWheatPlant,
    &defaultFlaxPlant,
    &defaultPineBranch,
    &defaultBone,
};
static FloraDistribution alpsFloraDistribution = {
    Alps,
    17,
    alpsFloraOdds
};

double getAlpsHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance
);

static Biome AlpsBiome = {
    .type = Alps,
    .tag = "alps",
    .odds = 0.25,
    .terrainBaseDistribution = &alpsTerrainDistribution,
    .floraDistribution = &alpsFloraDistribution,
    .getHeight = getAlpsHeight,
    .subBiomesSize = 0,
    .subBiomes = {},
};

#endif