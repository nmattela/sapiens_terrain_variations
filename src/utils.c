#include "utils.h"

double rangeMap(double oldMin, double oldMax, double newMin, double newMax, double oldValue) {

    if(oldMin > oldMax) {
        double temp = oldMin;
        oldMin = oldMax;
        oldMax = temp;
    }

    if(oldValue <= oldMin) {
        return newMin;
    }
    if(oldValue >= oldMax) {
        return newMax;
    }

    double oldRange = oldMax - oldMin;
    double newRange = newMax - newMin;
    double newValue = (((oldValue - oldMin) * newRange) / oldRange) + newMin;
    return newValue;
}

double rangeMapNoInvert(double oldMin, double oldMax, double newMin, double newMax, double oldValue) {
    if(newMin > newMax) {
        double temp = newMin;
        newMin = newMax;
        newMax = temp;
    }
    return rangeMap(oldMin, oldMax, newMin, newMax, oldValue);
}

/**
 * Take an x from a slop such that the integral [from, x] is equal to percentage
 * 
 * slope is f(x) = 1 - x
 * L = longer side of our derivative square (the "from" of our derivative)
 * l = smaller side of our derivative square (the "to" of our derivative) <- unknown
 * b = the width of our derivative square
 * A = the surface area of our derivative square
*/
double cutoffPointByPercentage(double from, double percentage) {
    double A = percentage * 0.5;
    double L = 1 - from;

    double b = (A / L) - (((A / L)*(A / L))/2);

    return from + b;
}

/**
 * Get the height at a specific position of half a cosine wave
 * @param fromSource smallest value that the provided sampling point can be
 * @param toSource largest value that the provided sampling point can be
 * @param fromTarget smallest value the sine wave can be
 * @param toTarget largest value the sine wave can be
 * @param samplingPoint point to sample from
 * 
*/
double cosineSmoothing(double fromSource, double toSource, double fromTarget, double toTarget, double samplingPoint) {
    double cossed = (cos(PI + ((samplingPoint - fromSource) * PI / toSource)) + 1) / 2;
    double newRange = toTarget - fromTarget;
    double newValue = (cossed * newRange) + fromTarget;
    return newValue;
}

/**
 * Get the height value at a specific position on a slope
 * 
 * @param m Steepness of the slope. If you move x by 1 unit to the right, how much does the y value increase/decrease?
 * @param x Position on the slope to sample from
 * @param b The height value when x=0. Note that this is not necessarily equal to saying "the height value at the start of your slope" as the start of your slope can be in the negatives
 * 
 * @returns The height at the sampled position on the slope
 * 
*/
double slopeSmoothing(double m, double x, double b) {
    return m * x + b;
}

/**
 * Smoothe off a modHeight towards a vanillaHeight to preserve vanilla oceans
 * 
 * @params modHeight mod height
 * @params vanillaHeight vanilla height
 * 
 * @returns a value between modHeight and vanillaHeight (latter being a negative value). If vanillaHeight is below -50, then it auto-returns the vanillaHeight
 * 
*/
double smootheTowardsOcean(double modHeight, double vanillaHeight) {
    return rangeMapNoInvert(0, -50, modHeight, vanillaHeight, vanillaHeight);
}