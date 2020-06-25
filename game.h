#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <enemy.h>
#include <character.h>


class game
{
public:
    game();
    void level(sf::Texture&,sf::Window&);
    int iloscenemy;
    int trudnosc;
    int players;
    int points = 0;
    void begin();
    std::vector<enemy> zombieVec;
    bool bite(character &player, enemy &enemy);
};

#endif // GAME_H
