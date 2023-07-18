//
// Created by Aubrey Nicoll on 18/7/2023.
//

#include "Creature.hpp"

#include <cassert>

auto Creature::reduceHealth(int amount) -> void {
        assert(amount > 0);
        m_health -= amount;
}

auto Creature::isDead() -> bool {
        return m_health <= 0;
}

auto Creature::addGold(int amount) -> void {
        assert(amount > 0);
        m_gold += amount;
}
