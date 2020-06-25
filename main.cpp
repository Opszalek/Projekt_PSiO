#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <character.h>
#include <TextureManager.h>
#include <bullet.h>
#include <enemy.h>
#include <weapons.h>
#include <uzi.h>
#include <game.h>


int main()
{
    game gra;
    gra.begin();


    // Loading all textures in TextureManager
    TextureManager::loadTexture("texture_guy", "Tekstury/player.png");
    TextureManager::loadTexture("texture_hp", "Tekstury/hp.png");
    TextureManager::loadTexture("texture_wall", "Tekstury/kostka.png");
    TextureManager::loadTexture("enemy1", "Tekstury/emove1.png");
    TextureManager::loadTexture("enemy2", "Tekstury/emove2.png");
    TextureManager::loadTexture("enemy3", "Tekstury/emove3.png");


    // Create main Window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Giereczka");

    // Create event
    sf::Event event;

    // Create clock
    sf::Clock klok;

    //tekstury

    /////////////////



    /////////////////

    TextureManager::getTexture("texture_wall")->setRepeated(true);

    sf::Sprite wall;
    wall.setTexture(*TextureManager::getTexture("texture_wall"));
    wall.setScale(1, 1);
    wall.setTextureRect(sf::IntRect(0, 0, 1280, 720));

    ///////////

    //crate firtst character
    sf::Sprite player_hp;
    player_hp.setTexture(*TextureManager::getTexture("texture_hp"));
    player_hp.setTextureRect(sf::IntRect(0, 0, 100, 10)); //left, top, width, height
    player_hp.setPosition(250.0, 250.0);

    character player;
    player.setTexture(*TextureManager::getTexture("texture_guy"));
    player.setTextureRect(sf::IntRect(0, 0, 49, 43));
    player.setOrigin(25, 21);
    player.setPosition(300.0, 300.0);

    // Create second player character
    sf::Sprite playerone_hp;
    playerone_hp.setTexture(*TextureManager::getTexture("texture_hp"));
    playerone_hp.setTextureRect(sf::IntRect(0, 0, 100, 10)); //left, top, width, height
    playerone_hp.setPosition(350.0, 350.0);

    character playerone;
    playerone.setTexture(*TextureManager::getTexture("texture_guy"));
    playerone.setTextureRect(sf::IntRect(0, 0, 49, 43));
    playerone.setOrigin(25, 21);
    playerone.setPosition(400.0, 400.0);

    //create enemy
    std::vector<enemy> zombieVec;
    Uzi pp;
    weapons* wsk;
    wsk = &pp;
    wsk->ammo = wsk->max_ammo;




    ///////////////
    //Obiekty

    std::vector<Bullet> bulletVec;

    sf::Clock delay;
    sf::Clock delay2;
    sf::Clock delay3;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsed = klok.restart();
        float czas = elapsed.asSeconds();
        window.clear(sf::Color::White);

        //funkcje

        player.movement(player, czas, player_hp,window);
        playerone.movement2(playerone, czas, playerone_hp);




        //testy
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            playerone.zdrowie(-1, playerone_hp, *TextureManager::getTexture("texture_hp"));

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)&& (delay3.getElapsedTime().asMilliseconds() > 300)) {
            wsk->change(1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)&& (delay3.getElapsedTime().asMilliseconds() > 300)) {
            wsk->change(1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (delay2.getElapsedTime().asMilliseconds() > 50)) {
            enemy zombie;
            zombie.setTexture(*TextureManager::getTexture("enemy1"));
            zombie.setTextureRect(sf::IntRect(0, 0, 288, 311));
            zombie.setPosition(rand() % window.getSize().x , rand() % window.getSize().y);
            zombie.scale(0.3, 0.3);
            zombie.setOrigin(144, 155);
            zombieVec.emplace_back(zombie);
            delay2.restart();


        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)
            && (delay.getElapsedTime().asMilliseconds() > 30)) {
           wsk->shoot(player);
            delay.restart();
        }

        //tworzenie pocisków
        /*
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)
            && (delay.getElapsedTime().asMilliseconds() > 30)) {
            Bullet newbullet(sf::Vector2f(10, 10), player.direction());
            newbullet.setPos(sf::Vector2f(player.getPosition().x, player.getPosition().y));
            if (player.ismoving == true) {
                newbullet.bullet_speed = newbullet.bullet_speed + player.m_speed();
            }
            bulletVec.emplace_back(newbullet);

            delay.restart();
        }
*/
        //sprawdzanie kolizji
        for (unsigned int i = 0;i < wsk->bulletVec.size(); i++) {
            if (wsk->bulletVec[i].bullet.getPosition().x > window.getSize().x
                || wsk->bulletVec[i].bullet.getPosition().x < 0
                || wsk->bulletVec[i].bullet.getPosition().y > window.getSize().y
                || wsk->bulletVec[i].bullet.getPosition().y < 0) {
                wsk->bulletVec.erase(wsk->bulletVec.begin() + i);

            }
            if (wsk->bulletVec[i].bullet.getGlobalBounds().intersects(playerone.getGlobalBounds())) {
                playerone.zdrowie(100, playerone_hp, *TextureManager::getTexture("texture_hp"));
                wsk->bulletVec.erase(wsk->bulletVec.begin() + i);


            }
//kolizje zombie z kulą
            for (unsigned int k = 0; k < gra.zombieVec.size(); k++) {
                for (unsigned int i = 0; i < wsk->bulletVec.size(); i++) {
                    if (wsk->bulletVec[i].bullet.getGlobalBounds().intersects(
                            gra.zombieVec[k].getGlobalBounds())) {
                        wsk->bulletVec.erase(wsk->bulletVec.begin() + i);
                        if (gra.zombieVec[k].alive(wsk->bulletVec[i].dmg)) {
                            gra.zombieVec.erase(gra.zombieVec.begin() + k);

                        }
                    }
                }
            }

        }
        //poziomy

        gra.level(*TextureManager::getTexture("enemy1"),window);
        //rysowanie
        window.draw(wall);
        window.draw(player_hp);
        window.draw(playerone_hp);
        window.draw(player);
        window.draw(playerone);
        //rysowanie zombie
        for (auto &z : gra.zombieVec) {
            if (gra.bite(player, z)) {
                player.zdrowie(z.dmg, player_hp, *TextureManager::getTexture("texture_hp"));
            }
            window.draw(z);
            z.find_way(player, czas);
             }
        //rysowanie bulletsow
        for (auto &r : wsk->bulletVec) {
            r.drawo(window);
            r.fire(czas);
        }

        window.draw(wsk->ile_ammo);
        window.display();
 }
    return 0;
}
