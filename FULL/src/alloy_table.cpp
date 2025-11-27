#include "hutils.h"
#include "calculations.h"
#include "json.hpp"

#include <fstream>
#include <filesystem>
#include <optional>

namespace fs = std::filesystem;
using json = nlohmann::json;

std::optional<std::vector<AlloyDefinition>> parseAlloyTable(const std::string &fileName){
    std::ifstream file(fileName);
    if(!file.is_open()) return std::nullopt;
    
    json j;
    file >> j;
    
    std::vector<AlloyDefinition> result;

    for (auto& entry : j) {
        AlloyDefinition def;
        def.name = colorLabel(entry["name"], entry.value("color", 0));
        def.aliases = entry["aliases"].get<std::vector<std::string>>();

        auto comps = entry["components"];
        for(size_t i = 0; i < comps.size() && i < 3; i++) {
            Component c;
            c.metal = colorLabel(comps[i].value("metal", ""), comps[i].value("color", 0));
            c.min   = comps[i].value("percent_min", 0);
            c.max   = comps[i].value("percent_max", 0);
            def.component[i] = c;
        }
        result.push_back(def);
    }
    return result;
}