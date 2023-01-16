#define _GNU_SOURCE
#include "SPBiome.h"
#include "heightBiomes.h"
#include "heightBiomesFlora.h"
#include "SPLog.h"
#include "utils.h"
#include "FastNoiseLite.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void spBiomeInit(SPBiomeThreadState* threadState) {

    // for(int r = 0; r < 256; r++) {
    //     for(int g = 0; g < 256; g++) {
    //         for(int b = 0; b < 0; b++) {
    //             char* str;
    //             asprintf(&str, "debug_%d_%d_%d", r, g, b);
    //             threadState->getTerrainBaseTypeIndex(threadState, str);
    //             threadState->getTerrainVariation(threadState, str);
    //         }
    //     }
    // }

    for(int i = 0; i < 256; i++) {
        char* strRed;
        asprintf(&strRed, "debug_%d_0_0", i);
        threadState->getTerrainBaseTypeIndex(threadState, strRed);
        threadState->getTerrainVariation(threadState, strRed);

        char* strGreen;
        asprintf(&strGreen, "debug_0_%d_0", i);
        threadState->getTerrainBaseTypeIndex(threadState, strGreen);
        threadState->getTerrainVariation(threadState, strGreen);

        char* strBlue;
        asprintf(&strBlue, "debug_0_0_%d", i);
        threadState->getTerrainBaseTypeIndex(threadState, strBlue);
        threadState->getTerrainVariation(threadState, strBlue);

        free(strRed);
        free(strGreen);
        free(strBlue);
    }
}

double min = 100000;
double max = -100000;

// SPSurfaceTypeResult spBiomeGetSurfaceTypeForPoint(
//     SPBiomeThreadState* threadState,
//     SPSurfaceTypeResult incomingType,
//     uint16_t* tags,
//     int tagCount,
//     uint32_t* modifications,
//     int modificationCount,
//     uint32_t fillGameObjectTypeIndex,
//     // (-Infinity, +Infinity)
//     int16_t digFillOffset,
//     uint32_t* variations,
//     SPVec3 pointNormal, 
//     SPVec3 noiseLoc, 
//     // (-0.001, 0.001)
//     double baseAltitude,
//     // (0, 2(+))
//     double steepness,
//     // (0, +Infinity)
//     double riverDistance,
//     int seasonIndex
// ) {

//     SPSurfaceTypeResult result = incomingType;

//     //Steepness is the difference between a sampled value 4 meters to the north and a sampled value 4 meters to the east. Using triangulation, we can get the angle
//     double angle = isnan(steepness) ? 0 : atan(steepness / sqrt(32));
//     double steepnessRange = rangeMap(0, 1.5707963268, 0, 1, angle);

//     long steepnessColor = roundl(rangeMap(0, 1, 0, 255, steepnessRange));
//     char* steepnessString;
//     asprintf(&steepnessString, "debug_%ld_0_0", steepnessColor);

//     //baseAltitude varies, and there is no "absolute minimum" or "absolute maximum", but running some tests it seems to fall between -0.001 and 0.001.
//     //Negative values are below sea level.
//     //1/255th is about 17 meters, putting the "highest" altitude to 4335 (if you see 0.001 as the maximum)
//     //1 meter in altitude is therefore 0.00000023 units in baseAltitude
//     long baseAltitudeColor = roundl(rangeMap(0, 0.001, 0, 255, baseAltitude));
//     char* baseAltitudeString;
//     asprintf(&baseAltitudeString, "debug_0_%ld_0", baseAltitudeColor);

//     //riverDistance of 1 is roughly 7650 hexagons removed from the nearest river
//     long riverDistanceColor = roundl(rangeMap(0, 1, 0, 255, riverDistance));
//     char* riverDistanceString;
//     asprintf(&riverDistanceString, "debug_0_0_%ld", riverDistanceColor);

//     result.surfaceBaseType = threadState->getTerrainBaseTypeIndex(threadState, riverDistanceString);
    
//     SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, result.surfaceBaseType);
//     result.materialIndex = defaults.materialIndex;
//     result.decalTypeIndex = defaults.decalGroupIndex;
//     result.pathDifficultyIndex = defaults.pathDifficultyIndex;

//     free(steepnessString);
//     free(baseAltitudeString);
//     free(riverDistanceString);

//     return result;
// }

typedef struct SurfaceTypeInfo {
	bool river;
	bool hot;
	int snowDepth;
} SurfaceTypeInfo;

