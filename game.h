#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <enemy.h>
#include <character.h>
#include <box.h>
#include <bullet.h>
#include <weapons.h>
#include <fstream>
#include <string>


class game
{
public:
    game();
    void level(sf::Window&,character&,weapons&);
    void level(sf::Window&);
    int iloscenemy;
    int trudnosc;
    int players;
    int points = 0;
    int poziom = 1;
    void begin();
    bool bite(character &player, enemy &enemy);
    void rysowanie(sf::RenderWindow &);
    void play_again(sf::RenderWindow&);
    std::vector<enemy> zombieVec;
    std::vector<Box> boxvec;
    sf::Text punkty;
    sf::Text restart;
    sf::Font font;
    sf::Text napis;
    sf::Text napis2;
    sf::Texture box_tex;
    sf::Texture zombie_tex;
    sf::Clock timer;
};

#endif // GAME_H
