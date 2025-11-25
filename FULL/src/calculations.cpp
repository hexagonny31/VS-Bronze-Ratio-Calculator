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
    } while (input < min || input > max);

    return input;
}

Alloy getTinBronze() {
    Alloy result;

    result.name = colorLabel("Tin Bronze", 227);

    result.ingots = inputVar("How many ingots do you want to make? (1-20)", 1, 20);
    result.reqUnits = result.ingots * unitsPerIngot;

    result.copperP = inputVar("How much percentage of copper do you want to put? (88-92)", 88, 92);
    result.tinP = 100 - result.copperP;

    result.reqBits = result.reqUnits / unitsPerBit;
    result.copperB = calculateBits(result.copperP, result.reqBits);
    result.tinB = result.reqBits - result.copperB;

    return result;
}

Alloy getBismuthBronze() {
    Alloy result;

    result.name = colorLabel("Bismuth Bronze", 136);

    result.ingots = inputVar("How many ingots do you want to make? (1-21)", 1, 21);
    result.reqUnits = result.ingots * unitsPerIngot;

    result.zincP = inputVar("How much percentage of zinc do you want to put? (20-30)", 20, 30);
    result.bismuthP = inputVar("How much percentage of bismuth do you want to put? (10-20)", 10, 20);
    result.copperP = 100 - result.zincP - result.bismuthP;

    result.reqBits = result.reqUnits / unitsPerBit;
    result.zincB = calculateBits(result.zincP, result.reqBits);
    result.bismuthB = calculateBits(result.bismuthP, result.reqBits);
    result.copperB = result.reqBits - result.zincB - result.bismuthB;

    return result;
}

Alloy getBlackBronze() {
    Alloy result;

    result.name = colorLabel("Black Bronze", 90);

    result.ingots = inputVar("How many ingots do you want to make? (1-16)", 1, 15);
    result.reqUnits = result.ingots * unitsPerIngot;

    result.goldP = inputVar("How much percentage of gold do you want to put? (8-16)", 8, 16);
    result.silverP = inputVar("How much percentage of silver do you want to put? (8-16)", 8, 16);
    result.copperP = 100 - result.goldP - result.silverP;

    result.reqBits = result.reqUnits / unitsPerBit;
    result.goldB = calculateBits(result.goldP, result.reqBits);
    result.silverB = calculateBits(result.silverP, result.reqBits);
    result.copperB = result.reqBits - result.goldB - result.silverB;

    return result;
}