void getSurfaceTypeInfo(SPBiomeThreadState* threadState, uint16_t* biomeTags, int tagCount, int seasonIndex, SurfaceTypeInfo* surfaceTypeInfo, double steepness, double noiseValue)
{

    uint16_t biomeTag_hot = threadState->getBiomeTag(threadState, "hot");
	uint16_t biomeTag_wet = threadState->getBiomeTag(threadState, "wet");
	uint16_t biomeTag_dry = threadState->getBiomeTag(threadState, "dry");
	uint16_t biomeTag_desert = threadState->getBiomeTag(threadState, "desert");
	uint16_t biomeTag_steppe = threadState->getBiomeTag(threadState, "steppe");
	uint16_t biomeTag_rainforest = threadState->getBiomeTag(threadState, "rainforest");
	uint16_t biomeTag_tropical = threadState->getBiomeTag(threadState, "tropical");
	uint16_t biomeTag_savanna = threadState->getBiomeTag(threadState, "savanna");
	uint16_t biomeTag_polar = threadState->getBiomeTag(threadState, "polar");
	uint16_t biomeTag_icecap = threadState->getBiomeTag(threadState, "icecap");
	uint16_t biomeTag_tundra = threadState->getBiomeTag(threadState, "tundra");
	uint16_t biomeTag_temperate = threadState->getBiomeTag(threadState, "temperate");
	uint16_t biomeTag_heavySnowWinter = threadState->getBiomeTag(threadState, "heavySnowWinter");
	uint16_t biomeTag_medSnowWinter = threadState->getBiomeTag(threadState, "medSnowWinter");
	uint16_t biomeTag_lightSnowWinter = threadState->getBiomeTag(threadState, "lightSnowWinter");
	uint16_t biomeTag_heavySnowSummer = threadState->getBiomeTag(threadState, "heavySnowSummer");
	uint16_t biomeTag_medSnowSummer = threadState->getBiomeTag(threadState, "medSnowSummer");
	uint16_t biomeTag_lightSnowSummer = threadState->getBiomeTag(threadState, "lightSnowSummer");
	uint16_t biomeTag_drySummer = threadState->getBiomeTag(threadState, "drySummer");
	uint16_t biomeTag_dryWinter = threadState->getBiomeTag(threadState, "dryWinter");
	uint16_t biomeTag_verySparseForest = threadState->getBiomeTag(threadState, "verySparseForest");
	uint16_t biomeTag_sparseForest = threadState->getBiomeTag(threadState, "sparseForest");
	uint16_t biomeTag_mediumForest = threadState->getBiomeTag(threadState, "mediumForest");
	uint16_t biomeTag_denseForest = threadState->getBiomeTag(threadState, "denseForest");
	uint16_t biomeTag_coniferous = threadState->getBiomeTag(threadState, "coniferous");
	uint16_t biomeTag_birch = threadState->getBiomeTag(threadState, "birch");
	uint16_t biomeTag_cliff = threadState->getBiomeTag(threadState, "cliff");
	uint16_t biomeTag_river = threadState->getBiomeTag(threadState, "river");
	uint16_t biomeTag_bamboo = threadState->getBiomeTag(threadState, "bamboo");

	for(int i = 0; i < tagCount; i++)
	{
		if(biomeTags[i] == biomeTag_river)
		{
			surfaceTypeInfo->river = true;
		}
		else if(biomeTags[i] == biomeTag_hot)
		{
			surfaceTypeInfo->hot = true;
		}
		else if(biomeTags[i] == biomeTag_heavySnowSummer)
		{
			surfaceTypeInfo->snowDepth = 3;
		}
		else if(biomeTags[i] == biomeTag_medSnowSummer)
		{
			if(seasonIndex == 1)
			{
				surfaceTypeInfo->snowDepth = 2;
			}
			else
			{
				surfaceTypeInfo->snowDepth = 3;
			}
		}
		else if(biomeTags[i] == biomeTag_lightSnowSummer)
		{
			if(seasonIndex == 1)
			{
				surfaceTypeInfo->snowDepth = 1;
			}
			else if(seasonIndex == 0 || seasonIndex == 2)
			{
				surfaceTypeInfo->snowDepth = 2;
			}
			else
			{
				surfaceTypeInfo->snowDepth = 3;
			}
		}
		else if(biomeTags[i] == biomeTag_heavySnowWinter)
		{
			if(seasonIndex == 3)
			{
				surfaceTypeInfo->snowDepth = 3;
			}
		}
		else if(biomeTags[i] == biomeTag_medSnowWinter)
		{
			if(seasonIndex == 3)
			{
				surfaceTypeInfo->snowDepth = 2;
			}
		}
		else if(biomeTags[i] == biomeTag_lightSnowWinter)
		{
			if(seasonIndex == 3)
			{
				surfaceTypeInfo->snowDepth = 1;
			}
		}
	}

	if(surfaceTypeInfo->snowDepth > 0)
	{
		if(steepness > 0.4 + noiseValue * 0.2)
		{
			surfaceTypeInfo->snowDepth--;
		}
		if(steepness > 0.7 + noiseValue * 0.2)
		{
			surfaceTypeInfo->snowDepth--;
		}
	}
}

static const double SEA_LEVEL = SP_METERS_TO_PRERENDER(-0.1);
static const double DEEP_SEA_LEVEL = SP_METERS_TO_PRERENDER(-1.1);

