#ifndef ALLOY_DEFINITION_H
#define ALLOY_DEFINITION_H

#include <string>
#include <vector>

//  i know it's a bit too much but i need a reason to practice structs and vectors.
//  the variables that is dependent to the user's input.
struct Component
{
    std::string metal;
    int min     = 0;
    int max     = 0;
    int percent = 0;
    int bits    = 0;
};

//  the given values that create the alloy.
struct AlloyDefinition
{
    std::string name;  // name of the alloy.
    std::vector<std::string> aliases;  // aliases for the alloy.
    std::vector<Component> component;
};

#endif