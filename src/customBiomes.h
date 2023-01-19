#ifndef customBiomes
#define customBiomes

#include "SPCommon.h"
#include "SPNoise.h"
#include "SPRand.h"


enum BiomeType {
    Unset,
    Fjords,
    Mesa,
    Plains,
    Swamp,
    DesertOasis,
    Hillsides,
};

#define BIOME_TYPE_COUNT 7

struct Biome;
typedef struct Biome {
    enum BiomeType type;
    double odds;
    struct Biome* subBiomes[];
} Biome;


struct BiomeBlend;
typedef struct BiomeBlend {
    enum BiomeType biome;
    double blend;
} BiomeBlend;

BiomeBlend* getBiomeForPoint(SPVec3 noiseLoc);

static Biome StopBiome = {
    .type = Unset,
    .odds = -1,
    .subBiomes = {}
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


struct BiomeTerrainBaseDistribution;
typedef struct BiomeTerrainBaseDistribution {
    uint16_t biome;
    int terrainBaseTypeOddsCount;
    TerrainBaseTypeOdds** terrainBaseTypesOdds;
} BiomeTerrainBaseDistribution;

struct FloraOdds;
typedef struct FloraOdds {
    int indexCount;
    char** floraIndices;

    int level;

    double odds;
    int density;

    double altitudeFrom;
    double altitudeTo;
    double minAltitude;
    double maxAltitude;

    double steepnessFrom;
    double steepnessTo;
    double minSteepness;
    double maxSteepness;

    double riverDistanceFrom;
    double riverDistanceTo;
    double minRiverDistance;
    double maxRiverDistance;


} FloraOdds;


struct FloraDistribution;
typedef struct FloraDistribution {
    enum BiomeType biome;
    int floraOddsCount;
    FloraOdds** floraOdds;
} FloraDistribution;


#include "customBiomesDefaults.h"

#include "UnsetSpec.h"
#include "FjordsSpec.h"
#include "MesaSpec.h"
#include "PlainsSpec.h"
#include "SwampSpec.h"
#include "DesertOasisSpec.h"
#include "HillsidesSpec.h"

#define MATRIX_ROWS 3
static Biome** biomeMatrix[MATRIX_ROWS] = {
    /* ^ equator */ (Biome*[]){ &MesaBiome  , &DesertOasisBiome, &UnsetBiome    ,              &StopBiome },
    /* |         */ (Biome*[]){ &PlainsBiome, &MesaBiomeFewer  , &HillsidesBiome, &UnsetBiome, &StopBiome },
    /* v poles   */ (Biome*[]){ &FjordsBiome, &SwampBiome      , &UnsetBiome    ,              &StopBiome }
};

#endif