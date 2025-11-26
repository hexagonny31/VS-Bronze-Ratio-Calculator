#include "hutils.h"
#include "calculations.h"

std::vector<AlloyDefinition> alloyTable = {
    {
        colorLabel("Brass", 227),
        {"brass"},
        {
            { colorLabel("Copper", 208), 60, 70 },
            {""},
            { colorLabel("Zinc", 250) }
        }
    },
    {
        colorLabel("Tin Bronze", 227),
        {"tin bronze", "tin"},
        {
            { colorLabel("Copper", 208), 88, 92 },
            {""},
            { colorLabel("Tin", 94) }
        }
    },
    {
        colorLabel("Bismuth Bronze", 136),
        {"bismuth bronze", "bismuth", "lead-free", "bismuth brass"},
        {
            { colorLabel("Zinc", 249),    20, 30 },
            { colorLabel("Bismuth", 144), 10, 20 },
            { colorLabel("Copper", 208) }
        }
    },
    { 
        colorLabel("Black Bronze", 90),
        {"hepatizon", "black bronze", "black", "dark bronze", "dark"},
        {
            { colorLabel("Gold", 220),   8, 16 },
            { colorLabel("Silver", 252), 8, 16 },
            { colorLabel("Copper", 208) }
        }
    },
    {
        colorLabel("Molybdochalkos", 227),
        {"molybdochalkos", "leaded copper"},
        {
            { colorLabel("Lead", 250), 88, 92 },
            {""},
            { colorLabel("Copper", 208) },
        }
    },
    {
        colorLabel("Lead Solder", 227),
        { "lead solder", "tin-lead", "leaded solder" },
        {
            { colorLabel("Lead", 250), 45, 55 },
            {""},
            { colorLabel("Tin", 94) }
        }
    },
    {
        colorLabel("Silver Solder", 251),
        { "silver solder", "silver blaze", "hard soldering" },
        {
            {colorLabel("Silver", 252), 40, 50},
            {""},
            {colorLabel("Tin", 94)}
        }
    },
    {
        colorLabel("Cupronickel", 221),
        { "cupronickel", "copper-nickel" },
        {
            { colorLabel("Copper", 208), 65, 75 },
            {""},
            { colorLabel("Nickel", 215) }
        }
    },
    { 
        colorLabel("Electrum", 227),
        { "electrum", "elec" },
        {
            { colorLabel("Silver", 252), 40, 60 },
            {""},
            { colorLabel("Gold", 220) }
        }
    }
};