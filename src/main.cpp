#include <fstream>
#include <iostream>

#include "jo_jo_counter.h"
#include "ktest.hpp"

int main() {
    ktest::runAllTests();

    std::fstream file{"yob2024.txt", std::fstream::in};
    const JoJoCounter counter(file);

    std::cout << "Jos:" << std::endl;
    for (const auto &jo: counter.getJos()) {
        std::cout << "  " << jo.first << ": " << jo.second << std::endl;
    }

    std::cout << "Number of 'Jo' names: " << counter.getNameCount() << std::endl;
    std::cout << "Total number of people named 'Jo': " << counter.getTotalCount() << std::endl;

    return 0;
}
