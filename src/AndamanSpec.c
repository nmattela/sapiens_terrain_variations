#include "AndamanSpec.h"
#include "SPLog.h"

double getAndamanHeight(
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

    double water = spNoiseGet(noise1, spVec3Mul(noiseLoc, 5000.0), 6);

    double height = spNoiseGet(noise2, spVec3Mul(noiseLoc, 6000.0), 5);
    height *= 400;

    if(height >= 0 && water <= 0) {

        if(water > -0.1) {
            height = rangeMapNoInvert(0, -0.1, height, (height / 2) * -1, water);
        } else {
            height = (height / 2) * -1;
        }
    }

    if(riverDistance < 0.001 && previous >= -20) {
        height = rangeMap(0, 0.001, spMax(previous, -50.0), height, riverDistance);
    }

    return height;
}