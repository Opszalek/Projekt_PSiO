#ifndef WEAPONS_H
#define WEAPONS_H
#include <character.h>
#include <bullet.h>
#include <vector>


class weapons
{
public:
    weapons();
    int ammo;
    int max_ammo;
    int dmg;
    int fire_delay;
    void shoot(character &);
    std::vector<Bullet> bulletVec;
    void change(int);
    int nr = 1;
    sf::Text ile_ammo;
    sf::Font font;

};

#endif // WEAPONS_H
