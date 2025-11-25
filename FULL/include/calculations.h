#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <string>
#include <vector>
#include "alloy_definition.h"

constexpr int unitsPerBit = 5;
constexpr int unitsPerIngot = 100;
extern std::vector<AlloyDefinition> alloyTable;

struct Alloy
{
    std::string name; // e.g. "Bismuth Bronze", "Tin Bronze"
    int ingots;       // how many ingots requested
    int reqUnits;     // total units needed
    int reqBits;      // total ore bits needed

    // percentages
    int P_1 = 0;  // independent
    int P_2 = 0;  // independent
    int P_3 = 0;  // dependent

    // ore bits
    int B_1 = 0;  // same for here.
    int B_2 = 0;
    int B_3 = 0;

    void printAlloy(const AlloyDefinition &def);
};

Alloy getComposition(const AlloyDefinition &def);

#endif