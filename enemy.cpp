#include "enemy.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <TextureManager.h>
#include <math.h>

enemy::enemy(sf::Texture &tex, sf::Window &window, int trudnosc)
{
    this->setTexture(tex);
    this->setTextureRect(sf::IntRect(0, 0, 288, 311));
    this->setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
    this->scale(0.3, 0.3);
    this->setOrigin(144, 155);
    if (trudnosc == 1) {
        this->dmg = 10;
        this->health_max = 100;
    } else if (trudnosc == 2) {
        this->dmg = 15;
        this->health_max = 125;
    } else if (trudnosc == 3) {
        this->health_max = 150;
        this->dmg = 20;
    }
    health_ = health_max;
}
void enemy::find_way(sf::Sprite &player, float time)
{

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
