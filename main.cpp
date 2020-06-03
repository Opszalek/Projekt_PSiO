#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <character.h>
#include <TextureManager.h>
#include <bullet.h>
void ruch(sf::Sprite &rectangle,float time)
{
    float xv = 0;
    float yv = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        yv = 50;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        xv = -50;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        xv = 50;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        yv = -50;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        yv = yv * 3;
        xv = xv * 3;
    }
    rectangle.move(xv * time, yv * time);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Giereczka");

    sf::Event event;
    sf::Clock klok;


 ////////////////
    sf::Texture texture_guy;
    if (!texture_guy.loadFromFile("Tekstury/head.png")) {
        return 1;
    }

    sf::Sprite guy;
    guy.setTexture(texture_guy);
    guy.setTextureRect(sf::IntRect(0, 0, 45, 90)); //left, top, width, height
    guy.setPosition(500.0, 400.0);

/////////////////

    sf::Texture texture_hp;
    if (!texture_hp.loadFromFile("Tekstury/hp100.png")) {
        return 1;
    }

    sf::Sprite boy_hp;
    boy_hp.setTexture(texture_hp);
    boy_hp.setTextureRect(sf::IntRect(0, 0, 100,20)); //left, top, width, height
    boy_hp.setPosition(275.0, 275.0);
/////////////////




    sf::Texture texture_wall;
    if (!texture_wall.loadFromFile("Tekstury/trawa.png")) {
        return 1;
    }
    texture_wall.setRepeated(true);

    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setScale(1, 1);
    wall.setTextureRect(sf::IntRect(0, 0, 800, 600));
///////////
    sf::Texture boy_texture;
    if (!boy_texture.loadFromFile("Tekstury/head1.png")) {
        return 1;
    }

    character boy;
    boy.setTexture(boy_texture);
    boy.setTextureRect(sf::IntRect(0,0,45,90));
    boy.setPosition(300.0, 300.0);


    sf::Vector2f p_size(10.0, 10.0);
    Bullet pocisk(p_size);

    ///////////////
    //Obiekty

    std::vector<Bullet> bulletVec;


    sf::Clock delay;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }


        sf::Time elapsed = klok.restart();
        float czas = elapsed.asSeconds();
        ruch(guy,czas);
        boy.movement(boy, czas,boy_hp);

        window.clear(sf::Color::White);


        ////
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            boy.zdrowie(0.0001, boy_hp, texture_hp);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && (delay.getElapsedTime().asMilliseconds()>150)) {

            Bullet newbullet(sf::Vector2f(10, 10));
            newbullet.setPos(sf::Vector2f(boy.getPosition().x, boy.getPosition().y));
            bulletVec.emplace_back(newbullet);
            delay.restart();
        }
    ////


        window.draw(wall);
        window.draw(guy);
        window.draw(boy_hp);
        window.draw(boy);

        for (auto &r : bulletVec) {

            r.draw(window);
            r.fire(czas,boy.direction());

        }

      window.display();


  }
  return 0;
}
