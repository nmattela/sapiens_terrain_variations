#ifndef heightBiomesFlora
#define heightBiomesFlora

#include "heightBiomesFlora.h"

struct FloraOdds;
typedef struct FloraOdds {
    int indexCount;
    char** floraIndices;

    int level;

    double odds;
    int density;

    double altitudeFrom;
    double altitudeTo;
    double minAltitude;
    double maxAltitude;

    double steepnessFrom;
    double steepnessTo;
    double minSteepness;
    double maxSteepness;

    double riverDistanceFrom;
    double riverDistanceTo;
    double minRiverDistance;
    double maxRiverDistance;


} FloraOdds;

//----------------//
//--- DEFAULTS ---//
//----------------//

static FloraOdds defaultPineBig = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "pineBig1"
    },
    .level = 15,

    .odds = 0.0625,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultAspenBig = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "aspenBig1"
    },
    .level = 15,

    .odds = 0.0625,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultWillow = {
    .indexCount = 2,
    .floraIndices = (char*[]){
        "willow1",
        "willow2"
    },
    .level = 16,

    .odds = 0,
    .density = 3,

    .altitudeFrom = 0,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0.05,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};

static FloraOdds defaultRock = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "rock",
        "rockSmall",
        "rockLarge",
    },
    .level = 18,

    .odds = 0.05,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultRedRock = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "redRock",
        "redRockSmall",
        "redRockLarge",
    },
    .level = 18,

    .odds = 0.0003,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 5,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultGreenRock = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "greenRock",
        "greenRockSmall",
        "greenRockLarge",
    },
    .level = 18,

    .odds = 0.0001,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultLimestoneRock = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "limestoneRock",
        "limestoneRockSmall",
        "limestoneRockLarge",
    },
    .level = 18,

    .odds = 0.02,
    .density = 6,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultFlint = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "flint",
    },
    .level = 18,

    .odds = 0.02,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultClay = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "clay",
    },
    .level = 18,

    .odds = 0.03,
    .density = 4,

    .altitudeFrom = 1,
    .altitudeTo = 0.7,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 2,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds defaultBirchBranch = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "birchBranch",
    },
    .level = 20,

    .odds = 0.003,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 0.3,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultPineBranch = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "pineBranch",
    },
    .level = 20,

    .odds = 0.003,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 0.3,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultWillowBranch = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "willowBranch"
    },
    .level = 20,

    .odds = 0,
    .density = 2,

    .altitudeFrom = 0,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0.003,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};

static FloraOdds defaultBambooBranch = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "bambooBranch",
    },
    .level = 20,

    .odds = 0.003,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 0.3,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultDeadAlpaca = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "deadAlpaca",
    },
    .level = 19,

    .odds = 0.00075,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 1,
    .maxAltitude = 1,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultDeadMammoth = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "deadMammoth",
    },
    .level = 19,

    .odds = 0.000125,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 1,
    .maxAltitude = 1,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultBone = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "bone",
    },
    .level = 19,

    .odds = 0.00075,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 1,
    .maxAltitude = 1,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultRaspberryBush = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "raspberryBush",
    },
    .level = 19,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultGooseberryBush = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "gooseberryBush",
    },
    .level = 19,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultAppleTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "appleTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultOrangeTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "orangeTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultPeachTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "peachTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultBananaTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "bananaTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultCoconutTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "coconutTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultElderBerryTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "elderberryTree",
    },
    .level = 18,

    .odds = 0.0012,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultBeetrootPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "beetrootPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.8,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultPumpkinPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "pumpkinPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 0.4,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultWheatPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "wheatPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 0.4,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultFlaxPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "flaxPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 0.4,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultPoppyPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "poppyPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.8,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultGarlicPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "garlicPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultAloePlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "aloePlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultEchinaceaPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "echinaceaPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultMarigoldPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "marigoldPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultGingerPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "gingerPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds defaultTurmericPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "turmericPlant",
    },
    .level = 19,

    .odds = 0.0027,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 1.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 1.3,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

//--------------------//
//--- END DEFAULTS ---//
//--------------------//

//--------------//
//--- FJORDS ---//
//--------------//

