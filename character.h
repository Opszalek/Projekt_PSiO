#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class character : public sf::Sprite
{
public:
    character();
    float health; //zdrowie
    int m_speed; //prędkość poruszania się
    float sprint; // Czas przez jaki postać może biec sprintem
    void movement(sf::Sprite &postac, float time,sf::Sprite &hp);
    void zdrowie(float dmg,sf::Sprite &hp,sf::Texture & texture);
    std::string direction();

private:
    int health_ = 1000;
    int m_speed_ = 100;
    float sprint_ = 5;
    bool limit(float x,float y,sf::Sprite &postac);
    std::string direction_;
};

#endif // CHARACTER_H
