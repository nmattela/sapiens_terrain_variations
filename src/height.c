#include "SPLog.h"
#include "SPHeight.h"
#include <stdio.h>


bool spReplacesPreviousHeight()
{
	return false;
}

SPVec4 spHeightGet(SPVec4 previousHeight, //if spReplacesPreviousHeight returns false, then previousHeight is the output of the previous mod, otherwise it should be ignored.
                   SPNoise* noise1,
                   SPNoise* noise2,
                   SPVec3 pointNormal,
                   SPVec3 noiseLoc,
                   SPWorldGenOptions worldGenOptions,
                   double riverValue,
                   double riverDistance) {

    spLog("HELLO WORLD");
    // char riverString[sizeof(riverValue) * 10 + 1];
    // sprintf(riverString, "%f", riverValue);
    // mjLog(riverString);

    if(riverDistance < 0.001) {
        return previousHeight;
    } else {
        SPVec4 result = {SP_METERS_TO_PRERENDER(100), riverDistance, 0.0, 0.0};
        return result;
    }

}