static FloraOdds fjordsWheatPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "wheatPlant",
    },
    .level = 19,

    .odds = 0.0024,
    .density = 5,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1.7,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds fjordsFlaxPlant = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "flaxPlant",
    },
    .level = 19,

    .odds = 0.0024,
    .density = 3,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1.7,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds fjordsAspen = {
    .indexCount= 3,
    .floraIndices = (char*[]){
        "aspen1",
        "aspen2",
        "aspen3"
    },
    .level = 16,

    .odds = 0.15,
    .density = 6,

    .altitudeFrom = 0.7,
    .altitudeTo = 2.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds fjordsPine = {
    .indexCount= 4,
    .floraIndices = (char*[]){
        "pine1",
        "pine2",
        "pine3",
        "pine4",
    },
    .level = 17,

    .odds = 0.25,
    .density = 20,

    .altitudeFrom = 1,
    .altitudeTo = 0.2,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 30,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

//------------------//
//--- END FJORDS ---//
//------------------//

//------------//
//--- MESA ---//
//------------//

static FloraOdds mesaRockPebble = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "rock",
        "rockSmall",
        "rockLarge",
    },
    .level = 19,

    .odds = 0.05,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 20,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaRedRock = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "redRock",
        "redRockSmall",
        "redRockLarge",
    },
    .level = 18,

    .odds = 0.017,
    .density = 3,

    .altitudeFrom = 1,
    .altitudeTo = 5,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 8,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaGreenRock = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "greenRock",
        "greenRockSmall",
        "greenRockLarge",
    },
    .level = 18,

    .odds = 0.021,
    .density = 5,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 12,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaLimestoneRock = {
    .indexCount = 3,
    .floraIndices = (char*[]){
        "limestoneRock",
        "limestoneRockSmall",
        "limestoneRockLarge",
    },
    .level = 19,

    .odds = 0.04,
    .density = 6,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 15,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaFlint = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "flint",
    },
    .level = 20,

    .odds = 0.09,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 4,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaClayBall = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "clay",
    },
    .level = 19,

    .odds = 0.05,
    .density = 4,

    .altitudeFrom = 1,
    .altitudeTo = 0.7,
    .minAltitude = 0,
    .maxAltitude = 0.01,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 2,

    .riverDistanceFrom = 4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.0003,
};

static FloraOdds mesaBone = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "bone",
    },
    .level = 19,

    .odds = 0.0075,
    .density = 1,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 1,
    .maxAltitude = 1,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

//----------------//
//--- END MESA ---//
//----------------//

//--------------//
//--- PLAINS ---//
//--------------//

static FloraOdds plainsAppleTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "appleTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsOrangeTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "orangeTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsPeachTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "peachTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsElderBerryTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "elderberryTree",
    },
    .level = 18,

    .odds = 0.002,
    .density = 4,

    .altitudeFrom = 2,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.001,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

static FloraOdds plainsForest = {
    .indexCount= 11,
    .floraIndices = (char*[]){
        "birch1",
        "aspen1",
        "appleTree",
        "birch2",
        "aspen2",
        "orangeTree",
        "birch3",
        "aspen3",
        "peachTree",
        "birch4",
        "elderberryTree",
    },
    .level = 16,

    .odds = 0.042,
    .density = 35,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 0,
    .minSteepness = 0.2,
    .maxSteepness = 6,

    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,
};

static FloraOdds plainsSunflower = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "sunflower"
    },
    .level = 19,

    .odds = 0.037,
    .density = 11,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0.4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.001,    
};

//------------------//
//--- END PLAINS ---//
//------------------//

//-------------//
//--- SWAMP ---//
//-------------//

static FloraOdds swampWillow = {
    .indexCount = 2,
    .floraIndices = (char*[]){
        "willow1",
        "willow2"
    },
    .level = 17,

    .odds = 0.056,
    .density = 3,

    .altitudeFrom = 10,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0.0000002,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 4,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};

static FloraOdds swampWillowBranch = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "willowBranch"
    },
    .level = 20,

    .odds = 0.056,
    .density = 2,

    .altitudeFrom = 1,
    .altitudeTo = 1,
    .minAltitude = 0,
    .maxAltitude = 0,

    .steepnessFrom = 1,
    .steepnessTo = 1,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.01,
};

//-----------------//
//--- END SWAMP ---//
//-----------------//

//--------------------//
//--- DESERT OASIS ---//
//--------------------//

static FloraOdds desertOasisBananaTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "bananaTree"
    },
    .level = 19,

    .odds = 0,
    .density = 3,

    .altitudeFrom = 0.32,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.0000002,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.00001,
};

static FloraOdds desertOasisCoconutTree = {
    .indexCount = 1,
    .floraIndices = (char*[]){
        "coconutTree"
    },
    .level = 18,

    .odds = 0,
    .density = 6,

    .altitudeFrom = 0.4,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.0000002,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 1,
    .riverDistanceTo = 1,
    .minRiverDistance = 0,
    .maxRiverDistance = 0.00001,
};

//------------------------//
//--- END DESERT OASIS ---//
//------------------------//

//-----------------//
//--- HILLSIDES ---//
//-----------------//

