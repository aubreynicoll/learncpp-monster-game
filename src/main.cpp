#include <iostream>
#include <string>

#include "Creature.hpp"
#include "Monster.hpp"
#include "Player.hpp"
#include "RandomIntGenerator.hpp"

auto get_input() -> char {
        std::cout << "(r)un, or (f)ight? " << std::flush;
        while (true) {
                char buf{};
                std::cin >> buf;
                if (strchr("rf", buf)) {
                        return buf;
                }
        }
}

auto attack_monster(Player &p, Monster &m) -> void {
        m.reduceHealth(p.getDamage());

        std::cout << "You hit " << m.getName() << " for " << p.getDamage()
                  << " damage.\n";

        if (m.isDead()) {
                std::cout << m.getName() << " died!\n";
                p.levelUp();
                p.addGold(m.getGold());
                std::cout << "You reached level " << p.getLevel() << "!\n";
        }
}

auto attack_player(Player &p, Monster &m) -> void {
        p.reduceHealth(m.getDamage());

        std::cout << m.getName() << " hit you for " << m.getDamage()
                  << " damage. Ouch!\n";
}

auto fight_monster(Player &p, Monster &m) -> bool {
        std::cout << "You have " << p.getHealth() << " health left.\n";
        char input{get_input()};

        bool continue_fight{};

        if (input == 'f') {
                attack_monster(p, m);
                if (!m.isDead()) {
                        attack_player(p, m);
                }

                continue_fight = !m.isDead() && !p.isDead();
        } else {
                RandomIntGenerator generator{0, 1};
                auto               hasFailed{generator.next()};

                if (hasFailed) {
                        std::cout << "Failed to flee!\n";
                        attack_player(p, m);
                } else {
                        std::cout << "You ran away!\n";
                }

                continue_fight = hasFailed && !p.isDead();
        }

        return continue_fight;
}

auto main() -> int {
        Player player{Player::getPlayer()};

        while (!player.hasWon() && !player.isDead()) {
                Monster monster{Monster::getRandomMonster()};
                std::cout << "You encountered a " << monster.getName() << ".\n";

                while (fight_monster(player, monster))
                        ;
        }

        if (player.isDead()) {
                std::cout << "You died at level " << player.getLevel()
                          << " with " << player.getGold() << " gold. Bummer!\n";
        } else {
                std::cout << "You reached level 20 with " << player.getGold()
                          << " gold in your pocket. What a champ!\n";
        }
}
