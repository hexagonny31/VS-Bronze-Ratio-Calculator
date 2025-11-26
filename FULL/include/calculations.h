#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <string>
#include <vector>
#include "alloy_definition.h"

constexpr int unitsPerBit = 5;      // soon to be removed whenever i feel like it.
constexpr int unitsPerIngot = 100;
extern std::vector<AlloyDefinition> alloyTable;  // the given variables in a table.

//  the alloy that is influenced by the user's inputs.
struct Alloy
{
    std::string name; // e.g. "Bismuth Bronze", "Tin Bronze"
    int ingots;       // how many ingots requested
    int reqUnits;     // total units needed
    int reqBits;      // total ore bits needed

    // a vector of percentages, metal names and ore bits.
    // the last element is the dependent variable.
    std::vector<Component> component = std::vector<Component>(3);

    void printAlloy();
};

Alloy getComposition(const AlloyDefinition &def);

#endif