#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class character : public sf::Sprite
{
public:
    character();
    int m_speed(){return m_speed_;}; //prędkość poruszania się
    float sprint; // Czas przez jaki postać może biec sprintem
    void movement(sf::Sprite &postac, float time,sf::Sprite &hp,sf::RenderWindow&);//poruszanie sie postaci
    void movement2(sf::Sprite &postac, float time,sf::Sprite &hp);//poruszanie sie drugiej postaci 2 players mode
    void zdrowie(float dmg,sf::Sprite &hp,sf::Texture & texture);//funkcja zadająca obrażenia oraz funkcja do healania
    std::string direction();
    bool ismoving;// do sprawdzania czy postać sie porusza, ponieważ czasami trzeba prędkość pocisku zwiększyć
    sf::Sprite player_hp;
private:
    float health_ = 1000; // zdrowie czempiona naszego
    float health_max = 1000;
    int m_speed_ = 100;//predkość poruszania się
    bool limit(float x,float y,sf::Sprite &postac);// jeszcze nie wiem ale byl na to jakiś zamysł
    std::string direction_="S"; // kierunek w która jest ustawiona postać oraz kierunek lotu pocisku ustawiony na S po to by pocisk nie stał w miejscu

};

#endif // CHARACTER_H
