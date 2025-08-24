#include "calculations.h"
#include "hutils.h"

#include <iostream>

std::string colorLabel(std::string label, const int color, bool use356) {
    return hUtils::text.fgColor(color, use356) + label + hUtils::text.defaultText();
}

int calculateBits(int metal, int maxBits) {
    return static_cast<int>(maxBits * (metal / 100.0));
}

int inputVar(std::string prompt, int min, int max) {
    int input;
    do {
        std::cout << prompt << "\n\t: ";
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
    } while (input < min || input > max);

    return input;
}

Alloy getTinBronzeComposition() {
    Alloy result;

    result.name = colorLabel("Tin Bronze", 227);

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

    result.name = colorLabel("Bismuth Bronze", 136);

    result.ingots = inputVar("How many ingots do you want to make? (1-21)", 1, 21);
    result.requiredUnits = result.ingots * unitsPerIngot;

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

    result.name = colorLabel("Black Bronze", 90);

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