SPSurfaceTypeResult spBiomeGetSurfaceTypeForPoint(
    SPBiomeThreadState* threadState,
    SPSurfaceTypeResult incomingType,
    uint16_t* tags,
    int tagCount,
    uint32_t* modifications,
    int modificationCount,
    uint32_t fillGameObjectTypeIndex,
    // (-Infinity, +Infinity)
    int16_t digFillOffset,
    uint32_t* variations,
    SPVec3 pointNormal, 
    SPVec3 noiseLoc, 
    // (-0.001, 0.001)
    double baseAltitude,
    // (0, 2(+))
    double steepness,
    // (0, +Infinity)
    double riverDistance,
    int seasonIndex
) {

	uint32_t terrainModification_snowRemoved						= threadState->getTerrainModification(threadState, "snowRemoved");
	uint32_t terrainModification_vegetationRemoved				    = threadState->getTerrainModification(threadState, "vegetationRemoved");
	uint32_t terrainModification_preventGrassAndSnow				= threadState->getTerrainModification(threadState, "preventGrassAndSnow");

	uint32_t terrainVariation_snow									= threadState->getTerrainVariation(threadState, "snow");
	uint32_t terrainVariation_grassSnow								= threadState->getTerrainVariation(threadState, "grassSnow");

	uint32_t terrainVariation_shallowWater							= threadState->getTerrainVariation(threadState, "shallowWater");
	uint32_t terrainVariation_deepWater								= threadState->getTerrainVariation(threadState, "deepWater");

	

	//Steepness is the difference between a sampled value 4 meters to the north and a sampled value 4 meters to the east. Using triangulation, we can get the angle
    double angle = isnan(steepness) ? 0 : atan(steepness / sqrt(32));
    steepness = rangeMap(0, 1.5707963268, 0, 1, angle);

	double noiseValueVanilla = spNoiseGet(threadState->spNoise1, spVec3Mul(noiseLoc, 45999.0 ), 2);

	SPSurfaceTypeResult result = incomingType;

	SurfaceTypeInfo surfaceTypeInfo;
	memset(&surfaceTypeInfo, 0, sizeof(surfaceTypeInfo));
	getSurfaceTypeInfo(threadState, tags, tagCount, seasonIndex, &surfaceTypeInfo, steepness, noiseValueVanilla);

	bool snowRemoved = false;
	bool shouldAddVegetation = true;
	int soilQuality = 1;

	for(int i = 0; i < modificationCount; i++)
	{
		if(modifications[i] == terrainModification_snowRemoved)
		{
			snowRemoved = true;
		}
		else if(modifications[i] == terrainModification_vegetationRemoved)
		{
			shouldAddVegetation = false;
		}
	}

	bool underWater = (baseAltitude + SP_METERS_TO_PRERENDER((double)digFillOffset) < SEA_LEVEL);
	if(underWater)
	{
		shouldAddVegetation = false;
		snowRemoved = true;
	}


	uint32_t fillSurfaceBaseType = 0;
	if(fillGameObjectTypeIndex != 0)
	{
		fillSurfaceBaseType = threadState->getSurfaceBaseTypeForFillObjectType(threadState, fillGameObjectTypeIndex);
	}


	bool hasSnow = false;
	if(!snowRemoved && surfaceTypeInfo.snowDepth > 0)
	{
		if(surfaceTypeInfo.snowDepth == 3)
		{
			hasSnow = true;
		}
		else if((noiseValueVanilla> -0.1))
		{
			if(surfaceTypeInfo.snowDepth == 2 || (noiseValueVanilla> 0.3))
			{
				hasSnow = true;
			}
		}
	}

	HeightBiome* heightBiomesArray = getHeightBiomeForPoint(noiseLoc);

	uint16_t heightBiomesSize = heightBiomesArray[0].biome;

	HeightBiome biome = heightBiomesArray[1];

	BiomeTerrainBaseDistribution distribution = defaultTerrainDistribution;
	switch(biome.biome) {
		case fjords: distribution = fjordsTerrainDistribution;break;
		case mesa: distribution = mesaTerrainDistribution;break;
		case plains: distribution = plainsTerrainDistribution;break;
		case swamp: distribution = swampTerrainDistribution;break;
		case desertOasis: distribution = desertOasisTerrainDistribution;break;
		case hillsides: distribution = hillsidesTerrainDistribution;break;
		default: {
			return incomingType;
		}
	}

	double calculatedOdds[distribution.terrainBaseTypeOddsCount];
	double totalOdds = 0;
	for(int i = 0; i < distribution.terrainBaseTypeOddsCount; i++) {
		TerrainBaseTypeOdds* terrainBaseTypeOdds = distribution.terrainBaseTypesOdds[i];
		double odds = terrainBaseTypeOdds->odds;

		if(baseAltitude > terrainBaseTypeOdds->minBaseAltitude && baseAltitude < terrainBaseTypeOdds->maxBaseAltitude) {
			double baseAltitudeModifier = rangeMap(terrainBaseTypeOdds->minBaseAltitude, terrainBaseTypeOdds->maxBaseAltitude, terrainBaseTypeOdds->baseAltitudeFrom, terrainBaseTypeOdds->baseAltitudeTo, baseAltitude);
			odds *= baseAltitudeModifier;
		}
		if(steepness > terrainBaseTypeOdds->minSteepness && steepness < terrainBaseTypeOdds->maxSteepness) {
			double steepnessModifier = rangeMap(terrainBaseTypeOdds->minSteepness, terrainBaseTypeOdds->maxSteepness, terrainBaseTypeOdds->steepnessFrom, terrainBaseTypeOdds->steepnessTo, steepness);
			odds *= steepnessModifier;
		}
		if(riverDistance > terrainBaseTypeOdds->minRiverDistance && riverDistance < terrainBaseTypeOdds->maxRiverDistance) {
			double riverDistanceModifier = rangeMap(terrainBaseTypeOdds->minRiverDistance, terrainBaseTypeOdds->maxRiverDistance, terrainBaseTypeOdds->riverDistanceFrom, terrainBaseTypeOdds->riverDistanceTo, riverDistance);
			odds *= riverDistanceModifier;
		}
		if(digFillOffset > terrainBaseTypeOdds->minDigFillOffset && digFillOffset < terrainBaseTypeOdds->maxDigFillOffset) {
			double digFillOffsetModifier = rangeMap(terrainBaseTypeOdds->minDigFillOffset, terrainBaseTypeOdds->maxDigFillOffset, terrainBaseTypeOdds->digFillOffsetFrom, terrainBaseTypeOdds->digFillOffsetTo, digFillOffset);
			odds *= digFillOffsetModifier;
		}

		calculatedOdds[i] = odds;
		totalOdds += odds;
	}

	fnl_state noiseValueGenerator = fnlCreateState();
	noiseValueGenerator.noise_type = FNL_NOISE_CELLULAR;
	noiseValueGenerator.frequency = 45999.0;
	noiseValueGenerator.octaves = 6;
	noiseValueGenerator.cellular_return_type = FNL_CELLULAR_RETURN_VALUE_CELLVALUE;
	noiseValueGenerator.cellular_distance_func = FNL_CELLULAR_DISTANCE_HYBRID;

	double accumulatedOdds = 0;
	TerrainBaseTypeOdds* chosenTerrainBaseTypeOdds = distribution.terrainBaseTypesOdds[distribution.terrainBaseTypeOddsCount-1];
	for(int i = 0; i < distribution.terrainBaseTypeOddsCount; i++) {
		double odds = calculatedOdds[i] / totalOdds;
		TerrainBaseTypeOdds* terrainBaseTypeOdds = distribution.terrainBaseTypesOdds[i];

		switch(terrainBaseTypeOdds->size) {
			case XS: noiseValueGenerator.frequency = 834567.0;break;
			case S:  noiseValueGenerator.frequency = 92273.0;break;
			case M:  noiseValueGenerator.frequency = 45999.0;break;
			case L:  noiseValueGenerator.frequency = 8073.0;break;
			case XL: noiseValueGenerator.frequency = 5036.0;break;
			default: noiseValueGenerator.frequency = 45999.0;break;
		}
		double noiseValue = (double)fabsf(fnlGetNoise3D(&noiseValueGenerator, noiseLoc.x, noiseLoc.y, noiseLoc.z));

		if(noiseValue > accumulatedOdds && noiseValue <= odds + accumulatedOdds) {
			chosenTerrainBaseTypeOdds = terrainBaseTypeOdds;
			break;
		} else {
			accumulatedOdds += odds;
		}
	}

	uint32_t grassVariation = 0;
	for(int i = 0; i < chosenTerrainBaseTypeOdds->variationCount; i++) {
		char* variationIndex = chosenTerrainBaseTypeOdds->variations[i];
		uint32_t variation = threadState->getTerrainVariation(threadState, variationIndex);

		bool isGrassVariation = false;
		if(shouldAddVegetation && grassVariation == 0) {
			for(int j = 0; j < GRASS_VARIATIONS_COUNT; j++) {
				if(grassVariations[j] == variationIndex) {
					isGrassVariation = true;
					break;
				}
			}
		}

		bool isSnowVariation = false;
		if(!snowRemoved && hasSnow && (variationIndex == "snow" || variationIndex == "grassSnow")) {
			isSnowVariation = true;
		}

		if(isSnowVariation) {
			variations[result.variationCount++] = variation;
		}

		if(shouldAddVegetation && isGrassVariation) {
			variations[result.variationCount++] = variation;
			grassVariation = variation;
		}
	}
	
	result.surfaceBaseType = threadState->getTerrainBaseTypeIndex(threadState, chosenTerrainBaseTypeOdds->terrainBaseTypeIndex);
	result.materialIndex = 0;

	if(fillSurfaceBaseType != 0) {
		result.surfaceBaseType = fillSurfaceBaseType;
	}

	if(grassVariation != 0) {
		SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, grassVariation);
		if(variationDefaults.materialIndex != 0) {
			result.materialIndex = variationDefaults.materialIndex;
			result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;

			result.decalTypeIndex = variationDefaults.decalGroupIndex;
		}
	}

	if(hasSnow) {
		SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, grassVariation != 0 ? terrainVariation_grassSnow : terrainVariation_snow);
		if(variationDefaults.materialIndex != 0) {
			result.materialIndex = variationDefaults.materialIndex;
			result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;

			if(grassVariation != 0) {
				result.decalTypeIndex = variationDefaults.decalGroupIndex;
			} else {
				result.decalTypeIndex = 0;
			}
		}
	}
	
	if(result.materialIndex == 0) {
		SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, result.surfaceBaseType);
		result.materialIndex = defaults.materialIndex;
		result.decalTypeIndex = defaults.decalGroupIndex;
		result.pathDifficultyIndex = defaults.pathDifficultyIndex;
	}

	if(baseAltitude + SP_METERS_TO_PRERENDER((double)digFillOffset) < SEA_LEVEL)
	{
		if(baseAltitude < DEEP_SEA_LEVEL)
		{
			SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, terrainVariation_deepWater);
			result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;
			variations[result.variationCount++] = terrainVariation_deepWater;
		}
		else
		{
			SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, terrainVariation_shallowWater);
			result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;
			variations[result.variationCount++] = terrainVariation_shallowWater;
		}
	}

	free(heightBiomesArray);

	return result;
}

