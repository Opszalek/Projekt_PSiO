#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class character : public sf::Sprite
{
public:
    character(sf::Texture&,sf::Texture&);
    int m_speed(){return m_speed_;}; //prędkość poruszania się
    float sprint; // Czas przez jaki postać może biec sprintem
    void movement(sf::Sprite &postac, float time,int,sf::RenderWindow&);//poruszanie sie postaci
    void zdrowie(float dmg);//funkcja zadająca obrażenia oraz funkcja do healania
    std::string direction();
    bool ismoving;// do sprawdzania czy postać sie porusza, ponieważ czasami trzeba prędkość pocisku zwiększyć
    sf::Sprite player_hp;
    float health_ = 100; // zdrowie czempiona naszego
private:
    float health_max = 100;
    int m_speed_ = 130;//predkość poruszania się
    std::string direction_="E"; // kierunek w która jest ustawiona postać oraz kierunek lotu pocisku ustawiony na S po to by pocisk nie stał w miejscu

};

#endif // CHARACTER_H
