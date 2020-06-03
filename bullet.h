#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


class Bullet
{
public:
    Bullet(sf::Vector2f size) { bullet.setSize(size);
     bullet.setFillColor(sf::Color(100, 50, 250));};

    void fire(float time,std::string direction_);
    int getRight() { return bullet.getPosition().x + bullet.getSize().x; }
    int getLeft() { return bullet.getPosition().x; }
    int getTop() { return bullet.getPosition().y; }
    int getBottom() { return bullet.getPosition().y + bullet.getSize().y; }
    void setPos(sf::Vector2f newPos) {
        bullet.setPosition(newPos);
    }
    void draw(sf::RenderWindow &window) {
        window.draw(bullet);
    }
private:
    sf::RectangleShape bullet;



};

#endif // BULLET_H
