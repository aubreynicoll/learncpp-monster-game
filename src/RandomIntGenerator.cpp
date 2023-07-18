//
// Created by Aubrey Nicoll on 18/7/2023.
//

#include "RandomIntGenerator.hpp"

static std::mt19937 rng{std::random_device{}()};

auto RandomIntGenerator::next() -> int {
        return m_dist(rng);
}
