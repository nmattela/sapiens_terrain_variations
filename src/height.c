#include "SPHeight.h"
#include "heightBiomes.h"
#include "utils.h"
#include "SPLog.h"
#include <stdio.h>

#define SP_PRERENDER_TO_METERS(_prerender_) ((_prerender_) * 8388608.0)

bool spReplacesPreviousHeight()
{
	return false;
}

double generateFjords(SPVec4 previousHeight, //a7852
                    SPNoise* noise1,
                    SPNoise* noise2,
                    SPVec3 pointNormal,
                    SPVec3 noiseLoc,
                    SPWorldGenOptions worldGenOptions,
                    double riverValue,
                    double riverDistance) {
    
    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);
    
    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 1000), 8);

    height = fabs(height);
    height = rangeMap(0, 1, previous, previous+1000, height);
    //height *= 1000;

    if(riverDistance < 0.001 && previous >= -10) {
        // double riverHeight = spMax(SP_PRERENDER_TO_METERS(previousHeight.x), -50.0);
        // height = cosineSmoothing(0, 0.001, riverHeight, height, riverDistance);

        double riverHeight = spMax(previous, -200.0);//b9691
        //double m = height / 0.001;
        double newMax = previous < 0 ? smootheTowardsOcean(height, previous) : height;
        height = rangeMapNoInvert(0, 0.0009, riverHeight, newMax, riverDistance);
        //height = slopeSmoothing(m, riverDistance, riverHeight);
    } else if(previous < 0) {
        height = smootheTowardsOcean(height, previous);
    }

    return height;
}

double generateMesa(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance) {

    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);

    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 1000), 1);

    height = fabs(height);
    height = rangeMap(0, 1, previous, previous+1000, height);
    //height *= 1000;

    // Height for river water
    if(riverDistance < 0.00005 && previous >= -20) {
        height = spMax(previous, -20.0);
    // Height for river slope
    } else if(riverDistance < 0.00015 && previous >= -20) {
        //height = 1;

        double multiplier = spNoiseGet(noise1, spVec3Mul(noiseLoc, 100), 1);
        multiplier *= 10;
        height = spMax(multiplier, 1);
    // Height for river bank
    } else if(riverDistance < 0.00035 && previous >= -20) {
        //We need to map the X range = [0.001, 0.002], onto Y range = [defaultHeight, height]

        double oldMin = 0.00015;
        double oldMax = 0.00035;
        double newMin = spMax(previous, 1);
        double newMax = previous < 0 ? smootheTowardsOcean(height, previous) : height;

        double newValue = rangeMapNoInvert(oldMin, oldMax, newMin, newMax, riverDistance);

        height = newValue;
    // Height for when ocean in sight
    } else if(previous < 0) {
        height = smootheTowardsOcean(height, previous);
    }

   return height;  
}

double generatePlains(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance) {

    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);

    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 500), 5);
    height *= 50;
    height = fabs(height);

    if(riverDistance < 0.01 && previous >= -10) {
        height = rangeMap(0, 0.01, spMax(previous, -50.0), height, riverDistance);
    } else if(previous < 0) {
        height = smootheTowardsOcean(height, previous);
    }

    return height;
}

double generateSwamp(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance) {

    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);
    
    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 6000), 4);
    height *= 30;

    if(riverDistance < 0.001 && previous >= -10) {
        height = rangeMap(0, 0.001, spMax(previous, -50.0), height, riverDistance);
    } else if(previous < 0) {
        height = smootheTowardsOcean(height, previous);
    }

    return height;

}

double generateDesertOasis(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance) {
    
    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);

    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 9000), 4);
    height *= 150;
    height += 50;

    if(riverDistance < 0.001 && previous >= -10) {
        height = rangeMap(0, 0.001, spMax(previous, -50.0), height, riverDistance);
    } else if(previous < 0) {
        height = smootheTowardsOcean(height, previous);
    }

    return height;

}

double generateHillsides(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance) {
    
    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);

    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 45999.0), 1);
    height *= 100;
    height += 50;


    if(riverDistance < 0.001 && previous >= -10) {
        height = rangeMap(0, 0.001, spMax(previous, -50.0), height, riverDistance);
    } else if(previous < 0) {
        height = smootheTowardsOcean(height, previous);
    }

    return height;

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

    HeightBiome* heightBiomesArray = getHeightBiomeForPoint(noiseLoc);

    uint16_t heightBiomeSize = heightBiomesArray[0].biome;

    // //DEBUG
    // double height = generateHillsides(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
    // SPVec4 result = previousHeight;
    // result.x = SP_METERS_TO_PRERENDER(height);
    // return result;
    // //DEBUG

    double totalHeight = 0.0;
    for(int i = 1; i < heightBiomeSize+1; i++) {
        HeightBiome heightBiome = heightBiomesArray[i];

        double height = SP_PRERENDER_TO_METERS(previousHeight.x);
        switch(heightBiome.biome) {
            case fjords: {
                height = generateFjords(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
                break;
            }
            case mesa: {
                height = generateMesa(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
                break;
            }
            case plains: {
                height = generatePlains(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
                break;
            }
            case swamp: {
                height = generateSwamp(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
                break;
            }
            case desertOasis: {
                height = generateDesertOasis(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
                break;
            }
            case hillsides: {
                height = generateHillsides(previousHeight, noise1, noise2, pointNormal, noiseLoc, worldGenOptions, riverValue, riverDistance);
                break;                
            }
        }

        totalHeight += height * heightBiome.blend;
    }

    SPVec4 result = previousHeight;
    result.x = SP_METERS_TO_PRERENDER(totalHeight);
    return result;

}