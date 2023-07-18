//
// Created by Aubrey Nicoll on 18/7/2023.
//

#include "Player.hpp"

#include <iostream>

auto Player::levelUp() -> void {
        ++m_level;
        setDamage(getDamage() + 1);
}

auto Player::hasWon() -> bool {
        return m_level >= max_level;
}

auto Player::getPlayer() -> Player {
        std::cout << "Enter your player name: " << std::flush;
        std::string buf;
        std::cin >> buf;
        std::cout << "Welcome, " << buf << '\n';
        return Player{buf};
}
