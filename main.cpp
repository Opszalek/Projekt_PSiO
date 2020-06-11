#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <character.h>
#include <TextureManager.h>
#include <bullet.h>
#include <enemy.h>




int main()
{
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




    ///////////////
    //Obiekty

    std::vector<Bullet> bulletVec;

    sf::Clock delay;
    sf::Clock delay2;
    sf::Clock delay3;
    int razraz = 0;
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

        player.movement(player, czas, player_hp);
        playerone.movement2(playerone, czas, playerone_hp);




        //testy
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            playerone.zdrowie(-1, playerone_hp, *TextureManager::getTexture("texture_hp"));

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)&& (delay3.getElapsedTime().asMilliseconds() > 300)) {

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
            razraz++;
            std::cout << razraz << std::endl;
        }



        //tworzenie pocisków
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)
            && (delay.getElapsedTime().asMilliseconds() > 30)) {
            Bullet newbullet(sf::Vector2f(10, 10), player.direction());
            newbullet.setPos(sf::Vector2f(player.getPosition().x + 10, player.getPosition().y + 20));
            if (player.ismoving == true) {
                newbullet.bullet_speed = newbullet.bullet_speed + player.m_speed();
            }
            bulletVec.emplace_back(newbullet);

            delay.restart();
        }
        //sprawdzanie kolizji
        for (auto i = 0;i <bulletVec.size(); i++) {
            if (bulletVec[i].bullet.getPosition().x > window.getSize().x
                || bulletVec[i].bullet.getPosition().x < 0
                || bulletVec[i].bullet.getPosition().y > window.getSize().y
                || bulletVec[i].bullet.getPosition().y < 0) {
                bulletVec.erase(bulletVec.begin() + i);

            }
            if (bulletVec[i].bullet.getGlobalBounds().intersects(playerone.getGlobalBounds())) {
                playerone.zdrowie(100, playerone_hp, *TextureManager::getTexture("texture_hp"));
                bulletVec.erase(bulletVec.begin() + i);


            }

            for (auto k = 0; k < zombieVec.size(); k++) {
                for (auto i = 0; i < bulletVec.size(); i++) {
                    if (bulletVec[i].bullet.getGlobalBounds().intersects(
                            zombieVec[k].getGlobalBounds())) {
                        bulletVec.erase(bulletVec.begin() + i);
                        if (zombieVec[k].alive(100)) {
                            zombieVec.erase(zombieVec.begin() + k);
                            razraz--;
                        }
                    }
                }
            }

        }

        //rysowanie
        window.draw(wall);
        window.draw(player_hp);
        window.draw(playerone_hp);
        window.draw(player);
        window.draw(playerone);

        for (auto &z : zombieVec) {
            window.draw(z);
            z.find_way(player, czas);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)
                && (delay3.getElapsedTime().asMilliseconds() > 300)) {
                z.rotate(10);
            }

        }
        for (auto &r : bulletVec) {
            r.drawo(window);
            r.fire(czas);}


        window.display();
 }
    return 0;
}
