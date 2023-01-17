#ifndef heightBiomes
#define heightBiomes

#include "SPCommon.h"
#include "SPNoise.h"
#include "SPRand.h"

#define UNSET  0
#define FJORDS 1
#define MESA   2
#define PLAINS 3
#define SWAMP  4
#define DESERT_OASIS 5
#define HILLSIDES 6

#define HEIGHT_BIOME_COUNT 7

static const uint16_t unset       = UNSET;
static const uint16_t fjords      = FJORDS;
static const uint16_t mesa        = MESA;
static const uint16_t plains      = PLAINS;
static const uint16_t swamp       = SWAMP;
static const uint16_t desertOasis = DESERT_OASIS;
static const uint16_t hillsides   = HILLSIDES;


struct HeightBiome;
typedef struct HeightBiome {
    uint16_t biome;
    double blend;
} HeightBiome;

HeightBiome* getHeightBiomeForPoint(SPVec3 noiseLoc);

struct BiomeOdds;
typedef struct BiomeOdds {
    uint16_t biome;
    double odds;
    double blendDistance;
    bool stop;
} BiomeOdds;

#define MATRIX_ROWS 3

static BiomeOdds *biomeMatrix[MATRIX_ROWS] = {
/* ^ equator */    (BiomeOdds[]){{ MESA  , 0.125 , 0.00004, false }, { DESERT_OASIS, 0.375 , 0.00004, false },                                      { UNSET, 0.50, 0.00004, false }, { UNSET, 0, 0, true } },
/* |         */    (BiomeOdds[]){{ PLAINS, 0.25  , 0.00004, false }, { MESA        , 0.05  , 0.00004, false }, { HILLSIDES, 0.20, 0.00004, false }, { UNSET, 0.50, 0.00004, false }, { UNSET, 0, 0, true } },
/* v poles   */    (BiomeOdds[]){{ FJORDS, 0.375 , 0.00004, false }, { SWAMP       , 0.125 , 0.00004, false },                                      { UNSET, 0.50, 0.00004, false }, { UNSET, 0, 0, true } },
};

#define TERRAIN_BASE_TYPE_INDEX_COUNT 13

static char* terrainBaseTypeIndices[TERRAIN_BASE_TYPE_INDEX_COUNT] = {
    "rock",
    "limestone",
    "beachSand",
    "riverSand",
    "desertSand",
    "ice",
    "desertRedSand",
    "redRock",
    "greenRock",
    "dirt",
    "richDirt",
    "poorDirt",
    "clay"
};

#define TERRAIN_VARIATION_TYPE_INDEX_COUNT 18

static char* terrainVariationTypeIndices[TERRAIN_VARIATION_TYPE_INDEX_COUNT] = {
    "snow",
    "grassSnow",
    "temperateGrass",
    "temperateGrassPlentiful",
    "temperateGrassWinter",
    "taigaGrass",
    "mediterraneanGrass",
    "mediterraneanGrassPlentiful",
    "steppeGrass",
    "tropicalRainforestGrass",
    "tropicalRainforestGrassPlentiful",
    "savannaGrass",
    "tundraGrass",
    "limestone",
    "redRock",
    "greenRock",
    "flint",
    "clay"
};

#define GRASS_VARIATIONS_COUNT 11

static char* grassVariations[GRASS_VARIATIONS_COUNT] = {
    "temperateGrass",
    "temperateGrassPlentiful",
    "temperateGrassWinter",
    "taigaGrass",
    "mediterraneanGrass",
    "mediterraneanGrassPlentiful",
    "steppeGrass",
    "tropicalRainforestGrass",
    "tropicalRainforestGrassPlentiful",
    "savannaGrass",
    "tundraGrass",
};

enum Size { XS, S, M, L, XL };

struct TerrainBaseTypeOdds;
typedef struct TerrainBaseTypeOdds {
    char* terrainBaseTypeIndex;
    // Absolute percentage (0, 1) chance of spawning this terrain type
    double odds;

    // How large your patches are allowed to be. E.g. a rare item should have a small patch. Common items can take something like medium, that's the default
    enum Size size;

    // (0, +infinity) value that indicates if the odds should increase or decrease as the base altitude increases
    // It will proportionally increase/decrease as the slope steepens
    // 1 is default, i.e. slopes have no effect on spawning this terrain type
    // minimum base altitude for the baseAltitudeModifier to take effect
    double baseAltitudeFrom;
    double baseAltitudeTo;
    double minBaseAltitude;
    // maximum base altitude for the baseAltitudeModifier to take effect
    double maxBaseAltitude;
    // Same but for steepness
    double minSteepness;
    double steepnessFrom;
    double steepnessTo;
    double maxSteepness;
    // Same but for river distance
    double minRiverDistance;
    double riverDistanceFrom;
    double riverDistanceTo;
    double maxRiverDistance;
    // digFillOffset is a value that says how deep/high we dug/filled (-infinity to infinity, 0 is surface level). So, this modifier determines if this terrain base type has a higher or lower chance to spawn below the surface
    double minDigFillOffset;
    double digFillOffsetFrom;
    double digFillOffsetTo;
    double maxDigFillOffset;

    int variationCount;
    // Array of possible variation indices this terrain base type may have
    char* variations[];
} TerrainBaseTypeOdds;

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

