#include "enemy.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <TextureManager.h>
#include <math.h>
enemy::enemy()
{

}
void enemy::find_way(sf::Sprite &player, float time)
{
    if (this->getPosition().x < player.getPosition().x) {
        this->move(m_speed_ * time, 0);
    }
    if(this->getPosition().x>player.getPosition().x)
    {
        this->move(-m_speed_ * time, 0);
    }
    if(this->getPosition().y<player.getPosition().y)
    {
        this->move(0, m_speed_ * time);
    }
    if(this->getPosition().y>player.getPosition().y)
    {
        this->move(0, -m_speed_ * time);
    }
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
