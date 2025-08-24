#include <iostream>
#include <algorithm>

constexpr int unitsPerBit = 5;
constexpr int unitsPerIngot = 100;

struct Alloy {
    std::string name;   // e.g. "Bismuth Bronze", "Tin Bronze"
    int ingots;         // how many ingots requested
    int requiredUnits;  // total units needed
    int requiredBits;   // total ore bits needed

    // percentages
    int copperPercent;  // common ore
    int tinPercent;     // tin bronze
    int zincPercent;    // bismuth bronze
    int bismuthPercent; // bismuth bronze
    int goldPercent;    // black bronze
    int silverPercent;  // black bronze

    // ore bits
    int copperBits;     // common ore
    int tinBits;        // tin bronze
    int zincBits;       // bismuth bronze
    int bismuthBits;    // bismuth bronze
    int goldBits;       // black bronze
    int silverBits;     // black bronze
};

int calculateBits(int metal, int maxBits) {
    return static_cast<int>(maxBits * (metal / 100.0));
}

int inputVar(std::string prompt, int min, int max) {
    int input;
    do {
        std::cout << prompt << "\n\t: ";
        std::cin >> input;
        if(input < min) {
            std::cout << "Input is too low!\n";
        } else if(input > max) {
            std::cout << "Input is too high!\n";
        }
    } while (input < min || input > max);

    return input;
}

Alloy getTinBronzeComposition() {
    Alloy result;

    result.name = "Tin Bronze";

    result.ingots = inputVar("How many ingots do you want to make? (1-20)", 1, 20);
    result.requiredUnits = result.ingots * unitsPerIngot;

    result.copperPercent = inputVar("How much percentage of copper do you want to put? (88-92)", 88, 92);
    result.tinPercent = 100 - result.copperPercent;

    result.requiredBits = result.requiredUnits / unitsPerBit;
    result.copperBits = calculateBits(result.copperPercent, result.requiredBits);
    result.tinBits = result.requiredBits - result.copperBits;

    return result;
}

Alloy getBismuthBronzeComposition() {
    Alloy result;

    result.name = "Bismuth Bronze";

    result.ingots = inputVar("How many ingots do you want to make? (1-21)", 1, 21);
    result.requiredUnits = (result.ingots * unitsPerIngot);

    result.zincPercent = inputVar("How much percentage of zinc do you want to put? (20-30)", 20, 30);
    result.bismuthPercent = inputVar("How much percentage of bismuth do you want to put? (10-20)", 10, 20);
    result.copperPercent = 100 - result.zincPercent - result.bismuthPercent;

    result.requiredBits = result.requiredUnits / unitsPerBit;
    result.zincBits = calculateBits(result.zincPercent, result.requiredBits);
    result.bismuthBits = calculateBits(result.bismuthPercent, result.requiredBits);
    result.copperBits = result.requiredBits - result.zincBits - result.bismuthBits;

    return result;
}

Alloy getBlackBronzeComposition() {
    Alloy result;

    result.name = "Black Bronze";

    result.ingots = inputVar("How many ingots do you want to make? (1-16)", 1, 16);
    result.requiredUnits = result.ingots * unitsPerIngot;

    result.goldPercent = inputVar("How much percentage of gold do you want to put? (8-16)", 8, 16);
    result.silverPercent = inputVar("How much percentage of silver do you want to put? (8-16)", 8, 16);
    result.copperPercent = 100 - result.goldPercent - result.silverPercent;

    result.requiredBits = result.requiredUnits / unitsPerBit;
    result.goldBits = calculateBits(result.goldPercent, result.requiredBits);
    result.silverBits = calculateBits(result.silverPercent, result.requiredBits);
    result.copperBits = result.requiredBits - result.goldBits - result.silverBits;

    return result;
}

void printAlloy(const Alloy &a) {
    std::cout << "---  Prerequisites (" << a.name << ") ---\n";
    std::cout << "Units per " << a.ingots << " ingot/s = " << a.requiredUnits << " units\n";
    std::cout << "Required ore bits = " << a.requiredBits << " ore bits\n";
    std::cout << "---  Final Alloy Composition  ---\n";

    if (a.copperPercent > 0)
        std::cout << "Copper  - " << a.copperBits << " ore bits (" << a.copperPercent << "%)\n";
    if (a.tinPercent > 0)
        std::cout << "Tin     - " << a.tinBits << " ore bits (" << a.tinPercent << "%)\n";
    if (a.zincPercent > 0)
        std::cout << "Zinc    - " << a.zincBits << " ore bits (" << a.zincPercent << "%)\n";
    if (a.bismuthPercent > 0)
        std::cout << "Bismuth - " << a.bismuthBits << " ore bits (" << a.bismuthPercent << "%)\n";
    if (a.goldPercent > 0)
        std::cout << "Gold    - " << a.goldBits << " ore bits (" << a.goldPercent << "%)\n";
    if (a.silverPercent > 0)
        std::cout << "Silver  - " << a.silverBits << " ore bits (" << a.silverPercent << "%)\n";
    std::cout << '\n';
}

int main(){
    Alloy alloy;
    std::string input;
    
    while(true) {    
        std::cout << "What alloy do you want to calculate?\n";
        std::cout << "Tin Bronze | Bismuth Bronze | Black Bronze | Exit\n\t: ";
        std::getline(std::cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);

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
            std::cout << "Unknown alloy type.\n";
            continue;
        }
    }

    return 0;
}