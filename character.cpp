#include "character.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <TextureManager.h>
#include <math.h>
character::character(sf::Texture & pla, sf::Texture & hp)
{
    this->setTexture(pla);
    this->setTextureRect(sf::IntRect(0, 0, 49, 43));
    this->setOrigin(25, 21);
    this->setPosition(300.0, 300.0);
    player_hp.setTexture(hp);
    player_hp.setTextureRect(sf::IntRect(0, 0, 100, 10)); //left, top, width, height
    player_hp.setPosition(250.0, 250.0);
}

void character::movement(sf::Sprite &postac, float time, int trudnosc, sf::RenderWindow &win)
{
    float xv = 0;
    float yv = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (postac.getGlobalBounds().top+postac.getGlobalBounds().height)<win.getSize().y)  {
        yv = m_speed_;
        setRotation(90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && postac.getGlobalBounds().left>0) {
        xv = -m_speed_;
        setRotation(180);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (postac.getGlobalBounds().left+postac.getGlobalBounds().width)<win.getSize().x) {
        xv = m_speed_;
        setRotation(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && postac.getGlobalBounds().top>0) {
        yv = -m_speed_;
        setRotation(-90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (postac.getGlobalBounds().left+postac.getGlobalBounds().width)<win.getSize().x && postac.getGlobalBounds().top>0) {
        yv = -m_speed_;
        xv = m_speed_;
        setRotation(-45);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && postac.getGlobalBounds().top>0 && sf::Keyboard::isKeyPressed(sf::Keyboard::A) && postac.getGlobalBounds().left>0 )
    {
        yv = -m_speed_;
        xv = -m_speed_;
        setRotation(-135);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && postac.getGlobalBounds().left>0 && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (postac.getGlobalBounds().top+postac.getGlobalBounds().height)<win.getSize().y)
    {
        yv = m_speed_;
        xv = -m_speed_;
        setRotation(135);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (postac.getGlobalBounds().left+postac.getGlobalBounds().width)<win.getSize().x && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (postac.getGlobalBounds().top+postac.getGlobalBounds().height)<win.getSize().y)
    {
        yv = m_speed_;
        xv = m_speed_;
        setRotation(45);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && trudnosc!=3) {
        yv = yv * 2;
        xv = xv * 2;
    }
    player_hp.move(xv * time, yv * time);
    postac.move(xv * time, yv * time);

    direction();

}

void character::zdrowie(float dmg)
{
    if (health_ >= 0 && health_<=health_max) {

        health_ = health_ - dmg;

    }
        float procent = health_ / health_max;




        if (procent == 1)
        {
          player_hp.setTextureRect(sf::IntRect(0, 0, 100, 10));
        } else if (procent<1 && procent>0.9) {
                player_hp.setTextureRect(sf::IntRect(0, 10, 100, 10));
            } else if (procent<0.9 && procent>0.8) {
                player_hp.setTextureRect(sf::IntRect(0, 20, 100, 10));
            }
            else if (procent<0.8 && procent>0.7) {
                player_hp.setTextureRect(sf::IntRect(0, 30, 100, 10));
            }
            else if (procent<0.7 && procent>0.6) {
                player_hp.setTextureRect(sf::IntRect(0, 40, 100, 10));
            }
            else if (procent<0.6 && procent>0.5) {
               player_hp.setTextureRect(sf::IntRect(0,50, 100, 10));
            }
            else if (procent<0.5 && procent>0.4) {
               player_hp.setTextureRect(sf::IntRect(0, 60, 100, 10));
            }
            else if (procent<0.4 && procent>0.3) {
                player_hp.setTextureRect(sf::IntRect(0, 70, 100, 10));
            }
            else if (procent<0.3 && procent>0.2) {
                player_hp.setTextureRect(sf::IntRect(0, 80, 100, 10));
            }
            else if (procent<0.2 && procent>0.1) {
                player_hp.setTextureRect(sf::IntRect(0, 90, 100, 10));
            }else if (procent<0.1 && procent>=0) {
                player_hp.setTextureRect(sf::IntRect(0, 100, 100, 10));
            }


}
std::string character::direction()
{



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
            && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction_ = "NE";ismoving = true;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction_ = "NW";ismoving = true;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction_ = "SW";ismoving = true;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction_ = "SE";ismoving = true;

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction_ = 'W';ismoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction_ = 'E';ismoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            direction_ = 'S';ismoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            direction_ = 'N';
            ismoving = true;
        } else {
            ismoving = false;}



    return direction_;
}
