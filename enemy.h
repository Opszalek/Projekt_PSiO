#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class enemy : public sf::Sprite
{
public:
    enemy(sf::Texture &tex, sf::Window &window,int);
    void find_way(sf::Sprite&,float);
    bool alive(float);
    int dmg;
    sf::Clock hit;
private:
    float health_ = 100.0;
    float m_speed_ =30.0;
    float health_max = 100.0;

};

#endif // ENEMY_H
