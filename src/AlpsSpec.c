#include "AlpsSpec.h"

double getAlpsHeight(
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

    double height = spNoiseGet(noise1, spVec3Mul(noiseLoc, 2000.0), 2);
    height *= 4000;
    height += 2000;

    if(riverDistance < 0.1) {
        height = rangeMap(0.005, 0.1, (height / 3), height, riverDistance);
    }
    if(riverDistance < 0.05 && previous >= -50) {
        height = rangeMap(0, 0.05, spMax(previous, -50.0) - 20, height, riverDistance);
    }
    if(previous < -50) {
        height = smootheTowardsOcean(height, previous);
    }

    return height;
}