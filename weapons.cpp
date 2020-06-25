#include "weapons.h"

weapons::weapons()
{

    font.loadFromFile("arial.ttf");
    ile_ammo.setFont(font);
    ile_ammo.setCharacterSize(24);
    ile_ammo.setFillColor(sf::Color::Red);
    ile_ammo.setStyle(sf::Text::Bold);
    ile_ammo.setString("Ammo");
    ile_ammo.setPosition(0,0);

}

void weapons::shoot(character & player)
{if(this->ammo>0){
    Bullet newbullet(sf::Vector2f(10, 10), player.direction());
    newbullet.setPos(sf::Vector2f(player.getPosition().x + 10, player.getPosition().y + 20));
    newbullet.dmg = this->dmg;
    this->ammo--;
    if (player.ismoving == true) {
        newbullet.bullet_speed = newbullet.bullet_speed + player.m_speed();
    }
    bulletVec.emplace_back(newbullet);
    }
    ile_ammo.setString(std::to_string(ammo) + "/" + std::to_string(max_ammo));
}

void weapons::change(int str)
{
    if (str == 1) {
        if (nr < 3) {
            nr++;
        } else {
            nr = 1;
        }
    } else if (str == 1) {
        if (nr > 1) {
            nr--;
        } else {
            nr = 3;
        }
    }
    if (nr == 1)
    {//TU będzie uzi


    } else if (nr == 2)
    {//tu będzie Pistol casual

    }else if(nr==3)
    {
        //jakiś KM

    }


}

