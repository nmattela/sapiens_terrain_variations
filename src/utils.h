#ifndef utils
#define utils

#include <math.h>

#define PI 3.14159265358979323846

#define SP_PRERENDER_TO_METERS(_prerender_) ((_prerender_) * 8388608.0)

double rangeMap(double oldMin, double oldMax, double newMin, double newMax, double oldValue);

double rangeMapNoInvert(double oldMin, double oldMax, double newMin, double newMax, double oldValue);

double cutoffPointByPercentage(double from, double percentage);

double cosineSmoothing(double fromSource, double toSource, double fromTarget, double toTarget, double samplingPoint);

double slopeSmoothing(double m, double x, double b);

double smootheTowardsOcean(double modHeight, double vanillaHeight);

#endif