//
// Created by Aubrey Nicoll on 18/7/2023.
//

#ifndef LEARNCPP_MONSTER_GAME_RANDOMINTGENERATOR_HPP
#define LEARNCPP_MONSTER_GAME_RANDOMINTGENERATOR_HPP

#include <random>

class RandomIntGenerator {
        std::uniform_int_distribution<int> m_dist{0, 1};

    public:
        explicit RandomIntGenerator(int min, int max)
            : m_dist(std::uniform_int_distribution{min, max}) {}

        auto next() -> int;
};

#endif  // LEARNCPP_MONSTER_GAME_RANDOMINTGENERATOR_HPP
