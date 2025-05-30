//
// Created by cyan on 5/29/25.
//

#ifndef JO_JO_COUNTER_H
#define JO_JO_COUNTER_H
#include <string>
#include <vector>


class JoJoCounter {
    std::vector<std::pair<std::string, int>> jos;
    int nameCount = 0;
    int totalCount = 0;
public:

    explicit JoJoCounter(std::istream &countFrom);

    std::vector<std::pair<std::string, int>> getJos() const {
        return jos;
    }

    int getNameCount() const {
        return nameCount;
    }

    int getTotalCount() const {
        return totalCount;
    }
};



#endif //JO_JO_COUNTER_H
