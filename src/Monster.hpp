//
// Created by Aubrey Nicoll on 18/7/2023.
//

#ifndef LEARNCPP_MONSTER_GAME_MONSTER_HPP
#define LEARNCPP_MONSTER_GAME_MONSTER_HPP

#include "Creature.hpp"
#include "RandomIntGenerator.hpp"

class Monster : public Creature {
    public:
        enum Type { DRAGON, ORC, SLIME, MAX_TYPE };

        explicit Monster(Type type) : Creature{getDefaultMonster(type)} {}

        static auto getRandomMonster() -> Monster {
                RandomIntGenerator generator{0, Type::MAX_TYPE - 1};
                auto               random_type{generator.next()};
                return Monster{static_cast<Type>(random_type)};
        }

    private:
        static auto getDefaultMonster(Type type) -> const Creature & {
                static std::array<Creature, Type::MAX_TYPE> const monster_data{
                    {{"dragon", 'D', 20, 4, 100},
                     {"orc", 'o', 4, 2, 25},
                     {"slime", 's', 1, 1, 10}}};

                return monster_data.at(type);
        }
};

#endif  // LEARNCPP_MONSTER_GAME_MONSTER_HPP
