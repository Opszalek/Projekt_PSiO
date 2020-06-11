#include "character.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <TextureManager.h>
#include <math.h>
character::character()
{

}

void character::movement(sf::Sprite &postac, float time, sf::Sprite &hp)
{
    float xv = 0;
    float yv = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        yv = m_speed_;
        setRotation(90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        xv = -m_speed_;
        setRotation(180);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        xv = m_speed_;
        setRotation(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        yv = -m_speed_;
        setRotation(-90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        yv = yv * 3;
        xv = xv * 3;
    }
    hp.move(xv * time, yv * time);
    postac.move(xv * time, yv * time);
    direction();

}

void character::movement2(sf::Sprite &postac, float time, sf::Sprite &hp)
{
    float xv = 0;
    float yv = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        yv = m_speed_;
        setRotation(90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        xv = -m_speed_;
        setRotation(180);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        xv = m_speed_;
        setRotation(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        yv = -m_speed_;
        setRotation(-90);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        yv = yv * 3;
        xv = xv * 3;
    }
    hp.move(xv * time, yv * time);
    postac.move(xv * time, yv * time);
    direction();
}

void character::zdrowie(float dmg, sf::Sprite &hp, sf::Texture &texture)
{
    if (health_ >= 0 && health_<=health_max) {

        health_ = health_ - dmg;
    }
        float procent = health_ / health_max;




        if (procent == 1)
        {
          hp.setTextureRect(sf::IntRect(0, 0, 100, 10));
        } else if (procent<1 && procent>0.9) {
                hp.setTextureRect(sf::IntRect(0, 10, 100, 10));
            } else if (procent<0.9 && procent>0.8) {
                hp.setTextureRect(sf::IntRect(0, 20, 100, 10));
            }
            else if (procent<0.8 && procent>0.7) {
                hp.setTextureRect(sf::IntRect(0, 30, 100, 10));
            }
            else if (procent<0.7 && procent>0.6) {
                hp.setTextureRect(sf::IntRect(0, 40, 100, 10));
            }
            else if (procent<0.6 && procent>0.5) {
               hp.setTextureRect(sf::IntRect(0,50, 100, 10));
            }
            else if (procent<0.5 && procent>0.4) {
               hp.setTextureRect(sf::IntRect(0, 60, 100, 10));
            }
            else if (procent<0.4 && procent>0.3) {
                hp.setTextureRect(sf::IntRect(0, 70, 100, 10));
            }
            else if (procent<0.3 && procent>0.2) {
                hp.setTextureRect(sf::IntRect(0, 80, 100, 10));
            }
            else if (procent<0.2 && procent>0.1) {
                hp.setTextureRect(sf::IntRect(0, 90, 100, 10));
            }else if (procent<0.1 && procent>=0) {
                hp.setTextureRect(sf::IntRect(0, 100, 100, 10));
            }


}
std::string character::direction()
{



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction_ = "NE";ismoving = true;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction_ = "NW";ismoving = true;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction_ = "SW";ismoving = true;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction_ = "SE";ismoving = true;

        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction_ = 'W';ismoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction_ = 'E';ismoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            direction_ = 'S';ismoving = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            direction_ = 'N';
            ismoving = true;
        } else {
            ismoving = false;}



    return direction_;
}
bool character::limit(float x, float y,sf::Sprite &postac)
{

}
