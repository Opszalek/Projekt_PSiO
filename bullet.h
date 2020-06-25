#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <character.h>



class Bullet : public sf::Sprite
{
public:
    Bullet(sf::Vector2f size, std::string dir_)
    {
        bullet.setSize(size);
        bullet.setFillColor(sf::Color(100, 50, 250));
        dir = dir_;
    };
    Bullet();

    void fire(float time); //funkcja od ruchu pocisku
   // void shoot(character&);//funkcja od tworzenia pocisków
    void setPos(sf::Vector2f newPos) {
        bullet.setPosition(newPos);
    }
    void drawo(sf::RenderWindow &window) {
        window.draw(bullet);
    }
    int bullet_speed=800;
    sf::RectangleShape bullet;
    std::vector<Bullet> bulletVec;
    int dmg;

private:
    std::string dir;

};
#endif // BULLET_H
