#include "FjordsSpec.h"

double getFjordsHeight(SPVec4 previousHeight,
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