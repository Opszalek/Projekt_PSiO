#include "enemy.h"

enemy::enemy()
{

}
void enemy::find_way(sf::Sprite & player)
{

}

bool enemy::alive(float dmg)
{
    if (health_ >= 0 && health_ <= health_max) {
        health_ = health_ - dmg;
    }
    if (health_ <= 0) {
        return true;
    } else {
        return false;
    }
}
