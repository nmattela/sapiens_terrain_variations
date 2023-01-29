#ifndef PlainsSpec
#define PlainsSpec

#include "customBiomes.h"

static TerrainBaseTypeOdds plainsLimestone = {
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

static TerrainBaseTypeOdds plainsClay = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.006,
    .size = S,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
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

static TerrainBaseTypeOdds plainsRock = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.002,
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

static TerrainBaseTypeOdds plainsRichDirt = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.11,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 0.001,
    .steepnessTo = 0.00001,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 25,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 0.01,
    .digFillOffsetTo = 0.0001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "temperateGrassPlentiful",
    }
};

static TerrainBaseTypeOdds plainsPoorDirt = {
    .terrainBaseTypeIndex = "poorDirt",
    .odds = 0.21,
    .size = S,
    .baseAltitudeFrom = 5,
    .baseAltitudeTo = 0.7,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 0.01,
    .minSteepness = 0.2,
    .maxSteepness = 1,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 10,
    .minRiverDistance = 0,
    .maxRiverDistance = 1,
    .digFillOffsetFrom = 0.01,
    .digFillOffsetTo = 0.0001,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
        "mediterraneanGrassPlentiful",
    }
};

static TerrainBaseTypeOdds plainsDirt = {
    .terrainBaseTypeIndex = "dirt",
    .odds = 0.4,
    .size = L,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0.7,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 0.005,
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



static TerrainBaseTypeOdds* plainsTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &plainsLimestone,
    &plainsClay,
    &plainsRock,
    &plainsDirt,
    &plainsPoorDirt,
    &plainsRichDirt,
};
static TerrainBaseDistribution plainsTerrainDistribution = {
    Plains,
    8,
    plainsTerrainBaseTypeOdds,
};



static FloraOdds plainsAppleTree = {
    .indexCount = 1,
    .floraIndices = {
        "appleTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsOrangeTree = {
    .indexCount = 1,
    .floraIndices = {
        "orangeTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsPeachTree = {
    .indexCount = 1,
    .floraIndices = {
        "peachTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsElderBerryTree = {
    .indexCount = 1,
    .floraIndices = {
        "elderberryTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsForest = {
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
    .level = 16,

    .odds = 0.042,
    .density = 35,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds plainsSunflower = {
    .indexCount = 1,
    .floraIndices = {
        "sunflower"
    },
    .level = 19,

    .odds = 0.037,
    .density = 11,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,    
};



static FloraOdds* plainsFloraOdds[] = {
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultClay,
    &defaultFlint,
    &plainsForest,
    &plainsSunflower,
    &defaultRaspberryBush,
    &defaultGooseberryBush,
    &defaultBeetrootPlant,
    &defaultPumpkinPlant,
    &defaultWheatPlant,
    &defaultFlaxPlant,
    &defaultPoppyPlant,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone,
};
static FloraDistribution plainsFloraDistribution = {
    Plains,
    15,
    plainsFloraOdds
};

double getPlainsHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance);

static Biome PlainsBiome = {
    .type = Plains,
    .tag = "plains",
    .odds = 0.25,
    .terrainBaseDistribution = &plainsTerrainDistribution,
    .floraDistribution = &plainsFloraDistribution,
    .getHeight = &getPlainsHeight,
    .subBiomesSize = 0,
    .subBiomes = {},
};


#endif