// SPSurfaceTypeResult spBiomeGetSurfaceTypeForPoint(
//     SPBiomeThreadState* threadState,
//     SPSurfaceTypeResult incomingType,
//     uint16_t* tags,
//     int tagCount,
//     uint32_t* modifications,
//     int modificationCount,
//     uint32_t fillGameObjectTypeIndex,
//     // (-Infinity, +Infinity)
//     int16_t digFillOffset,
//     uint32_t* variations,
//     SPVec3 pointNormal, 
//     SPVec3 noiseLoc, 
//     // (-0.001, 0.001)
//     double baseAltitude,
//     // (0, 2(+))
//     double steepness,
//     // (0, +Infinity)
//     double riverDistance,
//     int seasonIndex
// ) {
//         uint32_t terrainModification_snowRemoved						= threadState->getTerrainModification(threadState, "snowRemoved");
//         uint32_t terrainModification_vegetationRemoved				    = threadState->getTerrainModification(threadState, "vegetationRemoved");
//         uint32_t terrainModification_preventGrassAndSnow				= threadState->getTerrainModification(threadState, "preventGrassAndSnow");

//         uint32_t terrainVariation_snow									= threadState->getTerrainVariation(threadState, "snow");
// 	    uint32_t terrainVariation_grassSnow								= threadState->getTerrainVariation(threadState, "grassSnow");

