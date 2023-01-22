#ifndef UnsetSpec
#define UnsetSpec

#include "customBiomes.h"

static Biome UnsetBiome = {
    .type = Unset,
    .odds = 0.5,
    .subBiomesSize = 0,
    .subBiomes = {},
};

#endif