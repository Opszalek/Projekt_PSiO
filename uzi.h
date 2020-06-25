#ifndef UZI_H
#define UZI_H
#include <weapons.h>

class Uzi : public weapons
{
public:
    Uzi()
    {
        max_ammo = 100;
        dmg = 25;
        fire_delay = 50;
    };
};

#endif // UZI_H