//         uint32_t terrainVariation_shallowWater							= threadState->getTerrainVariation(threadState, "shallowWater");
// 	    uint32_t terrainVariation_deepWater								= threadState->getTerrainVariation(threadState, "deepWater");


//         // 



//         // fnl_state noiseValueGenerator = fnlCreateState();
//         // noiseValueGenerator.noise_type = FNL_NOISE_PERLIN;
//         // noiseValueGenerator.frequency = 45999.0;
//         // noiseValueGenerator.octaves = 2;

//         // fnl_state noiseValueSmallGenerator = fnlCreateState();
//         // noiseValueSmallGenerator.noise_type = FNL_NOISE_PERLIN;
//         // noiseValueSmallGenerator.frequency = 834567.0;
//         // noiseValueSmallGenerator.octaves = 2;

//         // fnl_state noiseValueMedGenerator = fnlCreateState();
//         // noiseValueMedGenerator.noise_type = FNL_NOISE_PERLIN;
//         // noiseValueMedGenerator.frequency = 92273.0;
//         // noiseValueMedGenerator.octaves = 2;

//         // fnl_state noiseValueLargeGenerator = fnlCreateState();
//         // noiseValueLargeGenerator.noise_type = FNL_NOISE_PERLIN;
//         // noiseValueLargeGenerator.frequency = 8073.0;
//         // noiseValueLargeGenerator.octaves = 2;

// 	    double noiseValue      = spNoiseGet(threadState->spNoise1, spVec3Mul(noiseLoc, 45999.0 ), 2);
//         double noiseValueSmall = spNoiseGet(threadState->spNoise1, spVec3Mul(noiseLoc, 834567.0), 2);
//         double noiseValueMed   = spNoiseGet(threadState->spNoise1, spVec3Mul(noiseLoc, 92273.0 ), 2);
//         double noiseValueLarge = spNoiseGet(threadState->spNoise1, spVec3Mul(noiseLoc, 8073.0  ), 2);


//         SPSurfaceTypeResult result = incomingType;

//         SurfaceTypeInfo surfaceTypeInfo;
//         memset(&surfaceTypeInfo, 0, sizeof(surfaceTypeInfo));
//         getSurfaceTypeInfo(threadState, tags, tagCount, seasonIndex, &surfaceTypeInfo, steepness, noiseValue);

//         noiseValue = fabs(noiseValue);
//         noiseValueSmall = fabs(noiseValueSmall);
//         noiseValueMed = fabs(noiseValueMed);
//         noiseValueLarge = fabs(noiseValueLarge);

//         bool snowRemoved = false;
//         bool shouldAddVegetation = true;
//         int soilQuality = 1;

//         for(int i = 0; i < modificationCount; i++)
//         {
//             if(modifications[i] == terrainModification_snowRemoved)
//             {
//                 snowRemoved = true;
//             }
//             else if(modifications[i] == terrainModification_vegetationRemoved)
//             {
//                 shouldAddVegetation = false;
//             }
//         }

