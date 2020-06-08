#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


class Bullet : public sf::Sprite
{
public:
    Bullet(sf::Vector2f size, std::string dir_)
    {
        bullet.setSize(size);
        bullet.setFillColor(sf::Color(100, 50, 250));
        dir = dir_;
    };

    void fire(float time);
    void setPos(sf::Vector2f newPos) {
        bullet.setPosition(newPos);
    }
    void drawo(sf::RenderWindow &window) {
        window.draw(bullet);
    }
    int bullet_speed=100;
    sf::RectangleShape bullet;
private:
    std::string dir;

};
#endif // BULLET_H
