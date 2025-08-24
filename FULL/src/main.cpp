#include "calculations.h"
#include "hutils.h"

#include <iostream>

void printAlloy(const Alloy &a) {
    hUtils::text.clearAll();
    std::cout << "---  Prerequisites (" << a.name << ") ---\n";
    std::cout << "Units per " << a.ingots << " ingot/s = " << a.requiredUnits << " units\n";
    std::cout << "Required ore bits = " << a.requiredBits << " ore bits\n\n";
    std::cout << "---  Final Alloy Composition  ---\n";

    if (a.copperPercent > 0)
        std::cout << colorLabel("Copper", 208) << "  - " << a.copperBits << " ore bits (" << a.copperPercent << "%)\n";
    if (a.tinPercent > 0)
        std::cout << colorLabel("Tin", 94) << "     - " << a.tinBits << " ore bits (" << a.tinPercent << "%)\n";
    if (a.zincPercent > 0)
        std::cout << colorLabel("Zinc", 250) << "    - " << a.zincBits << " ore bits (" << a.zincPercent << "%)\n";
    if (a.bismuthPercent > 0)
        std::cout << colorLabel("Bismuth", 144) << " - " << a.bismuthBits << " ore bits (" << a.bismuthPercent << "%)\n";
    if (a.goldPercent > 0)
        std::cout << colorLabel("Gold", 220) << "    - " << a.goldBits << " ore bits (" << a.goldPercent << "%)\n";
    if (a.silverPercent > 0)
        std::cout << colorLabel("Silver", 252) << "  - " << a.silverBits << " ore bits (" << a.silverPercent << "%)\n";

    std::cout << '\n';
}

int main() {
    Alloy alloy;
    std::string input;
    
    while(true) {    
        std::cout << "What alloy do you want to calculate?\n";
        std::cout << colorLabel("Tin Bronze", 227) << " | "
                  << colorLabel("Bismuth Bronze", 136) << " | "
                  << colorLabel("Black Bronze", 90) << " | Exit\n\t: ";
        std::getline(std::cin, input);
        input = hUtils::text.toLowerCase(input);

        if (input == "exit") break;

        if (input == "tin bronze") {
            alloy = getTinBronzeComposition();
        }
        else if (input == "bismuth bronze") {
            alloy = getBismuthBronzeComposition();
        }
        else if(input == "black bronze") {
            alloy = getBlackBronzeComposition();
        }
        else {
            std::cout << colorLabel("Unknown alloy type.", 31, false);
            hUtils::sleep(2000);
            hUtils::text.clearAbove(4);
            continue;
        }
        printAlloy(alloy);
        hUtils::pause(true);
        hUtils::text.clearAll();
    }
    return 0;
}