static FloraOdds hillsidesForest = {
    .indexCount= 11,
    .floraIndices = (char*[]){
        "birch1",
        "aspen1",
        "appleTree",
        "birch2",
        "aspen2",
        "orangeTree",
        "birch3",
        "aspen3",
        "peachTree",
        "birch4",
        "elderberryTree",
    },
    .level = 16,

    .odds = 0,
    .density = 35,

    .altitudeFrom = 1000,
    .altitudeTo = 0,
    .minAltitude = 0,
    .maxAltitude = 0.000005,

    .steepnessFrom = 0,
    .steepnessTo = 0,
    .minSteepness = 0,
    .maxSteepness = 0,

    .riverDistanceFrom = 0,
    .riverDistanceTo = 0,
    .minRiverDistance = 0,
    .maxRiverDistance = 0,
};

//---------------------//
//--- END HILLSIDES ---//
//---------------------//

struct FloraDistribution;
typedef struct FloraDistribution {
    uint16_t biome;
    int floraOddsCount;
    FloraOdds** floraOdds;
} FloraDistribution;

static FloraOdds* defaultFloraOdds[] = {
    &defaultPineBig,
    &defaultAspenBig,
    &defaultWillow,
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultFlint,
    &defaultBirchBranch,
    &defaultPineBranch,
    &defaultWillowBranch,
    &defaultBambooBranch,
    &defaultClay,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone,
};
static FloraDistribution defaultFloraDistribution = {
    unset,
    16,
    defaultFloraOdds
};

static FloraOdds* fjordsFloraOdds[] = {
    &defaultPineBig,
    &defaultAspenBig,
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultFlint,
    &defaultPineBranch,
    &defaultClay,
    &defaultDeadMammoth,
    &defaultBone,
    &defaultAppleTree,
    &defaultElderBerryTree,
    &defaultRaspberryBush,
    &defaultGooseberryBush,
    &fjordsWheatPlant,
    &fjordsFlaxPlant,
    &defaultPoppyPlant,
    &defaultGarlicPlant,
    &fjordsAspen,
    &fjordsPine,
};
static FloraDistribution fjordsFloraDistribution = {
    fjords,
    21,
    fjordsFloraOdds
};

static FloraOdds* mesaFloraOdds[] = {
    &mesaRockPebble,
    &mesaRedRock,
    &mesaGreenRock,
    &mesaLimestoneRock,
    &mesaFlint,
    &mesaClayBall,
    &defaultDeadAlpaca,
    &mesaBone,
    &defaultGingerPlant,
    &defaultAloePlant,
    &defaultMarigoldPlant,
    &defaultTurmericPlant,
    &defaultPineBranch,
};
static FloraDistribution mesaFloraDistribution = {
    mesa,
    13,
    mesaFloraOdds
};

static FloraOdds* plainsFloraOdds[] = {
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultClay,
    &defaultFlint,
    &plainsForest,
    &plainsSunflower,
    &defaultRaspberryBush,
    &defaultGooseberryBush,
    &defaultBeetrootPlant,
    &defaultPumpkinPlant,
    &defaultWheatPlant,
    &defaultFlaxPlant,
    &defaultPoppyPlant,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone,
};
static FloraDistribution plainsFloraDistribution = {
    plains,
    15,
    plainsFloraOdds
};

static FloraOdds* swampFloraOdds[] = {
    &defaultRock,
    &defaultRedRock,
    &defaultGreenRock,
    &defaultLimestoneRock,
    &defaultClay,
    &defaultFlint,
    &swampWillow,
    &swampWillowBranch,
    &defaultPumpkinPlant,
    &defaultElderBerryTree,
    &defaultFlaxPlant,
    &defaultPoppyPlant,
    &defaultGooseberryBush,
    &defaultEchinaceaPlant,
    &defaultGarlicPlant,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone,
};
static FloraDistribution swampFloraDistribution = {
    swamp,
    18,
    swampFloraOdds
};

static FloraOdds* desertOasisFloraOdds[] = {
    &defaultRock,
    &defaultGreenRock,
    &defaultRedRock,
    &defaultAloePlant,
    &defaultMarigoldPlant,
    &defaultGingerPlant,
    &defaultTurmericPlant,
    &mesaBone,
    &defaultDeadAlpaca,
    &desertOasisBananaTree,
    &desertOasisCoconutTree
};
static FloraDistribution desertOasisFloraDistribution = {
    desertOasis,
    11,
    desertOasisFloraOdds
};

static FloraOdds* hillsidesFloraOdds[] = {
    &defaultRock,
    &defaultLimestoneRock,
    &defaultFlint,
    &defaultWheatPlant,
    &defaultFlaxPlant,
    &defaultBirchBranch,
    &hillsidesForest,
    &defaultDeadAlpaca,
    &defaultDeadMammoth,
    &defaultBone
};
static FloraDistribution hillsidesFloraDistribution = {
    hillsides,
    10,
    hillsidesFloraOdds
};

#endif