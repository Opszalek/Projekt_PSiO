#include "bullet.h"



void Bullet::fire(float time, std::string direction_)
{

     if (direction_ == "NE") {
        bullet.move(100 * time, -100 * time);
    } else if (direction_ == "SE") {
        bullet.move(100 * time, 100 * time);
    } else if (direction_ == "SW") {
        bullet.move(-100 * time, 100 * time);
    } else if (direction_ == "NW") {
        bullet.move(-100 * time, -100 * time);
    }else if (direction_ == "N") {
        bullet.move(0, -100 * time);
    } else if (direction_ == "E") {
        bullet.move(100 * time, 0 * time);
    } else if (direction_ == "S") {
        bullet.move(0, 100 * time);
    } else if (direction_ == "W") {
        bullet.move(-100 * time, 0);
    }


}
