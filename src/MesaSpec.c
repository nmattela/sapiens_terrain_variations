#include "MesaSpec.h"

double getMesaHeight(
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

double getMonumentValleyHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance
) {
    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);

    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 1000), 1);

    // height = fabs(height);
    // height = rangeMap(0, 1, previous, fabs(previous)+3000, height);

    height = 3000;

    return height;

}