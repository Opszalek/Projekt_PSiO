#include "character.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <TextureManager.h>
character::character()
{

}

void character::movement(sf::Sprite &postac, float time, sf::Sprite &hp)
{
    float xv = 0;
    float yv = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        yv = m_speed_;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        xv = -m_speed_;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        xv = m_speed_;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        yv = -m_speed_;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        yv = yv * 3;
        xv = xv * 3;
    }
    hp.move(xv * time, yv * time);
    postac.move(xv * time, yv * time);
}

void character::zdrowie(float dmg, sf::Sprite &hp, sf::Texture &texture)
{
    if (health_ >= 0) {
        health_ = health_ - dmg;
    }
        float procent = health_ / 1000.0;

    std::cout << procent << std::endl;

    try {
        if (procent == 1) {
            if (!texture.loadFromFile("Tekstury/hp100.png")) {
                throw 1;
            }
        } else if (procent<1 && procent>0.9) {
                if (!texture.loadFromFile("Tekstury/hp90.png")) {
                    throw 1;
                }
            } else if (procent<0.9 && procent>0.8) {
                if (!texture.loadFromFile("Tekstury/hp80.png")) {
                    throw 1;
                }
            }
            else if (procent<0.8 && procent>0.7) {
                if (!texture.loadFromFile("Tekstury/hp70.png")) {
                    throw 1;
                }
            }
            else if (procent<0.7 && procent>0.6) {
                if (!texture.loadFromFile("Tekstury/hp60.png")) {
                    throw 1;
                }
            }
            else if (procent<0.6 && procent>0.5) {
                if (!texture.loadFromFile("Tekstury/hp50.png")) {
                    throw 1;
                }
            }
            else if (procent<0.5 && procent>0.4) {
                if (!texture.loadFromFile("Tekstury/hp40.png")) {
                    throw 1;
                }
            }
            else if (procent<0.4 && procent>0.3) {
                if (!texture.loadFromFile("Tekstury/hp30.png")) {
                    throw 1;
                }
            }
            else if (procent<0.3 && procent>0.2) {
                if (!texture.loadFromFile("Tekstury/hp20.png")) {
                    throw 1;
                }
            }
            else if (procent<0.2 && procent>0.1) {
                if (!texture.loadFromFile("Tekstury/hp10.png")) {
                    throw 1;
                }
            }else if (procent<0.1 && procent>=0) {
                if (!texture.loadFromFile("Tekstury/hp0_1.png")) {
                    throw 1;
                }
            }

    } catch (...) {

    }
    hp.setTexture(texture);
    hp.setTextureRect(sf::IntRect(0, 0, 100,20)); //left, top, width, height

}
std::string character::direction()
{
    std::string last;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction_ = "NE";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction_ = "NW";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction_ = "SW";
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                 && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction_ = "SE";
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direction_ = 'W';
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direction_ = 'E';
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            direction_ = 'S';
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            direction_ = 'N';
        }



    return direction_;
}
bool character::limit(float x, float y,sf::Sprite &postac)
{

}
