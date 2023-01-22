#include "SPHeight.h"
#include "customBiomes.h"
#include "utils.h"
#include "SPLog.h"
#include <stdio.h>
#include <stdlib.h>

bool spReplacesPreviousHeight()
{
	return false;
}

SPVec4 generateDebugTerrain(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance,
    double biomeBlend
) {
    SPVec4 result = {SP_METERS_TO_PRERENDER(biomeBlend), riverDistance, 0.0, 0.0};
    return result;
}



SPVec4 spHeightGet(SPVec4 previousHeight,
                   SPNoise* noise1,
                   SPNoise* noise2,
                   SPVec3 pointNormal,
                   SPVec3 noiseLoc,
                   SPWorldGenOptions worldGenOptions,
                   double riverValue,
                   double riverDistance) {

    BiomeBlend* biomeBlendArray = getBiomeForPoint(noiseLoc);

    int biomeBlendSize = biomeBlendArray[0].count;

    // //DEBUG
    // double height = generateHillsides(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
    // SPVec4 result = previousHeight;
    // result.x = SP_METERS_TO_PRERENDER(height);
    // return result;
    // //DEBUG

    double totalHeight = 0.0;
    for(int i = 1; i < biomeBlendSize+1; i++) {
        BiomeBlend biomeBlend = biomeBlendArray[i];

        double height = SP_PRERENDER_TO_METERS(previousHeight.x);

        if(biomeBlend.biome->type == Unset) {
            
        } else {
            height = biomeBlend.biome->getHeight(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
        }

        totalHeight += height * biomeBlend.blend;
    }
    free(biomeBlendArray);

    SPVec4 result = previousHeight;
    result.x = SP_METERS_TO_PRERENDER(totalHeight);
    return result;

}