//--------------//
//--- FJORDS ---//
//--------------//

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

//------------------//
//--- END FJORDS ---//
//------------------//

//------------//
//--- MESA ---//
//------------//

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
    .variationCount = 3,
    .variations = {
        "snow",
        "grassSnow",
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
    .variationCount = 2,
    .variations = {
        "snow",
        "grassSnow",
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
    .variationCount = 2,
    .variations = {
        "snow",
        "grassSnow",
    }
};

//----------------//
//--- END MESA ---//
//----------------//

//--------------//
//--- PLAINS ---//
//--------------//

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

//------------------//
//--- END PLAINS ---//
//------------------//

//-------------//
//--- SWAMP ---//
//-------------//

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

//-----------------//
//--- END SWAMP ---//
//-----------------//

//--------------------//
//--- DESERT OASIS ---//
//--------------------//

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
    .odds = 0.0001,
    .size = S,
    .baseAltitudeFrom = 99999999,
    .baseAltitudeTo = 0,
    .minBaseAltitude = -0.00001,
    .maxBaseAltitude = 0.000002,
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
    .odds = 0.08,
    .size = S,
    .baseAltitudeFrom = 5,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0.0001,
    .maxBaseAltitude = 0.001,
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

static TerrainBaseTypeOdds desertOasisDirt = {
    .terrainBaseTypeIndex = "dirt",
    .odds = 0.009,
    .size = S,
    .baseAltitudeFrom = 666666,
    .baseAltitudeTo = 0,
    .minBaseAltitude = 0.0000007,
    .maxBaseAltitude = 0.0000025,
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

static TerrainBaseTypeOdds desertOasisDesertRedSand = {
    .terrainBaseTypeIndex = "desertRedSand",
    .odds = 0.3,
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
    .odds = 0.2,
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


//------------------------//
//--- END DESERT OASIS ---//
//------------------------//

//-----------------//
//--- HILLSIDES ---//
//-----------------//

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

//---------------------//
//--- END HILLSIDES ---//
//---------------------//

struct BiomeTerrainBaseDistribution;
typedef struct BiomeTerrainBaseDistribution {
    uint16_t biome;
    int terrainBaseTypeOddsCount;
    TerrainBaseTypeOdds** terrainBaseTypesOdds;
} BiomeTerrainBaseDistribution;

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
static BiomeTerrainBaseDistribution defaultTerrainDistribution = {
    unset,
    9,
    defaultTerrainBaseTypeOdds,
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
static BiomeTerrainBaseDistribution fjordsTerrainDistribution = {
    fjords,
    9,
    fjordsTerrainBaseTypeOdds,
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
static BiomeTerrainBaseDistribution mesaTerrainDistribution = {
    mesa,
    10,
    mesaTerrainBaseTypeOdds,
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
static BiomeTerrainBaseDistribution plainsTerrainDistribution = {
    plains,
    8,
    plainsTerrainBaseTypeOdds,
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
static BiomeTerrainBaseDistribution swampTerrainDistribution = {
    swamp,
    7,
    swampTerrainBaseTypeOdds,
};

static TerrainBaseTypeOdds* desertOasisTerrainBaseTypeOdds[] = {
    &redRockDefault,
    &greenRockDefault,
    &desertOasisLimestone,
    &desertOasisRock,
    &desertOasisRichDirt,
    &desertOasisPoorDirt,
    &desertOasisDirt,
    &desertOasisDesertRedSand,
    &desertOasisDesertSand,
};
static BiomeTerrainBaseDistribution desertOasisTerrainDistribution = {
    desertOasis,
    9,
    desertOasisTerrainBaseTypeOdds,
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
static BiomeTerrainBaseDistribution hillsidesTerrainDistribution = {
    hillsides,
    9,
    hillsidesTerrainBaseTypeOdds,
};

struct CalculatedOdds;
typedef struct CalculatedOdds {
    double odds;
    double oddsSmall;
    double oddsMed;
    double oddsLarge;
} CalculatedOdds;

#endif