//         bool underWater = (baseAltitude + SP_METERS_TO_PRERENDER((double)digFillOffset) < SEA_LEVEL);
//         if(underWater)
//         {
//             shouldAddVegetation = false;
//             snowRemoved = true;
//         }


//         uint32_t fillSurfaceBaseType = 0;
//         if(fillGameObjectTypeIndex != 0)
//         {
//             fillSurfaceBaseType = threadState->getSurfaceBaseTypeForFillObjectType(threadState, fillGameObjectTypeIndex);
//         }


//         bool hasSnow = false;
//         if(!snowRemoved && surfaceTypeInfo.snowDepth > 0)
//         {
//             if(surfaceTypeInfo.snowDepth == 3)
//             {
//                 hasSnow = true;
//             }
//             else if((noiseValue > -0.1))
//             {
//                 if(surfaceTypeInfo.snowDepth == 2 || (noiseValue > 0.3))
//                 {
//                     hasSnow = true;
//                 }
//             }
//         }



//         HeightBiome* heightBiomesArray = getHeightBiomeForPoint(noiseLoc);

//         uint16_t heightBiomesSize = heightBiomesArray[0].biome;

//         HeightBiome biome = heightBiomesArray[1];

//         BiomeTerrainBaseDistribution distribution = defaultTerrainDistribution;
//         switch(biome.biome) {
//             case fjords: distribution = fjordsTerrainDistribution;break;
//             case mesa: distribution = mesaTerrainDistribution;break;
//             case plains: distribution = plainsTerrainDistribution;break;
//             case swamp: distribution = swampTerrainDistribution;break;
//             case desertOasis: distribution = desertOasisTerrainDistribution;break;
//             case hillsides: distribution = hillsidesTerrainDistribution;break;
//             default: {
//                 return incomingType;
//             }
//         }

//         //spLog("%lf%lf%lfFor pointNormal = (%lf, %lf, %lf), noiseLoc = (%lf, %lf, %lf), scaledNoiseLoc = (%lf, %lf, %lf), noiseValue = %lf", pointNormal.x, pointNormal.y, pointNormal.z, pointNormal.x, pointNormal.y, pointNormal.z, noiseLoc.x, noiseLoc.y, noiseLoc.z, scaledNoiseLoc.x, scaledNoiseLoc.y, scaledNoiseLoc.z, noiseValue);

//         TerrainBaseTypeOdds* chosenTerrainBaseTypeOdds = distribution.terrainBaseTypesOdds[distribution.terrainBaseTypeOddsCount-1];
//         for(int i = 0; i < distribution.terrainBaseTypeOddsCount; i++) {
//             TerrainBaseTypeOdds* terrainBaseTypeOdds = distribution.terrainBaseTypesOdds[i];

//             double odds = terrainBaseTypeOdds->odds;
//             double oddsSmall = terrainBaseTypeOdds->oddsSmall;
//             double oddsMed = terrainBaseTypeOdds->oddsMed;
//             double oddsLarge = terrainBaseTypeOdds->oddsLarge;

//             if(baseAltitude > terrainBaseTypeOdds->minBaseAltitude && baseAltitude < terrainBaseTypeOdds->maxBaseAltitude) {
//                 double baseAltitudeModifier = rangeMap(terrainBaseTypeOdds->minBaseAltitude, terrainBaseTypeOdds->maxBaseAltitude, terrainBaseTypeOdds->baseAltitudeFrom, terrainBaseTypeOdds->baseAltitudeTo, baseAltitude);
//                 odds *= baseAltitudeModifier;
//                 oddsSmall *= baseAltitudeModifier;
//                 oddsMed *= baseAltitudeModifier;
//                 oddsLarge *= baseAltitudeModifier;
//             }
//             if(steepness > terrainBaseTypeOdds->minSteepness && steepness < terrainBaseTypeOdds->maxSteepness) {
//                 double steepnessModifier = rangeMap(terrainBaseTypeOdds->minSteepness, terrainBaseTypeOdds->maxSteepness, terrainBaseTypeOdds->steepnessFrom, terrainBaseTypeOdds->steepnessTo, steepness);
//                 odds *= steepnessModifier;
//                 oddsSmall *= steepnessModifier;
//                 oddsMed *= steepnessModifier;
//                 oddsLarge *= steepnessModifier;
//             }
//             if(riverDistance > terrainBaseTypeOdds->minRiverDistance && riverDistance < terrainBaseTypeOdds->maxRiverDistance) {
//                 double riverDistanceModifier = rangeMap(terrainBaseTypeOdds->minRiverDistance, terrainBaseTypeOdds->maxRiverDistance, terrainBaseTypeOdds->riverDistanceFrom, terrainBaseTypeOdds->riverDistanceTo, riverDistance);
//                 odds *= riverDistanceModifier;
//                 oddsSmall *= riverDistanceModifier;
//                 oddsMed *= riverDistanceModifier;
//                 oddsLarge *= riverDistanceModifier;
//             }
//             if(digFillOffset > terrainBaseTypeOdds->minDigFillOffset && digFillOffset < terrainBaseTypeOdds->maxDigFillOffset) {
//                 double digFillOffsetModifier = rangeMap(terrainBaseTypeOdds->minDigFillOffset, terrainBaseTypeOdds->maxDigFillOffset, terrainBaseTypeOdds->digFillOffsetFrom, terrainBaseTypeOdds->digFillOffsetTo, digFillOffset);
//                 odds *= digFillOffsetModifier;
//                 oddsSmall *= digFillOffsetModifier;
//                 oddsMed *= digFillOffsetModifier;
//                 oddsLarge *= digFillOffsetModifier;
//             }

