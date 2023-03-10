#ifndef HillsidesSpec
#define HillsidesSpec

#include "customBiomes.h"


static TerrainBaseTypeOdds hillsidesLimestone = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.001,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 40,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 100,
    .minSteepness = 0.1,
    .maxSteepness = 1,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 10,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = { "limestone" },
};

static TerrainBaseTypeOdds hillsidesClay = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.003,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 8,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 6,
    .steepnessTo = 60,
    .minSteepness = 0.1,
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

static TerrainBaseTypeOdds hillsidesDesertSand = {
    .terrainBaseTypeIndex = "desertSand",
    .odds = 0.0005,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 200,
    .minSteepness = 0.1,
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

static TerrainBaseTypeOdds hillsidesRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.003,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 80,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 3,
    .steepnessTo = 600,
    .minSteepness = 0.1,
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

static TerrainBaseTypeOdds hillsidesRichDirt = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.26,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 0.1,
    .steepnessTo = 0.001,
    .minSteepness = 0,
    .maxSteepness = 1,
    .riverDistanceFrom = 10,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 0.00001,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = {
        "temperateGrass",
    }
};

static TerrainBaseTypeOdds hillsidesPoorDirt = {
    .terrainBaseTypeIndex = "poorDirt",
    .odds = 0.08,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 5,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 0.001,
    .minSteepness = 0,
    .maxSteepness = 1,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 10,
    .minRiverDistance = 0,
    .maxRiverDistance = 1,
    .digFillOffsetFrom = 0.00001,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = {
        "savannaGrass",
    }
};

static TerrainBaseTypeOdds hillsidesDirt = {
    .terrainBaseTypeIndex = "dirt",
    .odds = 0.4,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 0.8,
    .steepnessTo = 0.0005,
    .minSteepness = 0,
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
        "temperateGrass",
    }
};




static TerrainBaseTypeOdds* hillsidesTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &hillsidesLimestone,
    &hillsidesClay,
    &hillsidesDesertSand,
    &hillsidesRock,
    &hillsidesDirt,
    &hillsidesPoorDirt,
    &hillsidesRichDirt,
};
static TerrainBaseDistribution hillsidesTerrainDistribution = {
    Hillsides,
    9,
    hillsidesTerrainBaseTypeOdds,
};



static FloraOdds hillsidesForest = {
    .indexCount= 11,
    .floraIndices = {
        "birch1",
        "aspen1",
        "appleTree",
        "birch2",
        "aspen2",
        "orangeTree",
        "birch3",
        "aspen3",
        "peachTree",
        "birch4",
        "elderberryTree",
    },
    .level = 17,

    .odds = 0,
    .density = 35,

    .altitudeFrom = 10000,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.00001,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};


static FloraOdds* hillsidesFloraOdds[] = {
    &defaultRock,
    &defaultLimestoneRock,
    &defaultFlint,
    &defaultWheatPlant,
    &defaultFlaxPlant,
    &defaultBirchBranch,
    &hillsidesForest,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone
};
static FloraDistribution hillsidesFloraDistribution = {
    Hillsides,
    10,
    hillsidesFloraOdds
};

double getHillsidesHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance);

static Biome HillsidesBiome = {
    .type = Hillsides,
    .tag = "hillsides",
    .odds = 0.25,
    .terrainBaseDistribution = &hillsidesTerrainDistribution,
    .floraDistribution = &hillsidesFloraDistribution,
    .getHeight = &getHillsidesHeight,
    .subBiomesSize = 0,
    .subBiomes = {},
};

#endif