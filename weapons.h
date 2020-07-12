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
    int max_ammo=100;
    int dmg;
    int dmg_uzi=10;
    int dmg_pistol=10;
    int fire_delay=100;
    void shoot(character &);
    std::vector<Bullet> bulletVec;
    void change();
    int nr = 1;
    sf::Text ile_ammo;
    sf::Font font;


};

#endif // WEAPONS_H
