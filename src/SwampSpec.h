#ifndef SwampSpec
#define SwampSpec

#include "customBiomes.h"


static TerrainBaseTypeOdds swampLimestone = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.006,
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

static TerrainBaseTypeOdds swampClay = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.04,
    .size = S,
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

static TerrainBaseTypeOdds swampDesertSand = {
    .terrainBaseTypeIndex = "desertSand",
    .odds = 0.07,
    .size = S,
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

static TerrainBaseTypeOdds swampRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.001,
    .size = XS,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 80,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 3,
    .steepnessTo = 600,
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

static TerrainBaseTypeOdds swampRichDirt = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.3,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0001,
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
        "tropicalRainforestGrassPlentiful",
    }
};

static TerrainBaseTypeOdds swampDirt = {
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
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "tropicalRainforestGrass",
    }
};



static TerrainBaseTypeOdds* swampTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &swampLimestone,
    &swampClay,
    &swampRock,
    &swampRichDirt,
    &swampDirt
};
static TerrainBaseDistribution swampTerrainDistribution = {
    Swamp,
    7,
    swampTerrainBaseTypeOdds,
};


static FloraOdds swampWillow = {
    .indexCount = 2,
    .floraIndices = (char*[]){
        "willow1",
        "willow2"
    },
    .level = 17,

    .odds = 0.056,
    .density = 3,

    .altitudeFrom = 10,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.0000002,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};

static FloraOdds swampWillowBranch = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "willowBranch"
    },
    .level = 20,

    .odds = 0.056,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};


static FloraOdds* swampFloraOdds[] = {
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultClay,
    &defaultFlint,
    &swampWillow,
    &swampWillowBranch,
    &defaultPumpkinPlant,
    &defaultElderBerryTree,
    &defaultFlaxPlant,
    &defaultPoppyPlant,
    &defaultGooseberryBush,
    &defaultEchinaceaPlant,
    &defaultGarlicPlant,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone,
};
static FloraDistribution swampFloraDistribution = {
    Swamp,
    18,
    swampFloraOdds
};

double getSwampHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance);

static Biome SwampBiome = {
    .type = Swamp,
    .tag = "swamp",
    .odds = 0.125,
    .terrainBaseDistribution = &swampTerrainDistribution,
    .floraDistribution = &swampFloraDistribution,
    .getHeight = &getSwampHeight,
    .subBiomesSize = 0,
    .subBiomes = {},
};

#endif