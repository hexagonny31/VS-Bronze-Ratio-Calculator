#include "calculations.h"
#include "hutils.h"

#include <iostream>

void printAlloy(const Alloy &a) {
    hUtils::text.clearAll();
    std::cout << "---  Prerequisites (" << a.name << ") ---\n";
    std::cout << "Units per " << a.ingots << " ingot/s = " << a.reqUnits << " units\n";
    std::cout << "Required ore bits = " << a.reqBits << " ore bits\n\n";
    std::cout << "---  Final Alloy Composition  ---\n";

    if (a.copperP > 0)
        std::cout << colorLabel("Copper", 208) << "  - " << a.copperB  << " ore bits (" << a.copperP  << "%)\n";
    if (a.tinP > 0)
        std::cout << colorLabel("Tin", 94)  << "     - " << a.tinB     << " ore bits (" << a.tinP     << "%)\n";
    if (a.zincP > 0)
        std::cout << colorLabel("Zinc", 250) << "    - " << a.zincB    << " ore bits (" << a.zincP    << "%)\n";
    if (a.bismuthP > 0)
        std::cout << colorLabel("Bismuth", 144) << " - " << a.bismuthB << " ore bits (" << a.bismuthP << "%)\n";
    if (a.goldP > 0)
        std::cout << colorLabel("Gold", 220) << "    - " << a.goldB    << " ore bits (" << a.goldP    << "%)\n";
    if (a.silverP > 0)
        std::cout << colorLabel("Silver", 252) << "  - " << a.silverB  << " ore bits (" << a.silverP  << "%)\n";

    std::cout << '\n';
}

int main() {
    Alloy alloy;
    std::string input;
    
    while(true) {    
        std::cout << "What alloy do you want to calculate?\n";
        std::cout << colorLabel("Tin Bronze", 227) << " | "
                  << colorLabel("Bismuth Bronze", 136) << " | "
                  << colorLabel("Black Bronze", 90) << " | Exit\n> ";
        std::getline(std::cin, input);
        input = hUtils::text.toLowerCase(input);

        if (input == "exit") break;

        if (input == "tin bronze" || input == "tin") {
            alloy = getTinBronze();
        }
        else if (input == "bismuth bronze" || input == "bismuth") {
            alloy = getBismuthBronze();
        }
        else if(input == "black bronze" || input == "black") {
            alloy = getBlackBronze();
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