#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class enemy : public sf::Sprite
{
public:
    enemy();
    void move(sf::Sprite &enemy, float time);
    void find_way(sf::Sprite & enemy);
    bool alive(float dmg);
private:
    float health_ = 1000;
    int m_speed_ = 100;
    float health_max = 1000;

};

#endif // ENEMY_H
