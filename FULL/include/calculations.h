#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "hutils.h"
#include <string>

constexpr int unitsPerBit = 5;
constexpr int unitsPerIngot = 100;

struct Alloy {
    std::string name;   // e.g. "Bismuth Bronze", "Tin Bronze"
    int ingots;         // how many ingots requested
    int requiredUnits;  // total units needed
    int requiredBits;   // total ore bits needed

    // percentages
    int copperPercent = 0;  // common ore
    int tinPercent = 0;     // tin bronze
    int zincPercent = 0;    // bismuth bronze
    int bismuthPercent = 0; // bismuth bronze
    int goldPercent = 0;    // black bronze
    int silverPercent = 0;  // black bronze

    // ore bits
    int copperBits;     // common ore
    int tinBits;        // tin bronze
    int zincBits;       // bismuth bronze
    int bismuthBits;    // bismuth bronze
    int goldBits;       // black bronze
    int silverBits;     // black bronze
};

std::string colorLabel(std::string label, const int color, bool use356 = true);

Alloy getTinBronzeComposition();
Alloy getBismuthBronzeComposition();
Alloy getBlackBronzeComposition();

#endif