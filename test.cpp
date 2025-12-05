#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

struct Component
{
    std::string metal;
    int min     = 0;
    int max     = 0;
    int percent = 0;
    int bits    = 0;
    std::vector<std::pair<int, int>> stacks;
};

struct Alloy
{
    std::string name; // e.g. "Bismuth Bronze", "Tin Bronze".
    int ingots;       // how many ingots requested.
    int reqUnits;     // total units needed.
    int reqBits;      // total ore bits needed.

    // a vector of percentages, metal names and ore bits.
    // the last element is the dependent variable.
    std::vector<Component> component = std::vector<Component>(3);

    void printAlloy();
};

int main() {
    Alloy result;

    for(auto &c : result.component) {
        c.bits = static_cast<int>(0.2 * 1 * 88); // static for now
        c.stacks.push_back({c.bits / 128, c.bits % 128});
    }

    for(int i = 0; i < result.component.size(); i++) {
        std::cout << result.component[i].bits << '\n';
        for(const auto &[stack, leftover] : result.component[i].stacks) {
            std::cout << stack << " " << leftover << '\n';
        }
    }

    return 0;
}