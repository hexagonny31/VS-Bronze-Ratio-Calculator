#include "hutils.h"
#include "calculations.h"

std::vector<AlloyDefinition> alloyTable = {
    {
        colorLabel("Tin Bronze", 227),
        colorLabel("Copper", 208),
        "",
        colorLabel("Tin", 94),
        88, 92,
        0, 0
    },
    {
        colorLabel("Bismuth Bronze", 136),
        colorLabel("Zinc", 250),
        colorLabel("Bismuth", 144),
        colorLabel("Copper", 208),
        20, 30,
        10, 20 
    },
    { 
        colorLabel("Black Bronze", 90),
        colorLabel("Gold", 220),
        colorLabel("Silver", 252),
        colorLabel("Copper", 208),
        8, 16,
        8, 16 
    }
};