#include "weapons.h"

weapons::weapons()
{

    font.loadFromFile("arial.ttf");
    ile_ammo.setFont(font);
    ile_ammo.setCharacterSize(24);
    ile_ammo.setFillColor(sf::Color::Red);
    ile_ammo.setStyle(sf::Text::Bold);
    ile_ammo.setString("Ammo");
    ile_ammo.setPosition(0, 0);


    ammo = max_ammo;
    dmg = 10;

}

void weapons::shoot(character & player)
{if(this->ammo>0 || nr==1){
    Bullet newbullet(sf::Vector2f(5, 5), player.direction());
    newbullet.setPos(sf::Vector2f(player.getPosition().x + 10, player.getPosition().y + 20));
    newbullet.dmg = this->dmg;
    if(nr==2){
    this->ammo--;
    ile_ammo.setString(std::to_string(ammo) + "/" + std::to_string(max_ammo));
    } else {ile_ammo.setString("Infinity");
    }
    if (player.ismoving == true) {
        newbullet.bullet_speed = newbullet.bullet_speed + player.m_speed();
    }
    bulletVec.emplace_back(newbullet);
    }


}

void weapons::change()
{
    if (nr == 1) { //uzi
        nr = 2;
        dmg = dmg_uzi;
        fire_delay = 50;
        ile_ammo.setString(std::to_string(ammo) + "/" + std::to_string(max_ammo));
    } else if (nr == 2) { // pistolet
        nr = 1;
        dmg = dmg_pistol;
        fire_delay = 150;
        ile_ammo.setString("Infinity");
    }


}

