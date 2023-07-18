//
// Created by Aubrey Nicoll on 18/7/2023.
//

#ifndef LEARNCPP_MONSTER_GAME_CREATURE_HPP
#define LEARNCPP_MONSTER_GAME_CREATURE_HPP

#include <string>
#include <utility>

class Creature {
        std::string m_name;
        char        m_symbol{};
        int         m_health{};
        int         m_damage{};
        int         m_gold{};

    public:
        Creature(std::string name, char symbol, int health, int damage,
                 int gold)
            : m_name(std::move(name)),
              m_symbol(symbol),
              m_health(health),
              m_damage(damage),
              m_gold(gold) {}

        [[nodiscard]] auto getName() const -> std::string const & {
                return m_name;
        }

        [[nodiscard]] auto getSymbol() const -> char {
                return m_symbol;
        }

        [[nodiscard]] auto getHealth() const -> int {
                return m_health;
        }

        void setHealth(int health) {
                m_health = health;
        }

        void setDamage(int damage) {
                m_damage = damage;
        }

        void setGold(int gold) {
                m_gold = gold;
        }

        [[nodiscard]] auto getDamage() const -> int {
                return m_damage;
        }

        [[nodiscard]] auto getGold() const -> int {
                return m_gold;
        }

        auto reduceHealth(int amount) -> void;
        auto isDead() -> bool;
        auto addGold(int amount) -> void;
};

#endif  // LEARNCPP_MONSTER_GAME_CREATURE_HPP
