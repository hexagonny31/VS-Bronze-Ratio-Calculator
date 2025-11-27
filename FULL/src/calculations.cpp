#include "calculations.h"
#include "hutils.h"

#include <iostream>
#include <cmath>
#include <string>
#include <numeric>

int calculateMaxIngots(std::vector<int>& metals) {
    int ingots = 0;
    while(true) {
        ingots++;
        int slots = 0;
        for(int metal: metals) slots += ceil((0.2 * metal * ingots) / 128.0);
        slots += ceil((0.2 * (100 - std::accumulate(metals.begin(), metals.end(), 0)) * ingots) / 128.0);
        if(slots > 4) return ingots - 1;
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

std::optional<Alloy> getComposition(const AlloyDefinition &def) {
    Alloy result;
    result.name = def.name;

    if(def.component[2].metal.empty()) {
        std::cout << colorLabel("3rd metal is not defined!", 31, false);
        return std::nullopt;
    }
    result.component = {
        {def.component[0].metal},
        {def.component[1].metal},
        {def.component[2].metal}
    };

    std::vector<int> totalPercent;
    for(int i = 0; i < 2; i++) {
        std::string metal = def.component[i].metal;
        std::string temp = hUtils::text.stripAnsi(metal);
        if(!temp.empty()) {
            const int min = def.component[i].min;
            const int max = def.component[i].max;
            if(max < min || (min <= 0 && max <= 0)) {
                auto temp = hUtils::text.stripAnsi(metal);
                std::cout << colorLabel(
                    "Range for " + hUtils::text.toLowerCase(temp)
                    + " is impossible or empty!",
                    31, false
                );
                return std::nullopt;
            }

            result.component[i].percent = inputVar(
                "How much percentage of " + hUtils::text.toLowerCase(metal)
                + " do you want to put? (" + std::to_string(min)
                + "-" + std::to_string(max) + ")",
                min, max
            );
            totalPercent.push_back(result.component[i].percent);
        }
    }
    result.component[2].percent = 100 - std::accumulate(totalPercent.begin(), totalPercent.end(), 0);
    if(result.component[2].percent < 1) {
        auto temp = hUtils::text.stripAnsi(result.component[2].metal);
        std::cout << colorLabel(
            "The percentage of " + hUtils::text.toLowerCase(temp)
            + " is non-existent!",
            31, false
        );
        return std::nullopt;
    }

    int maxIngots = calculateMaxIngots(totalPercent);
    if(maxIngots < 1) {
        std::cout << colorLabel(
            "Maximum (" + std::to_string(maxIngots)
            + ") is at impossible range!",
            31, false
        );
        return std::nullopt;
    }
    result.ingots = inputVar(
        "How many ingots do you want to make? (1-"
        + std::to_string(maxIngots) + ")", 1, maxIngots
    );

    result.reqUnits = result.ingots * unitsPerIngot;  // just for show for now.
    result.reqBits = result.reqUnits / unitsPerBit;   // same for this.
    for (auto &c : result.component) c.bits = static_cast<int>(0.2 * result.ingots * c.percent);

    return result;
}