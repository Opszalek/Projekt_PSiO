#include "bullet.h"
#include <character.h>



void Bullet::fire(float time)
{


    if (dir == "NE") {
        bullet.move(bullet_speed * time, -bullet_speed * time);
    } else if (dir == "SE") {
        bullet.move(bullet_speed * time, bullet_speed * time);
    } else if (dir == "SW") {
        bullet.move(-bullet_speed * time, bullet_speed * time);
    } else if (dir == "NW") {
        bullet.move(-bullet_speed * time, -bullet_speed * time);
    } else if (dir == "N") {
        bullet.move(0, -bullet_speed * time);
    } else if (dir == "E") {
        bullet.move(bullet_speed * time, 0 * time);
    } else if (dir == "S") {
        bullet.move(0, bullet_speed * time);
    } else if (dir == "W") {
        bullet.move(-bullet_speed * time, 0);
    }


}

void Bullet::shoot(character player)
{
    Bullet newbullet(sf::Vector2f(10, 10), player.direction());
    newbullet.setPos(sf::Vector2f(player.getPosition().x + 10, player.getPosition().y + 20));
    if (player.ismoving == true) {
        newbullet.bullet_speed = newbullet.bullet_speed + player.m_speed();
    }
    bulletVec.emplace_back(newbullet);
}
