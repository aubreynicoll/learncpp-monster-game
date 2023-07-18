//
// Created by Aubrey Nicoll on 18/7/2023.
//

#ifndef LEARNCPP_MONSTER_GAME_PLAYER_HPP
#define LEARNCPP_MONSTER_GAME_PLAYER_HPP

#include "Creature.hpp"

class Player : public Creature {
        static char constexpr player_symbol{'@'};
        static int constexpr starting_health{10};
        static int constexpr starting_damage{1};
        static int constexpr starting_gold{0};
        static int constexpr starting_level{1};
        static int constexpr max_level{20};

        int m_level{starting_level};

    public:
        explicit Player(std::string const &name)
            : Creature(name, player_symbol, starting_health, starting_damage,
                       starting_gold) {}

        static auto getPlayer() -> Player;

        [[nodiscard]] auto getLevel() const -> int {
                return m_level;
        }

        auto levelUp() -> void;
        auto hasWon() -> bool;
};

#endif  // LEARNCPP_MONSTER_GAME_PLAYER_HPP
