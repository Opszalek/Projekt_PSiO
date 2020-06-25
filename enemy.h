#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class enemy : public sf::Sprite
{
public:
    enemy();
    void find_way(sf::Sprite&,float);
    bool alive(float);
    int dmg;
private:
    float health_ = 1000;
    float m_speed_ =50.0;
    float health_max = 1000;

};

#endif // ENEMY_H
