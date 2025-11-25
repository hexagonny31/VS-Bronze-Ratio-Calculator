#include "calculations.h"
#include "hutils.h"

#include <iostream>
#include <cmath>
#include <string>

std::string colorLabel(std::string label, const int color, bool use356) {
    return hUtils::text.fgColor(color, use356) + label + hUtils::text.defaultText();
}

int calculateBits(int metal, int maxBits) {
    return static_cast<int>(maxBits * (metal / 100.0));
}

int calculateMaxIngots(int metal1, int metal2 = 0) {
    int ingots = 0;
    int m1Slots, m2Slots, m3Slots;
    while(true) {
        ingots++;
        m1Slots = ceil((0.2 * metal1 * ingots) / 128.0);
        m2Slots = (metal2 != 0) ? ceil((0.2 * metal2 * ingots) / 128.0) : 0;
        m3Slots = ceil((0.2 * (100 - metal1 - metal2) * ingots) / 128.0);
        if((m1Slots + m2Slots + m3Slots) > 4) {
            return ingots - 1;
        }
    }
}

int inputVar(std::string prompt, int min, int max) {
    int input;
    do {
        std::cout << prompt << "\n> ";
        std::cin >> input;
        if(input < min) {
            std::cout << colorLabel("Input is too low!", 31, false);
            hUtils::sleep(2000);
            hUtils::text.clearAbove(2);
        } else if(input > max) {
            std::cout << colorLabel("Input is too high!", 31, false);
            hUtils::sleep(2000);
            hUtils::text.clearAbove(2);
        }
    } while(input < min || input > max);

    return input;
}

Alloy getComposition(const AlloyDefinition &def) {
    Alloy result;

    result.name = def.name;

    result.P_1 = inputVar("How much percentage of " + hUtils::text.toLowerCase(def.metal_name_1)
                          + " do you want to put? (" + std::to_string(def.metal_range_1_min)
                          + "-" + std::to_string(def.metal_range_1_max) + ")",
                          def.metal_range_1_min, def.metal_range_1_max);
    if(!def.metal_name_2.empty()) {
        result.P_2 = inputVar("How much percentage of " + hUtils::text.toLowerCase(def.metal_name_2)
                              + " do you want to put? (" + std::to_string(def.metal_range_2_min)
                              + "-" + std::to_string(def.metal_range_2_max) + ")",
                              def.metal_range_2_min, def.metal_range_2_max);
    }
    result.P_3 = 100 - result.P_1 - result.P_2;

    int maxIngots = calculateMaxIngots(result.P_1, result.P_2);
    result.ingots = inputVar("How many ingots do you want to make? (1-" + std::to_string(maxIngots) + ")", 1, maxIngots);
    result.reqUnits = result.ingots * unitsPerIngot;  // just for show for now.
    result.reqBits = result.reqUnits / unitsPerBit;   // same for this.

    result.B_1 = 0.2 * result.ingots * result.P_1;
    result.B_2 = 0.2 * result.ingots * result.P_2;
    result.B_3 = 0.2 * result.ingots * (100 - result.P_1 - result.P_2);

    return result;
}