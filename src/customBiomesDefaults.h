#ifndef customBiomesDefaults
#define customBiomesDefaults

#include "customBiomes.h"

static TerrainBaseTypeOdds redRockDefault = {
    .terrainBaseTypeIndex = "redRock",
    .odds = 0.00007,//0.0004,
    .size = XS,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 8,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 100,
    .minSteepness = 0,
    .maxSteepness = 1,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 1.2,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = { "redRock" },
};

static TerrainBaseTypeOdds greenRockDefault = {
    .terrainBaseTypeIndex = "greenRock",
    .odds = 0.00005,
    .size = XS,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 8,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 100,
    .minSteepness = 0,
    .maxSteepness = 1,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.1,
    .digFillOffsetFrom = 1,
    .digFillOffsetTo = 1.2,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 1,
    .variations = { "greenRock" },
};

static TerrainBaseTypeOdds limestoneDefault = {
    .terrainBaseTypeIndex = "limestone",
    .odds = 0.001,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 40,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 100,
    .minSteepness = 0.2,
    .maxSteepness = 2,
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

static TerrainBaseTypeOdds clayDefault = {
    .terrainBaseTypeIndex = "clay",
    .odds = 0.005,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 8,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 6,
    .steepnessTo = 60,
    .minSteepness = 0.2,
    .maxSteepness = 2,
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

static TerrainBaseTypeOdds desertSandDefault = {
    .terrainBaseTypeIndex = "desertSand",
    .odds = 0.009,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 2,
    .steepnessTo = 200,
    .minSteepness = 0.2,
    .maxSteepness = 2,
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

static TerrainBaseTypeOdds rockDefault = {
    .terrainBaseTypeIndex = "rock",
    .odds = 0.006,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 80,
    .minBaseAltitude = 0.00001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 3,
    .steepnessTo = 600,
    .minSteepness = 0.2,
    .maxSteepness = 2,
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

static TerrainBaseTypeOdds richDirtDefault = {
    .terrainBaseTypeIndex = "richDirt",
    .odds = 0.003,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.0001,
    .steepnessFrom = 0.0001,
    .steepnessTo = 0.00000001,
    .minSteepness = 0.2,
    .maxSteepness = 2,
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

static TerrainBaseTypeOdds poorDirtDefault = {
    .terrainBaseTypeIndex = "poorDirt",
    .odds = 0.004,
    .size = M,
    .baseAltitudeFrom = 5,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 0.001,
    .steepnessTo = 0.00001,
    .minSteepness = 0.2,
    .maxSteepness = 2,
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

static TerrainBaseTypeOdds dirtDefault = {
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



static TerrainBaseTypeOdds beachSandDefault = {
    .terrainBaseTypeIndex = "beachSand",
    .odds = 1.0,
    .size = M,
    .baseAltitudeFrom = 0,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 2,
    .riverDistanceFrom = 0,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 0,
    .digFillOffsetTo = 0,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};

static TerrainBaseTypeOdds riverSandDefault = {
    .terrainBaseTypeIndex = "riverSand",
    .odds = 1.0,
    .size = M,
    .baseAltitudeFrom = 0,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 2,
    .riverDistanceFrom = 1,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
    .digFillOffsetFrom = 0,
    .digFillOffsetTo = 0,
    .minDigFillOffset = -0.2,
    .maxDigFillOffset = -INFINITY,
    .variationCount = 0,
    .variations = {  },
};


static TerrainBaseTypeOdds desertRedSandDefault = {
    .terrainBaseTypeIndex = "desertRedSand",
    .odds = 0.1,
    .size = M,
    .baseAltitudeFrom = 1,
    .baseAltitudeTo = 1,
    .minBaseAltitude = 0,
    .maxBaseAltitude = 0.001,
    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0.2,
    .maxSteepness = 2,
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



static TerrainBaseTypeOdds* defaultTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &limestoneDefault,
    &clayDefault,
    &desertSandDefault,
    &rockDefault,
    &richDirtDefault,
    &poorDirtDefault,
    &dirtDefault,
};
static TerrainBaseDistribution defaultTerrainDistribution = {
    Unset,
    9,
    defaultTerrainBaseTypeOdds,
};

static FloraOdds defaultPineBig = {
    .indexCount = 1,
    .floraIndices = {
        "pineBig1"
    },
    .level = 15,

    .odds = 0.0625,
    .density = 1,

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
    .maxRiverDistance = 0,
};

static FloraOdds defaultAspenBig = {
    .indexCount = 1,
    .floraIndices = {
        "aspenBig1"
    },
    .level = 15,

    .odds = 0.0625,
    .density = 1,

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
    .maxRiverDistance = 0,
};

static FloraOdds defaultWillow = {
    .indexCount = 2,
    .floraIndices = {
        "willow1",
        "willow2"
    },
    .level = 16,

    .odds = 0,
    .density = 3,

    .altitudeFrom = 0,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0.05,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};

static FloraOdds defaultRock = {
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
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultRedRock = {
    .indexCount = 3,
    .floraIndices = {
        "redRock",
        "redRockSmall",
        "redRockLarge",
    },
    .level = 18,

    .odds = 0.0003,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 5,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultGreenRock = {
    .indexCount = 3,
    .floraIndices = {
        "greenRock",
        "greenRockSmall",
        "greenRockLarge",
    },
    .level = 18,

    .odds = 0.0001,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultLimestoneRock = {
    .indexCount = 3,
    .floraIndices = {
        "limestoneRock",
        "limestoneRockSmall",
        "limestoneRockLarge",
    },
    .level = 18,

    .odds = 0.02,
    .density = 6,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultFlint = {
    .indexCount = 1,
    .floraIndices = {
        "flint",
    },
    .level = 18,

    .odds = 0.02,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultClay = {
    .indexCount = 1,
    .floraIndices = {
        "clay",
    },
    .level = 18,

    .odds = 0.03,
    .density = 4,

    .altitudeFrom = 1,
    .altitudeTo = 0.7,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultBirchBranch = {
    .indexCount = 1,
    .floraIndices = {
        "birchBranch",
    },
    .level = 20,

    .odds = 0.003,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 0.3,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultPineBranch = {
    .indexCount = 1,
    .floraIndices = {
        "pineBranch",
    },
    .level = 20,

    .odds = 0.003,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 0.3,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultWillowBranch = {
    .indexCount = 1,
    .floraIndices = {
        "willowBranch"
    },
    .level = 20,

    .odds = 0,
    .density = 2,

    .altitudeFrom = 0,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0.003,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};

static FloraOdds defaultBambooBranch = {
    .indexCount = 1,
    .floraIndices = {
        "bambooBranch",
    },
    .level = 20,

    .odds = 0.003,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 0.3,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultDeadAlpaca = {
    .indexCount = 1,
    .floraIndices = {
        "deadAlpaca",
    },
    .level = 19,

    .odds = 0.00075,
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

static FloraOdds defaultDeadMammoth = {
    .indexCount = 1,
    .floraIndices = {
        "deadMammoth",
    },
    .level = 19,

    .odds = 0.000125,
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

static FloraOdds defaultBone = {
    .indexCount = 1,
    .floraIndices = {
        "bone",
    },
    .level = 19,

    .odds = 0.00075,
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

static FloraOdds defaultRaspberryBush = {
    .indexCount = 1,
    .floraIndices = {
        "raspberryBush",
    },
    .level = 19,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultGooseberryBush = {
    .indexCount = 1,
    .floraIndices = {
        "gooseberryBush",
    },
    .level = 19,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultAppleTree = {
    .indexCount = 1,
    .floraIndices = {
        "appleTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultOrangeTree = {
    .indexCount = 1,
    .floraIndices = {
        "orangeTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultPeachTree = {
    .indexCount = 1,
    .floraIndices = {
        "peachTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultBananaTree = {
    .indexCount = 1,
    .floraIndices = {
        "bananaTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultCoconutTree = {
    .indexCount = 1,
    .floraIndices = {
        "coconutTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultElderBerryTree = {
    .indexCount = 1,
    .floraIndices = {
        "elderberryTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

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

static FloraOdds defaultBeetrootPlant = {
    .indexCount = 1,
    .floraIndices = {
        "beetrootPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.8,
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

static FloraOdds defaultPumpkinPlant = {
    .indexCount = 1,
    .floraIndices = {
        "pumpkinPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 0.4,
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

static FloraOdds defaultWheatPlant = {
    .indexCount = 1,
    .floraIndices = {
        "wheatPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 0.4,
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

static FloraOdds defaultFlaxPlant = {
    .indexCount = 1,
    .floraIndices = {
        "flaxPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 0.4,
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

static FloraOdds defaultPoppyPlant = {
    .indexCount = 1,
    .floraIndices = {
        "poppyPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.8,
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

static FloraOdds defaultGarlicPlant = {
    .indexCount = 1,
    .floraIndices = {
        "garlicPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultAloePlant = {
    .indexCount = 1,
    .floraIndices = {
        "aloePlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultEchinaceaPlant = {
    .indexCount = 1,
    .floraIndices = {
        "echinaceaPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultMarigoldPlant = {
    .indexCount = 1,
    .floraIndices = {
        "marigoldPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultGingerPlant = {
    .indexCount = 1,
    .floraIndices = {
        "gingerPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultTurmericPlant = {
    .indexCount = 1,
    .floraIndices = {
        "turmericPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds* defaultFloraOdds[] = {
    &defaultPineBig,
    &defaultAspenBig,
    &defaultWillow,
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultFlint,
    &defaultBirchBranch,
    &defaultPineBranch,
    &defaultWillowBranch,
    &defaultBambooBranch,
    &defaultClay,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone,
};
static FloraDistribution defaultFloraDistribution = {
    Unset,
    16,
    defaultFloraOdds
};

#endif