//             // if(terrainBaseTypeOdds->terrainBaseTypeIndex == "poorDirt" || terrainBaseTypeOdds->terrainBaseTypeIndex == "poorDirt")
//             // spLog("For %s:\n noiseValue      = %lf <? odds      = %lf: %s,\n noiseValueSmall = %lf <? oddsSmall = %lf: %s,\n noiseValueMed   = %lf <? oddsMed   = %lf: %s,\n noiseValueLarge = %lf <? oddsLarge = %lf: %s\n", terrainBaseTypeOdds->terrainBaseTypeIndex, noiseValue, odds, noiseValue < odds ? "true" : "false", noiseValueSmall, oddsSmall, noiseValueSmall < oddsSmall ? "true" : "false", noiseValueMed, oddsMed, noiseValueMed < oddsMed ? "true" : "false", noiseValueLarge, oddsLarge, noiseValueLarge < oddsLarge ? "true" : "false");
//             if(noiseValue < odds && noiseValueSmall < oddsSmall && noiseValueMed < oddsMed && noiseValueLarge < oddsLarge) {
//                 // if(terrainBaseTypeOdds->terrainBaseTypeIndex == "poorDirt" || terrainBaseTypeOdds->terrainBaseTypeIndex == "poorDirt") {
//                 //     spLog("%s found", terrainBaseTypeOdds->terrainBaseTypeIndex);
//                 // }
//                 // if(terrainBaseTypeOdds->terrainBaseTypeIndex == "redRock") {
//                 //     spLog("redRockCount = %d, greenRockCount = %d", ++redRockCount, greenRockCount);
//                 // }
//                 // if(terrainBaseTypeOdds->terrainBaseTypeIndex == "greenRock") {
//                 //     spLog("redRockCount = %d, greenRockCount = %d", redRockCount, ++greenRockCount);
//                 // }
//                 chosenTerrainBaseTypeOdds = terrainBaseTypeOdds;
//                 break;
//             } else {
//                 // spLog("false for %s", terrainBaseTypeOdds->terrainBaseTypeIndex);
//             }
//         }

//         uint32_t grassVariation = 0;
//         for(int i = 0; i < chosenTerrainBaseTypeOdds->variationCount; i++) {
//             char* variationIndex = chosenTerrainBaseTypeOdds->variations[i];
//             uint32_t variation = threadState->getTerrainVariation(threadState, variationIndex);

//             bool isGrassVariation = false;
//             if(shouldAddVegetation && grassVariation == 0) {
//                 for(int j = 0; j < GRASS_VARIATIONS_COUNT; j++) {
//                     if(grassVariations[j] == variationIndex) {
//                         isGrassVariation = true;
//                         break;
//                     }
//                 }
//             }

//             bool isSnowVariation = false;
//             if(!snowRemoved && hasSnow && (variationIndex == "snow" || variationIndex == "grassSnow")) {
//                 isSnowVariation = true;
//             }

//             if(isSnowVariation) {
//                 variations[result.variationCount++] = variation;
//             }

//             if(shouldAddVegetation && isGrassVariation) {
//                 variations[result.variationCount++] = variation;
//                 grassVariation = variation;
//             }
//         }

//         result.surfaceBaseType = threadState->getTerrainBaseTypeIndex(threadState, chosenTerrainBaseTypeOdds->terrainBaseTypeIndex);
//         result.materialIndex = 0;

//         if(fillSurfaceBaseType != 0) {
//             result.surfaceBaseType = fillSurfaceBaseType;
//         }

//         if(grassVariation != 0) {
//             SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, grassVariation);
//             if(variationDefaults.materialIndex != 0) {
//                 result.materialIndex = variationDefaults.materialIndex;
// 			    result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;

//                 result.decalTypeIndex = variationDefaults.decalGroupIndex;
//             }
//         }

//         if(hasSnow) {
//             SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, grassVariation != 0 ? terrainVariation_grassSnow : terrainVariation_snow);
// 		    if(variationDefaults.materialIndex != 0) {
//                 result.materialIndex = variationDefaults.materialIndex;
// 			    result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;

//                 if(grassVariation != 0) {
//                     result.decalTypeIndex = variationDefaults.decalGroupIndex;
//                 } else {
//                     result.decalTypeIndex = 0;
//                 }
//             }
//         }
        
//         if(result.materialIndex == 0) {
//             SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, result.surfaceBaseType);
//             result.materialIndex = defaults.materialIndex;
//             result.decalTypeIndex = defaults.decalGroupIndex;
//             result.pathDifficultyIndex = defaults.pathDifficultyIndex;
//         }

