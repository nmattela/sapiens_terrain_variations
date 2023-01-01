#include "SPBiome.h"
#include "heightBiomes.h"

// void spBiomeGetTagsForPoint(SPBiomeThreadState* threadState,
//                             uint16_t* tagsOut,
//                             int* tagCountOut,
//                             SPVec3 pointNormal,
//                             SPVec3 noiseLoc,
//                             double altitude,
//                             double steepness,
//                             double riverDistance,
//                             double temperatureSummer,
//                             double temperatureWinter,
//                             double rainfallSummer,
//                             double rainfallWinter)
// {
//     //*tagCountOut = 0;
//     *tagCountOut = threadState->getBiomeTag(threadState, "rainforest");
//     *tagsOut = 0;
// }

// static uint32_t terrainBaseType_debug_fjords;
// static uint32_t terrainVariation_debug_fjords;
// static uint32_t terrainBaseType_debug_mesa;
// static uint32_t terrainVariation_debug_mesa;
// static uint32_t terrainBaseType_debug_plains;
// static uint32_t terrainVariation_debug_plains;
// static uint32_t terrainBaseType_debug_swamp;
// static uint32_t terrainVariation_debug_swamp;
// static uint32_t terrainBaseType_debug_desert_oasis;
// static uint32_t terrainVariation_debug_desert_oasis;
// static uint32_t terrainBaseType_debug_hillsides;
// static uint32_t terrainVariation_debug_hillsides;

// void spBiomeInit(SPBiomeThreadState* threadState) {
//     terrainBaseType_debug_fjords = threadState->getTerrainBaseTypeIndex(threadState, "debug_fjords");
//     terrainVariation_debug_fjords = threadState->getTerrainVariation(threadState, "debug_fjords");
//     terrainBaseType_debug_mesa = threadState->getTerrainBaseTypeIndex(threadState, "debug_mesa");
//     terrainVariation_debug_mesa = threadState->getTerrainVariation(threadState, "debug_mesa");
//     terrainBaseType_debug_plains = threadState->getTerrainBaseTypeIndex(threadState, "debug_plains");
//     terrainVariation_debug_plains = threadState->getTerrainVariation(threadState, "debug_plains");
//     terrainBaseType_debug_swamp = threadState->getTerrainBaseTypeIndex(threadState, "debug_swamp");
//     terrainVariation_debug_swamp = threadState->getTerrainVariation(threadState, "debug_swamp");
//     terrainBaseType_debug_desert_oasis = threadState->getTerrainBaseTypeIndex(threadState, "debug_desert_oasis");
//     terrainVariation_debug_desert_oasis = threadState->getTerrainVariation(threadState, "debug_desert_oasis");
//     terrainBaseType_debug_hillsides = threadState->getTerrainBaseTypeIndex(threadState, "debug_hillsides");
//     terrainVariation_debug_hillsides = threadState->getTerrainVariation(threadState, "debug_hillsides");
// }

// SPSurfaceTypeResult spBiomeGetSurfaceTypeForPoint(SPBiomeThreadState* threadState,
//                                                   SPSurfaceTypeResult incomingType,
//                                                   uint16_t* tags,
//                                                   int tagCount,
//                                                   uint32_t* modifications,
//                                                   int modificationCount,
//                                                   uint32_t fillGameObjectTypeIndex,
//                                                   int16_t digFillOffset,
//                                                   uint32_t* variations,
//                                                   SPVec3 pointNormal, 
//                                                   SPVec3 noiseLoc, 
//                                                   double baseAltitude,
//                                                   double steepness,
//                                                   double riverDistance,
//                                                   int seasonIndex) {

//     SPSurfaceTypeResult result = incomingType;

//     HeightBiome* heightBiomesArray = getHeightBiomeForPoint(noiseLoc);

//     uint16_t heightBiomesSize = heightBiomesArray[0].biome;

//     //spLog("In biome.c, size is: %u", (unsigned int)heightBiomesSize);

//     if(heightBiomesSize == 1) {
//         HeightBiome heightBiome = heightBiomesArray[1];

//         switch(heightBiome.biome) {
//             case fjords: {
//                 result.surfaceBaseType = terrainBaseType_debug_fjords;
//                 break;
//             }
//             case mesa: {
//                 result.surfaceBaseType = terrainBaseType_debug_mesa;
//                 break;
//             }
//             case plains: {
//                 result.surfaceBaseType = terrainBaseType_debug_plains;
//                 break;
//             }
//             case swamp: {
//                 result.surfaceBaseType = terrainBaseType_debug_swamp;
//                 break;
//             }
//             case desertOasis: {
//                 result.surfaceBaseType = terrainBaseType_debug_desert_oasis;
//                 break;
//             }
//             case hillsides: {
//                 result.surfaceBaseType = terrainBaseType_debug_hillsides;
//                 break;
//             }
//             default: {
//                 break;
//             }
//         }

//         SPSurfaceTypeDefault defaults = threadState->getSurfaceDefaultsForBaseType(threadState, result.surfaceBaseType);
//         result.materialIndex = defaults.materialIndex;
//         result.decalTypeIndex = defaults.decalGroupIndex;
//         result.pathDifficultyIndex = defaults.pathDifficultyIndex;
//         free(heightBiomesArray);
//         return result;

//     } else {
//         free(heightBiomesArray);
//         return result;
//     }

// }












// SPSurfaceTypeResult generateFjords(
//     SPBiomeThreadState* threadState,
//     SPSurfaceTypeResult incomingType,
//     uint16_t* tags,
//     int tagCount,
//     uint32_t* modifications,
//     int modificationCount,
//     uint32_t fillGameObjectTypeIndex,
//     int16_t digFillOffset,
//     uint32_t* variations,
//     SPVec3 pointNormal, 
//     SPVec3 noiseLoc, 
//     double baseAltitude,
//     double steepness,
//     double riverDistance,
//     int seasonIndex
// ) {
//         SPSurfaceTypeResult result = incomingType;

//         double noise = spNoiseGet(threadState->spNoise1, spVec3Mul(noiseLoc, 45999.0), 3);



//         return result;
// }

// SPSurfaceTypeResult spBiomeGetSurfaceTypeForPoint(
//     SPBiomeThreadState* threadState,
//     SPSurfaceTypeResult incomingType,
//     uint16_t* tags,
//     int tagCount,
//     uint32_t* modifications,
//     int modificationCount,
//     uint32_t fillGameObjectTypeIndex,
//     int16_t digFillOffset,
//     uint32_t* variations,
//     SPVec3 pointNormal, 
//     SPVec3 noiseLoc, 
//     double baseAltitude,
//     double steepness,
//     double riverDistance,
//     int seasonIndex
// ) {
//         SPSurfaceTypeResult result = incomingType;

//         HeightBiome* heightBiomesArray = getHeightBiomeForPoint(noiseLoc);

//         uint16_t heightBiomesSize = heightBiomesArray[0].biome;



//         free(heightBiomesArray);

//         return result;
// }
