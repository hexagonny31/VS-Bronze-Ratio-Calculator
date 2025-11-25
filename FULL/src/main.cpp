#include "calculations.h"
#include "hutils.h"
#include "alloy_definition.h"

#include <iostream>

void Alloy::printAlloy(const AlloyDefinition &def) {
    hUtils::text.clearAll();
    std::cout << "---  Prerequisites (" << name << ") ---\n";
    std::cout << "Units per " << ingots << " ingot/s = " << reqUnits << " units\n";
    std::cout << "Required ore bits = " << reqBits << " ore bits\n\n";
    std::cout << "---  Final Alloy Composition  ---\n";

    if (P_1 > 0)
        std::cout << def.metal_name_1   << " - " << B_1 << " ore bits (" << P_1 << "%)\n";
    if (P_2 > 0)
        std::cout << def.metal_name_2   << " - " << B_2 << " ore bits (" << P_2 << "%)\n";
    if (P_3 > 0)
        std::cout << def.dependent_name << " - " << B_3 << " ore bits (" << P_3 << "%)\n";
    std::cout << '\n';
}

int main() {
    Alloy alloy;
    
    std::string input;
    int index;
    
    while(true) {    
        std::cout << "What alloy do you want to calculate?\n";
        std::cout << colorLabel("Tin Bronze", 227) << " | "
                  << colorLabel("Bismuth Bronze", 136) << " | "
                  << colorLabel("Black Bronze", 90) << " | Exit\n> ";
        std::getline(std::cin, input);
        input = hUtils::text.toLowerCase(input);

        if (input == "exit") break;

        if (input == "tin bronze" || input == "tin") {
            index = 0;
        }
        else if (input == "bismuth bronze" || input == "bismuth") {
            index = 1;
        }
        else if(input == "black bronze" || input == "black") {
            index = 2;
        }
        else {
            std::cout << colorLabel("Unknown alloy type.", 31, false);
            hUtils::sleep(2000);
            hUtils::text.clearAbove(4);
            continue;
        }
        alloy = getComposition(alloyTable[index]);

        alloy.printAlloy(alloyTable[index]);
        hUtils::pause(true);
        hUtils::text.clearAll();
    }
    return 0;
}