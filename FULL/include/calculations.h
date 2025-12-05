#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <string>
#include <vector>
#include <utility>
#include <optional>

constexpr int unitsPerBit = 5;      // soon to be removed whenever i feel like it.
constexpr int unitsPerIngot = 100;

//  i know it's a bit too much but i need a reason to practice structs and vectors.
//  the variables that is dependent to the user's input.
struct Component
{
    std::string metal;
    int min     = 0;
    int max     = 0;
    int percent = 0;
    int bits    = 0;
    std::pair<int, int> stacks;
};

//  the given values that create the alloy.
struct AlloyDefinition
{
    std::string name;                  // name of the alloy.
    std::vector<std::string> aliases;  // aliases for the alloy.
    std::vector<Component> component = std::vector<Component>(3);
};

std::optional<std::vector<AlloyDefinition>> parseAlloyTable(const std::string &fileName); 

//  the alloy that is influenced by the user's inputs.
struct Alloy
{
    std::string name; // e.g. "Bismuth Bronze", "Tin Bronze".
    int ingots;       // how many ingots requested.
    int reqUnits;     // total units needed.
    int reqBits;      // total ore bits needed.

    // a vector of percentages, metal names and ore bits.
    // the last element is the dependent variable.
    std::vector<Component> component = std::vector<Component>(3);

    void printAlloy();
};

//  this is where the calculation goes.
std::optional<Alloy> getComposition(const AlloyDefinition &def);

#endif