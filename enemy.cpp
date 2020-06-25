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
    //this->setRotation(0);
   /* if(this->getPosition().y<player.getPosition().y)
    {
        this->setRotation(90);
        this->move(0, m_speed_ * time);

    }
   if(this->getPosition().y>player.getPosition().y)
    {
        this->setRotation(-90);
        this->move(0, -m_speed_ * time);

    }
   if (this->getPosition().x < player.getPosition().x) {
        this->setRotation(0);
        this->move(m_speed_ * time, 0);

    }
  if(this->getPosition().x>player.getPosition().x)
    {
        this->setRotation(180);
        this->move(-m_speed_ * time, 0);

    }
*/

   if(this->getPosition().y>player.getPosition().y && this->getPosition().x>player.getPosition().x)
    {
        this->move(-m_speed_ * time, -m_speed_ * time);
        this->setRotation(-135);
    }
    if(this->getPosition().y>player.getPosition().y && this->getPosition().x<player.getPosition().x)
    {
        this->move(m_speed_ * time, -m_speed_ * time);
        this->setRotation(-45);
    }
    if(this->getPosition().y<player.getPosition().y && this->getPosition().x>player.getPosition().x)
    {
        this->move(-m_speed_ * time, m_speed_ * time);
        this->setRotation(135);
    }
    if(this->getPosition().y<player.getPosition().y && this->getPosition().x<player.getPosition().x)
    {
        this->move(m_speed_ * time, m_speed_ * time);
        this->setRotation(45);
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
