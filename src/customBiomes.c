#include "customBiomes.h"
#include "SPLog.h"
#include "utils.h"
#include "FastNoiseLite.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

BiomeThreshold* calculateOddsThresholds(Biome** biomeRow, int biomeRowSize) {
    BiomeThreshold* oddsThresholds = malloc(sizeof(BiomeThreshold) * (biomeRowSize));
    double threshold = 1;
    for(int i = 0; i < biomeRowSize; i++) {
        Biome* biome = biomeRow[i];
        threshold -= biome->odds;
        BiomeThreshold oddsThreshold = {
            .biome = biome,
            .threshold = threshold,
        };
        oddsThresholds[i] = oddsThreshold;
    }

    

    return oddsThresholds;
}

Biome* recursivelyFindBiome(BiomeThreshold* oddsThresholds, int oddsThresholdsSize, double biomeNoise) {
    BiomeThreshold biomeOfChoice;
    bool found = false;
    for(int i = 0; i < oddsThresholdsSize; i++) {
        BiomeThreshold oddsThreshold = oddsThresholds[i];
        if(biomeNoise >= oddsThreshold.threshold && (!found || biomeNoise < biomeOfChoice.threshold)) {
            biomeOfChoice = oddsThreshold;
            found = true;
        }
    }

    if(!found) {
        return NULL;
    } else if(biomeOfChoice.biome->subBiomesSize > 0) {
        double oddsFrom = biomeOfChoice.threshold;
        double oddsTo   = biomeOfChoice.threshold + biomeOfChoice.biome->odds;

        double newNoise = rangeMap(oddsFrom, oddsTo, 0, 1, biomeNoise);

        BiomeThreshold* newOddsThresholds = calculateOddsThresholds(biomeOfChoice.biome->subBiomes, biomeOfChoice.biome->subBiomesSize);

        Biome* recurseResult = recursivelyFindBiome(newOddsThresholds, biomeOfChoice.biome->subBiomesSize, newNoise);

        //free(newOddsThresholds);

        if(recurseResult == NULL) {
            return biomeOfChoice.biome;
        } else {
            return recurseResult;
        }

    } else {
        return biomeOfChoice.biome;
    }
}

Biome** biomeMatrix[MATRIX_ROWS];
bool isInitialized = false;
void customBiomesInit() {

	/* ^ equator */ static Biome* latitude1[] = { &MesaBiome     , &DesertOasisBiome,                &UnsetBiome     , &StopBiome };
    /* |         */ static Biome* latitude2[] = { &MesaBiomeFewer, &PlainsBiome     , &AndamanBiome, &UnsetBiomeFewer, &StopBiome };
	/* |         */ static Biome* latitude3[] = { &PlainsBiome   , &HillsidesBiome  , &AlpsBiome   , &UnsetBiomeFewer, &StopBiome };
	/* v poles   */ static Biome* latitude4[] = { &FjordsBiome   , &SwampBiome      ,                &UnsetBiome     , &StopBiome };

    static Biome** latitudes[MATRIX_ROWS] = {
        latitude1,
        latitude2,
        latitude3,
        latitude4,
    };

    memcpy(biomeMatrix, latitudes, sizeof(latitudes));

    isInitialized = true;
}


/**
 * 
 * This is my own function and implements an "overlay" over the default biomes to add custom height-dependent biomes (e.g. badlands, fjords)
 * My mod is able to call this function and know what biome is at this particular place so that it can properly set the height
 * 
 * @param noiseLoc location on the map to sample biome at
 * 
 * @returns an array of structs containing the biome as well as the blending strength of that biome for the given point.
 * If the point is not close to the edge of a biome, you can expect a single value in the array.
 * If it is close to the edge, then it returns all biomes in a proximity of 0.00001 from the sampled point
 * 
*/

