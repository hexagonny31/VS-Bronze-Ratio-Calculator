#include "calculations.h"
#include "hutils.h"

#include <iostream>
#include <cmath>
#include <string>

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
    result.component = {
        {def.component[0].metal},
        {def.component[1].metal},
        {def.component[2].metal}
    };

    for(int i = 0; i < 2; i++) {
        if(!def.component[i].metal.empty()) {
            result.component[i].percent = inputVar(
                "How much percentage of " + hUtils::text.toLowerCase(def.component[i].metal)
                + " do you want to put? (" + std::to_string(def.component[i].min)
                + "-" + std::to_string(def.component[i].max) + ")",
                def.component[i].min, def.component[i].max
            );
        }
    }
    
    result.component[2].percent = 100 - result.component[0].percent - result.component[1].percent;

    int maxIngots = calculateMaxIngots(result.component[0].percent, result.component[1].percent);
    result.ingots = inputVar(
        "How many ingots do you want to make? (1-"
        + std::to_string(maxIngots) + ")", 1, maxIngots
    );

    result.reqUnits = result.ingots * unitsPerIngot;  // just for show for now.
    result.reqBits = result.reqUnits / unitsPerBit;   // same for this.
    for (auto &c : result.component) c.bits = static_cast<int>(0.2 * result.ingots * c.percent);

    return result;
}