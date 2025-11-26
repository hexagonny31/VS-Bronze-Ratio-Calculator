#include "calculations.h"
#include "hutils.h"
#include "alloy_definition.h"

#include <iostream>
#include <unordered_map>

void Alloy::printAlloy() {

    hUtils::text.clearAll();
    std::cout << "---  Prerequisites (" << name << ") ---\n";
    std::cout << "Units per " << ingots << " ingot/s = " << reqUnits << " units\n";
    std::cout << "Required ore bits = " << reqBits << " ore bits\n\n";
    std::cout << "---  Final Alloy Composition  ---\n";

    for(int i = 0; i <= component.size(); i++) {
        if(component[i].percent > 0)
            std::cout << component[i].metal   << " - "
                      << component[i].bits    << " ore bits ("
                      << component[i].percent << "%)\n";
    }
    std::cout << '\n';
}

int main() {
    Alloy alloy;

    std::unordered_map<std::string, int> lookup;
    for (int i = 0; i < alloyTable.size(); i++) {
        for (const std::string &alias : alloyTable[i].aliases) {
            lookup[hUtils::text.toLowerCase(alias)] = i;
        }
    }
    
    std::vector<std::string> alloyNames;
    for(const auto &a : alloyTable) alloyNames.push_back(a.name);
    
    std::string input;
    while(true) {
        std::cout << "What alloy do you want to calculate? (Enter 'e' to exit)\n";
        hUtils::table.setElements(alloyNames);
        hUtils::table.toColumn("left", 16, 3);
        std::cout << "> ";
        std::getline(std::cin, input);
        input = hUtils::text.toLowerCase(input);

        if (input == "exit" || input == "e") break;

        auto it = lookup.find(input);
        if (it == lookup.end()) {
            std::cout << colorLabel("Unknown alloy type.", 31, false);
            hUtils::sleep(2000);
            hUtils::text.clearAbove(5);
            continue;
        }

        int index = it->second;
        alloy = getComposition(alloyTable[index]);

        alloy.printAlloy();
        hUtils::pause(true);
        hUtils::text.clearAll();
    }
    return 0;
}