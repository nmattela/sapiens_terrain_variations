#ifndef FjordsSpec
#define FjordsSpec

#include "customBiomes.h"


static TerrainBaseTypeOdds fjordsLimestone = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.0012,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 40,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 200,
    .minSteepness = 0.15,
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

static TerrainBaseTypeOdds fjordsClay = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.001,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 8,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 120,
    .minSteepness = 0.15,
    .maxSteepness = 1,
    .riverDistanceFrom = 20,
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

static TerrainBaseTypeOdds fjordsDesertSand = {
    .terrainBaseTypeIndex = "desertSand",
    .odds = 0.001,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 100,
    .minSteepness = 0.15,
    .maxSteepness = 1,
    .riverDistanceFrom = 14,
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

static TerrainBaseTypeOdds fjordsRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.004,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 80,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 3,
    .steepnessTo = 160,
    .minSteepness = 0.15,
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

static TerrainBaseTypeOdds fjordsRichDirt = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.006,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 0.01,
    .steepnessTo = 0.00001,
    .minSteepness = 0.15,
    .maxSteepness = 1,
    .riverDistanceFrom = 700,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.2,
    .digFillOffsetFrom = 0.00001,
    .digFillOffsetTo = 0.00001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "temperateGrassPlentiful",
    }
};

static TerrainBaseTypeOdds fjordsPoorDirt = {
    .terrainBaseTypeIndex = "poorDirt",
    .odds = 0.14,
    .size = M,
    .baseAltitudeFrom = 5,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 0.01,
    .steepnessTo = 0.00001,
    .minSteepness = 0.15,
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
        "savannaGrass",
    }
};

static TerrainBaseTypeOdds fjordsDirt = {
    .terrainBaseTypeIndex = "dirt",
    .odds = 0.2,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 0.4,
    .steepnessTo = 0.0001,
    .minSteepness = 0.15,
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

static TerrainBaseTypeOdds* fjordsTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &fjordsRock,
    &fjordsLimestone,
    &fjordsClay,
    &fjordsDesertSand,
    &fjordsRichDirt,
    &fjordsPoorDirt,
    &fjordsDirt,
};
static TerrainBaseDistribution fjordsTerrainDistribution = {
    Fjords,
    9,
    fjordsTerrainBaseTypeOdds,
};


static FloraOdds fjordsWheatPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "wheatPlant",
    },
    .level = 19,

    .odds = 0.0024,
    .density = 5,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1.7,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds fjordsFlaxPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "flaxPlant",
    },
    .level = 19,

    .odds = 0.0024,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1.7,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds fjordsAspen = {
    .indexCount= 3,
    .floraIndices = (char*[]){
        "aspen1",
        "aspen2",
        "aspen3"
    },
    .level = 16,

    .odds = 0.15,
    .density = 6,

    .altitudeFrom = 0.7,
    .altitudeTo = 2.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds fjordsPine = {
    .indexCount= 4,
    .floraIndices = (char*[]){
        "pine1",
        "pine2",
        "pine3",
        "pine4",
    },
    .level = 17,

    .odds = 0.25,
    .density = 20,

    .altitudeFrom = 1,
    .altitudeTo = 0.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 30,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds* fjordsFloraOdds[] = {
    &defaultPineBig,
    &defaultAspenBig,
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultFlint,
    &defaultPineBranch,
    &defaultClay,
    &defaultDeadMammoth,
    &defaultBone,
    &defaultAppleTree,
    &defaultElderBerryTree,
    &defaultRaspberryBush,
    &defaultGooseberryBush,
    &fjordsWheatPlant,
    &fjordsFlaxPlant,
    &defaultPoppyPlant,
    &defaultGarlicPlant,
    &fjordsAspen,
    &fjordsPine,
};
static FloraDistribution fjordsFloraDistribution = {
    Fjords,
    21,
    fjordsFloraOdds
};

double getFjordsHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance
);

static Biome FjordsBiome = {
    .type = Fjords,
    .odds = 0.375,
    .terrainBaseDistribution = &fjordsTerrainDistribution,
    .floraDistribution = &fjordsFloraDistribution,
    .getHeight = getFjordsHeight,
    .subBiomesSize = 0,
    .subBiomes = {},
};

#endif