//         if(baseAltitude + SP_METERS_TO_PRERENDER((double)digFillOffset) < SEA_LEVEL)
//         {
//             if(baseAltitude < DEEP_SEA_LEVEL)
//             {
//                 SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, terrainVariation_deepWater);
//                 result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;
//                 variations[result.variationCount++] = terrainVariation_deepWater;
//             }
//             else
//             {
//                 SPSurfaceTypeDefault variationDefaults = threadState->getSurfaceDefaultsForVariationType(threadState, terrainVariation_shallowWater);
//                 result.pathDifficultyIndex = variationDefaults.pathDifficultyIndex;
//                 variations[result.variationCount++] = terrainVariation_shallowWater;
//             }
//         }

//         // if(steepness < 1) {
//         //     SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, threadState->getTerrainBaseTypeIndex(threadState, "greenRock"));
//         //     result.materialIndex = defaults.materialIndex;
//         //     result.decalTypeIndex = defaults.decalGroupIndex;
//         //     result.pathDifficultyIndex = defaults.pathDifficultyIndex;
//         // } else {
//         //     SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, threadState->getTerrainBaseTypeIndex(threadState, "redRock"));
//         //     result.materialIndex = defaults.materialIndex;
//         //     result.decalTypeIndex = defaults.decalGroupIndex;
//         //     result.pathDifficultyIndex = defaults.pathDifficultyIndex;
//         // }

//         free(heightBiomesArray);

//         return result;
// }

#define ADD_OBJECT(__addType__)\
types[addedCount++] = __addType__;\
if(addedCount >= BIOME_MAX_GAME_OBJECT_COUNT_PER_SUBDIVISION)\
{\
	return addedCount;\
}

int spBiomeGetTransientGameObjectTypesForFaceSubdivision(
    SPBiomeThreadState* threadState,
	int incomingTypeCount,
	uint32_t* types,
	uint16_t* biomeTags,
	int tagCount,
	SPVec3 pointNormal, 
	SPVec3 noiseLoc, 
	uint64_t faceUniqueID, 
	int level, 
	double altitude, 
	double steepness,
	double riverDistance
) {

    int addedCount = 0;

    HeightBiome* heightBiomesArray = getHeightBiomeForPoint(noiseLoc);

    uint16_t heightBiomesSize = heightBiomesArray[0].biome;

    HeightBiome biome = heightBiomesArray[1];


    FloraDistribution distribution = defaultFloraDistribution;
    switch(biome.biome) {
        case fjords: distribution = fjordsFloraDistribution;break;
        case mesa: distribution = mesaFloraDistribution;break;
        case plains: distribution = plainsFloraDistribution;break;
        case swamp: distribution = swampFloraDistribution;break;
        case desertOasis: distribution = desertOasisFloraDistribution;break;
        case hillsides: distribution = hillsidesFloraDistribution;break;
        default: {
            return incomingTypeCount;
        }
    }

    for(int i = 0; i < distribution.floraOddsCount; i++) {
        FloraOdds* floraOdds = distribution.floraOdds[i];
        if(level == floraOdds->level) {
            double odds = floraOdds->odds;

            double random = spRandomValueForUniqueIDAndSeed(faceUniqueID, 60638 + i);
            
            if(altitude >= floraOdds->minAltitude && altitude < floraOdds->maxAltitude) {
                double altitudeModifier = rangeMap(floraOdds->minAltitude, floraOdds->maxAltitude, floraOdds->altitudeFrom, floraOdds->altitudeTo, altitude);
                if(odds != 0)
                    odds *= altitudeModifier;
                else
                    odds = altitudeModifier;
            }

            if(steepness >= floraOdds->minSteepness && steepness < floraOdds->maxSteepness) {
                double steepnessModifier = rangeMap(floraOdds->minSteepness, floraOdds->maxSteepness, floraOdds->steepnessFrom, floraOdds->steepnessTo, steepness);
                if(odds != 0)
                    odds *= steepnessModifier;
                else
                    odds = steepnessModifier;
            }

            if(riverDistance >= floraOdds->minRiverDistance && riverDistance < floraOdds->maxRiverDistance) {
                double riverDistanceModifier = rangeMap(floraOdds->minRiverDistance, floraOdds->maxRiverDistance, floraOdds->riverDistanceFrom, floraOdds->riverDistanceTo, riverDistance);
                if(odds != 0)
                    odds *= riverDistanceModifier;
                else
                    odds = riverDistanceModifier;
            }

            if(random < odds) {

                double noiseValueMed = spNoiseGet(threadState->spNoise1, spVec3Mul(noiseLoc, 92273.0), 2);
                long amount = floraOdds->density > 1 ? roundl(rangeMap(-1, 1, 1, floraOdds->density * 2, noiseValueMed)) : 1;

                for(int j = 0; j < amount; j++) {
                    int chosenIndex = spRandomIntegerValueForUniqueIDAndSeed(faceUniqueID, 3434 + (i * amount) + j, floraOdds->indexCount);
                    char* floraIndex = floraOdds->floraIndices[chosenIndex];
                    uint32_t gameObjectTypeIndex = threadState->getGameObjectTypeIndex(threadState, floraIndex);
                    ADD_OBJECT(gameObjectTypeIndex);
                }
            }
        }
    }

    return addedCount;
}