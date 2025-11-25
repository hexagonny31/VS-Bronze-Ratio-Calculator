#ifndef ALLOY_DEFINITION_H
#define ALLOY_DEFINITION_H

#include <string>

struct AlloyDefinition
{
    std::string name;
    std::string metal_name_1;
    std::string metal_name_2;   // empty when unused
    std::string dependent_name;

    int metal_range_1_min;
    int metal_range_1_max;

    int metal_range_2_min;
    int metal_range_2_max;
};

#endif