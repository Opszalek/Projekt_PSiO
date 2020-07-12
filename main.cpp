#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <character.h>
#include <TextureManager.h>
#include <bullet.h>
#include <enemy.h>
#include <weapons.h>
#include <game.h>
#include <box.h>


int main()
{
    game gra;
    gra.begin();


    // Loading all textures in TextureManager
    TextureManager::loadTexture("texture_guy", "Tekstury/player.png");
    TextureManager::loadTexture("over", "Tekstury/over.png");
    TextureManager::loadTexture("texture_hp", "Tekstury/hp.png");
    TextureManager::loadTexture("texture_wall", "Tekstury/tlo.png");


    // Create main Window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Menel_Defender version pre-alpha 0.0000001 ");


    //tekstury

    /////////////////



    /////////////////

    TextureManager::getTexture("texture_wall")->setRepeated(true);

    sf::Sprite wall;
    wall.setTexture(*TextureManager::getTexture("texture_wall"));
    wall.setScale(1, 1);
    wall.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    ///////////
    sf::Sprite game_over;
    game_over.setTexture(*TextureManager::getTexture("over"));
    game_over.setOrigin(540, 540);
    game_over.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    //crate firtst character

    sf::Music gun1;
    gun1.openFromFile("Tekstury/gun2.ogg");
    sf::Music gun2;
    gun2.openFromFile("Tekstury/gun1.ogg");
    gun1.play();
    gun1.setLoop(true);
    gun2.play();
    gun2.setLoop(true);

    character player(*TextureManager::getTexture("texture_guy"),*TextureManager::getTexture("texture_hp"));



    ///////////////
    //Obiekty

    sf::Event event;

    weapons gun;

    std::vector<enemy> zombieVec;
    std::vector<Bullet> bulletVec;

    sf::Clock klok;
    sf::Clock delay;
    sf::Clock delay2;
    sf::Clock delay3;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
//zmiana weaponsa
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Q) {
                    gun.change();
                }
            }
        }

        sf::Time elapsed = klok.restart();
        float czas = elapsed.asSeconds();


//poruszanie sie
        if(player.health_>0){
        player.movement(player, czas, gra.trudnosc, window);

//strzelanie
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
            && (delay.getElapsedTime().asMilliseconds() > gun.fire_delay)) {
            gun.shoot(player);
            delay.restart();
            if (gun.nr == 1) {
                gun1.setVolume(50);
            } else {
                gun1.setVolume(0);
            }
            if (gun.nr == 2 && gun.ammo > 0) {
                gun2.setVolume(50);
            } else {
                gun2.setVolume(0);
            }

        } else if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
            gun1.setVolume(0);
            gun2.setVolume(0);
       }


        //sprawdzanie kolizji z oknem
        for (unsigned int i = 0; i < gun.bulletVec.size(); i++) {
            if (gun.bulletVec[i].bullet.getPosition().x > window.getSize().x
                || gun.bulletVec[i].bullet.getPosition().x < 0
                || gun.bulletVec[i].bullet.getPosition().y > window.getSize().y
                || gun.bulletVec[i].bullet.getPosition().y < 0) {
                gun.bulletVec.erase(gun.bulletVec.begin() + i);
            }

            //kolizje zombie z kulą
            for (unsigned int k = 0; k < gra.zombieVec.size(); k++) {
                for (unsigned int i = 0; i < gun.bulletVec.size(); i++) {
                    if (gun.bulletVec[i].bullet.getGlobalBounds().intersects(
                            gra.zombieVec[k].getGlobalBounds())) {

                        gun.bulletVec.erase(gun.bulletVec.begin() + i);
                        if (gra.zombieVec[k].alive(gun.bulletVec[i].dmg)) {
                            gra.zombieVec.erase(gra.zombieVec.begin() + k);
                            gra.level(window);
                            gra.points += 10*gra.trudnosc;
                            gra.punkty.setString("Points :" + std::to_string(gra.points));
                        }
                    }
                }
            }
        }
        //poziomy

        gra.level(window, player, gun);
        //rysowanie
        window.draw(wall); //tlo

        gra.rysowanie(window);
        window.draw(player.player_hp);

        window.draw(player);

        //rysowanie zombie i szukanie way to playersa
        for (auto &z : gra.zombieVec) {
            if (gra.bite(player, z)) {
                player.zdrowie(z.dmg);
            }
            window.draw(z);
            z.find_way(player, czas);
        }
        //rysowanie bulletsow
        for (auto &r : gun.bulletVec) {
            r.drawo(window);
            r.fire(czas);
        }
        window.draw(gun.ile_ammo);
    }
//Koniec gry oraz gra od nowa
        if (player.health_ <= 0) {
            gun1.stop();
            gun2.stop();
            window.clear(sf::Color::White);
            gra.play_again(window);
            window.draw(game_over);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                gra.points = 0;
                gun.ammo = gun.max_ammo = 100;
                gun.dmg_uzi = 10;
                gun.dmg_pistol = 10;
                player.health_ = 100;
                player.zdrowie(0);
                gra.punkty.setString("Points");
                gun1.play();
                gun1.setLoop(true);
                gun2.play();
                gun2.setLoop(true);
            }

        }
        window.display();
    }
return 0;
}
