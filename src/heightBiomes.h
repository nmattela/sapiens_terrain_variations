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

static const uint16_t unset       = UNSET;
static const uint16_t fjords      = FJORDS;
static const uint16_t mesa        = MESA;
static const uint16_t plains      = PLAINS;
static const uint16_t swamp       = SWAMP;
static const uint16_t desertOasis = DESERT_OASIS;
static const uint16_t hillsides   = HILLSIDES;

#define HEIGHT_BIOME_COUNT 7

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
    bool stop;
} BiomeOdds;

#define MATRIX_ROWS 3

static BiomeOdds *biomeMatrix[MATRIX_ROWS] = {
/* ^ equator */    (BiomeOdds[]){{ MESA  , 0.125 , false }, { DESERT_OASIS, 0.375 , false },                             { UNSET, 0.50, false }, { UNSET, 0, true } },
/* |         */    (BiomeOdds[]){{ PLAINS, 0.25  , false }, { MESA        , 0.05  , false }, { HILLSIDES, 0.20, false }, { UNSET, 0.50, false }, { UNSET, 0, true } },
/* v poles   */    (BiomeOdds[]){{ FJORDS, 0.375 , false }, { SWAMP       , 0.125 , false },                             { UNSET, 0.50, false }, { UNSET, 0, true } },
};

#endif