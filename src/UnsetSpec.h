#ifndef UnsetSpec
#define UnsetSpec

#include "customBiomes.h"

static Biome UnsetBiome = {
    .type = Unset,
    .tag = "unset",
    .odds = 0.5,
    .subBiomesSize = 0,
    .subBiomes = {},
};

static Biome UnsetBiomeFewer = {
    .type = Unset,
    .tag = "unset",
    .odds = 0.25,
    .subBiomesSize = 0,
    .subBiomes = {},
};

#endif