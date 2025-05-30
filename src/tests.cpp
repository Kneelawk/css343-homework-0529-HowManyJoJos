//
// Created by cyan on 4/21/25.
//

#include "jo_jo_counter.h"
#include "ktest.hpp"

KTEST(read_streamstream) {
    std::stringstream ss;
    const JoJoCounter counter(ss);

    KASSERT_EQ(0, counter.getJos().size());
    KASSERT_EQ(0, counter.getNameCount());
    KASSERT_EQ(0, counter.getTotalCount());
}

KTEST(read_some_jos) {
    std::stringstream ss;
    ss << "Joa,F,213" << std::endl;
    ss << "Josephine,F,21" << std::endl;
    const JoJoCounter counter(ss);

    const auto jos = counter.getJos();
    KASSERT_EQ(2, jos.size());
    KASSERT_EQ("Joa", jos[0].first);
    KASSERT_EQ(213, jos[0].second);
    KASSERT_EQ("Josephine", jos[1].first);
    KASSERT_EQ(21, jos[1].second);

    KASSERT_EQ(2, counter.getNameCount());
    KASSERT_EQ(234, counter.getTotalCount());
}

KTEST(ignore_non_jos) {
    std::stringstream ss;
    ss << "Joa,F,213" << std::endl;
    ss << "Julia,F,25" << std::endl;
    ss << "Josephine,F,21" << std::endl;
    const JoJoCounter counter(ss);

    const auto jos = counter.getJos();
    KASSERT_EQ(2, jos.size());
    KASSERT_EQ("Joa", jos[0].first);
    KASSERT_EQ(213, jos[0].second);
    KASSERT_EQ("Josephine", jos[1].first);
    KASSERT_EQ(21, jos[1].second);

    KASSERT_EQ(2, counter.getNameCount());
    KASSERT_EQ(234, counter.getTotalCount());
}

KTEST(ignore_non_f) {
    std::stringstream ss;
    ss << "Joa,F,213" << std::endl;
    ss << "Jonah,M,19283" << std::endl;
    ss << "Josephine,F,21" << std::endl;
    const JoJoCounter counter(ss);

    const auto jos = counter.getJos();
    KASSERT_EQ(2, jos.size());
    KASSERT_EQ("Joa", jos[0].first);
    KASSERT_EQ(213, jos[0].second);
    KASSERT_EQ("Josephine", jos[1].first);
    KASSERT_EQ(21, jos[1].second);

    KASSERT_EQ(2, counter.getNameCount());
    KASSERT_EQ(234, counter.getTotalCount());
}
