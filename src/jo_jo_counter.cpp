//
// Created by cyan on 5/29/25.
//

#include "jo_jo_counter.h"

#include <regex>

const std::regex regex("^(Jo[^,]*),F,(\\d+)$");

JoJoCounter::JoJoCounter(std::istream &countFrom) {
    std::string line;
    while (std::getline(countFrom, line)) {
        std::match_results<std::string::iterator> match;
        if (std::regex_match(line.begin(), line.end(), match, regex)) {
            std::string name = match[1].str();
            int count = std::stoi(match[2].str());
            jos.push_back(std::pair<std::string, int>(name, count));
            nameCount++;
            totalCount += count;
        }
    }
}
