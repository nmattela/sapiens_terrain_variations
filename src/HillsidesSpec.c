#include "HillsidesSpec.h"

double getHillsidesHeight(
    SPVec4 previousHeight,
    SPNoise* noise1,
    SPNoise* noise2,
    SPVec3 pointNormal,
    SPVec3 noiseLoc,
    SPWorldGenOptions worldGenOptions,
    double riverValue,
    double riverDistance) {
    
    double previous = SP_PRERENDER_TO_METERS(previousHeight.x);

    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 7599.0), 2);
    height *= 500;
    height += 250;


    if(riverDistance < 0.001 && previous >= -10) {
        height = rangeMap(0, 0.001, spMax(previous, -50.0), height, riverDistance);
    } else if(previous < 0) {
        height = smootheTowardsOcean(height, previous);
    }

    return height;

}