BiomeBlend* getBiomeForPoint(SPVec3 noiseLoc) {

    if(!isInitialized) {
        customBiomesInit();
    }

    // // DEBUG
    // BiomeBlend* debug = malloc(sizeof(BiomeBlend)*2);
    // debug[0] = (BiomeBlend){ 1, 0, &UnsetBiome };
    // debug[1] = (BiomeBlend){ 0, 1, &AlpsBiome };
    // return debug;
    // // DEBUG

    // We do not use the vanilla perlin noise. Instead we use a verenoi noise provided to us by the FastNoiseLite library to generate our biomes
    fnl_state biomeNoiseGenerator = fnlCreateState();
    biomeNoiseGenerator.noise_type = FNL_NOISE_CELLULAR;
    biomeNoiseGenerator.frequency = 500;
    biomeNoiseGenerator.octaves = 6;
    biomeNoiseGenerator.cellular_return_type = FNL_CELLULAR_RETURN_VALUE_CELLVALUE;
    biomeNoiseGenerator.cellular_distance_func = FNL_CELLULAR_DISTANCE_HYBRID;

    // We instantiate another verenoi noise, but this one will be used to calculate the biome blend (it returns a value close to 0 if it is close to a biome edge, and close to 1 if it is in the center of a biome)
    fnl_state blendingNoiseGenerator = fnlCreateState();
    blendingNoiseGenerator.noise_type = FNL_NOISE_CELLULAR;
    blendingNoiseGenerator.frequency = 500;
    blendingNoiseGenerator.octaves = 6;
    blendingNoiseGenerator.cellular_return_type = FNL_CELLULAR_RETURN_VALUE_DISTANCE2DIV;
    blendingNoiseGenerator.cellular_distance_func = FNL_CELLULAR_DISTANCE_HYBRID;

    // A value ranging from 0 to 1 indicating how far off we are from the equator (on both halves of the planet). 0 = at equatior. 1 = at the poles.
    // We use this value to index biomeMatrix with, which will return us an array of biomes that are allowed to exist on this part of the world along with their percentual chance expressed as a double
    double latitude = noiseLoc.y - 1.2;
    latitude = isnan(latitude) ? 0 : fabs(latitude);

    // An index to index biomeMatrix with
    int rowIndex = (int)round(latitude * (MATRIX_ROWS - 1));
    // An array of possible biomes to assign to this point
    Biome** biomeRow = biomeMatrix[rowIndex];

    // Get the size of the biomeRow. Last element of the biomeRow is a dummy element with a true value for `.stop`
    int biomeRowSize = 0;
    for(int i = 0; biomeRow[i]->odds >= 0; i++) {
        biomeRowSize++;
    }

    // Convert the `.odds` (a double from 0 to 1) to a threshold between 0 and 1 that indicates that if our random noise (again, range from 0 to 1) is equal or higher to the threshold, then we choose that biome
    BiomeThreshold* oddsThresholds = calculateOddsThresholds(biomeRow, biomeRowSize);


    // To calculate the blend, we will check the biome type at each 27 directions in 3D space from our sampled point.
    // But first we need to know how far ahead we need to look ahead in the directions.
    // The smaller the distance we need to check, the sharper the biome blending will be
    // Mesas need sharp biome blending, but swamps need smoother biome blending e.g.
    float biomeNoise = fabsf(fnlGetNoise3D(&biomeNoiseGenerator, noiseLoc.x, noiseLoc.y, noiseLoc.z));

    Biome* centralBiome = recursivelyFindBiome(oddsThresholds, biomeRowSize, biomeNoise);

    double blendDistance = 0.00008;




    // Now, get all biomes in each 27 directions in 3D space blendDistance units away from the sampled point and check if the biome at those points differ from the sampled point
    BiomeBlend biomeBlends[27];
    int biomeBlendIndex = 0;

    for(int x = -1; x <= 1; x++) {
        for(int y = -1; y <= 1; y++) {
            for(int z = -1; z <= 1; z++) {

                // Take an offset, which can be -blendDistance, +0, or +blendDistance from the sampled point
                double xOffset = noiseLoc.x + (x * blendDistance);
                double yOffset = noiseLoc.y + (y * blendDistance);
                double zOffset = noiseLoc.z + (z * blendDistance);

                // Fix floating point errors
                if(xOffset < 0.2 || xOffset > 2.2 || yOffset < 0.2 || yOffset > 2.2 || zOffset < 0.2 || zOffset > 2.2) {
                    xOffset = noiseLoc.x;
                    yOffset = noiseLoc.y;
                    zOffset = noiseLoc.z;
                }

                // Generate noise for both what biome will be on the point as well as what the blending noise for that point is.
                float biomeNoise = fabsf(fnlGetNoise3D(&biomeNoiseGenerator, xOffset, yOffset, zOffset));
                float blendingNoise = fabsf(fnlGetNoise3D(&blendingNoiseGenerator, xOffset, yOffset, zOffset));

                // Find what biome fits this sampled point based on the odds in the oddsThresholds array
                // Initial value will be first value in the array !!! THIS MEANS THAT NO ARRAY MAY BE LEFT EMPTY !!! (duh)

                Biome* biomeOfChoice = recursivelyFindBiome(oddsThresholds, biomeRowSize, biomeNoise);

                BiomeBlend biomeBlend = { 0, blendingNoise, biomeOfChoice };
                
                int index = biomeBlendIndex++;
                biomeBlends[index] = biomeBlend;
            }
        }
    }

    free(oddsThresholds);

    Biome* biomeStructs[BIOME_TYPE_COUNT];
    //Array of weights for each biome, indexed by biome height value (fjords = 1, swamp = 4, etc. Check header file)
    double biomeWeights[BIOME_TYPE_COUNT];
    // Array keeping count of how many times we saw a particular biome, again indexed the same way
    int biomeWeightCounts[BIOME_TYPE_COUNT];
    // Total value of all weights combined, irregardless of the biome the weight belongs to
    double totalBiomeWeights = 0.0;

    // Normally C should guarantee that all values for the two above arrays are 0, but for some reason it's not :/
    for(int i = 0; i < BIOME_TYPE_COUNT; i++) {
        biomeWeights[i] = 0.0;
        biomeWeightCounts[i] = 0;
    }

    // For every point sampled 0.00001 units away from the requested point, aggregate their weights into the biomeWeights array, the count in the biomeWeightCounts array, and the total weights in the totalBiomeWeights variable
    for(int i = 0; i < 27; i++) {
        BiomeBlend biomeBlend = biomeBlends[i];

        double biomeWeight = biomeWeights[(int)biomeBlend.biome->type];
        int biomeWeightCount = biomeWeightCounts[(int)biomeBlend.biome->type];

        totalBiomeWeights += biomeBlend.blend;
        biomeStructs[(int)biomeBlend.biome->type] = biomeBlend.biome;
        biomeWeights[(int)biomeBlend.biome->type] = biomeWeight + biomeBlend.blend;
        biomeWeightCounts[(int)biomeBlend.biome->type] = biomeWeightCount + 1;
    }

    // Get how many biomes were actually found
    int biomeSize = 0;
    for(int i = 0; i < BIOME_TYPE_COUNT; i++) {
        int biomeWeightCount = biomeWeightCounts[i];

        if(biomeWeightCount != 0) {
            biomeSize++;
        }
    }

    // This is our return array, so we allocate it on the heap
    BiomeBlend *biomes = malloc(sizeof(BiomeBlend) * (biomeSize+1));

    // A dirty hack to provide the length is to add the length as first element in the array, abusing BiomeBlend but oh well
    BiomeBlend length = { biomeSize, 0, &UnsetBiome };
    biomes[0] = length;

    // Fill the biomes array with biome + blend
    int biomeIndex = 2;
    for(int i = 0; i < BIOME_TYPE_COUNT; i++) {
        double biomeWeight = biomeWeights[i];
        int biomeWeightCount = biomeWeightCounts[i];

        if(biomeWeightCount != 0) {
            Biome* biomeStruct = biomeStructs[i];
            
            int index = i == centralBiome->type ? 1 : biomeIndex++;
            // The weight of the biome / the total of all weights gives us a percentage of how influencial this biome is to the sampled point
            // If there is only one biome, the weight is 1 by definition
            double weight = biomeWeight / totalBiomeWeights;
            BiomeBlend biome = { 0, weight, biomeStruct };
            biomes[index] = biome;
        }
    }

    return biomes;


}