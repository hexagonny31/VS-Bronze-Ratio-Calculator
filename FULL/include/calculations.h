#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "hutils.h"
#include <string>

constexpr int unitsPerBit = 5;
constexpr int unitsPerIngot = 100;

struct Alloy
{
    std::string name; // e.g. "Bismuth Bronze", "Tin Bronze"
    int ingots;       // how many ingots requested
    int reqUnits;     // total units needed
    int reqBits;      // total ore bits needed

    // percentages
    int copperP = 0;  // common ore
    int tinP = 0;     // tin bronze
    int zincP = 0;    // bismuth bronze
    int bismuthP = 0; // bismuth bronze
    int goldP = 0;    // black bronze
    int silverP = 0;  // black bronze

    // ore bits
    int copperB;  // common ore
    int tinB;     // tin bronze
    int zincB;    // bismuth bronze
    int bismuthB; // bismuth bronze
    int goldB;    // black bronze
    int silverB;  // black bronze
};

std::string colorLabel(std::string label, const int color, bool use356 = true);

Alloy getTinBronze();
Alloy getBismuthBronze();
Alloy getBlackBronze();

#endif