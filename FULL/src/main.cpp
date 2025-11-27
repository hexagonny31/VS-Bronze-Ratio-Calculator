#include "calculations.h"
#include "hutils.h"

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
    std::optional<std::vector<AlloyDefinition>> init = parseAlloyTable("alloy_table.json");
    if(!init) {
        std::cout << colorLabel("ifstream failed to open .json file.", 31, false);
        hUtils::sleep(2000);
        return -1;
    }
    std::vector<AlloyDefinition> alloyTable = *init;

    std::unordered_map<std::string, int> lookup;
    for (int i = 0; i < alloyTable.size(); i++) {
        for (const std::string &alias : alloyTable[i].aliases) {
            lookup[hUtils::text.toLowerCase(alias)] = i;
        }
    }
    
    std::vector<std::string> alloyNames;
    for(int i = 0; i < alloyTable.size(); i++) {
        auto temp = hUtils::text.stripAnsi(alloyTable[i].name);
            if(temp.empty()) {
                std::cout << colorLabel("Alloy name is missing at index " + std::to_string(i), 31, false);
                hUtils::sleep(2000);
                return -1;
            }
        alloyNames.push_back(alloyTable[i].name);
    }
    
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
        std::optional<Alloy> result = getComposition(alloyTable[index]);
        if(!result) {
            hUtils::sleep(2000);
            return -1;
        }
        Alloy alloy = *result;

        alloy.printAlloy();
        hUtils::pause(true);
        hUtils::text.clearAll();
    }
    return 0;
}