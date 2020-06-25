#include "game.h"



game::game()
{

}

void game::level(sf::Texture &tex, sf::Window &window)
{
    if (zombieVec.empty()) {
        for (int i = 0; i < iloscenemy; i++) {
            enemy zombie;
            zombie.setTexture(tex);
            zombie.setTextureRect(sf::IntRect(0, 0, 288, 311));
            zombie.setPosition(rand() % window.getSize().x, rand() % window.getSize().y);
            zombie.scale(0.3, 0.3);
            zombie.setOrigin(144, 155);
            if (trudnosc == 1) {
                zombie.dmg = 10;
            }else if (trudnosc == 2) {
                zombie.dmg = 15;
            }else if (trudnosc == 3) {
                zombie.dmg = 20;
            }
            zombieVec.emplace_back(zombie);


        }
    }

}

void game::begin()
{
    std::string bufor;
    std::cout << "Witaj poszukiwaczu przygod\n wlasnie znalazles moja okropna gierke" << std::endl;
    std::cout << "Milo mi cie widziec w Menel Defender" << std::endl;
    std::cout << "Wybierz poziom trudnosci 1-easy 2-medium 3-hard" << std::endl;
    std::cin >> bufor;
    while (bufor != "1" && bufor != "2") {
        std::cout << "Nie jasne??" << std::endl;
        std::cin >> bufor;
    }
    trudnosc = std::stoi(bufor);
    std::cout << "Wybierz ilosc graczy 1/2" << std::endl;
    std::cin >> bufor;
    while (bufor != "1" && bufor != "2") {
        std::cout << "Nie jasne??" << std::endl;
        std::cin >> bufor;
    }
    players = std::stoi(bufor);

    switch (trudnosc) {
    case 1:
        iloscenemy = 2;
        break;
    case 2:
        iloscenemy = 4;
        break;
    case 3:
        iloscenemy = 6;
        break;

    }
}

bool game::bite(character &player, enemy &enemy)
{
    if (player.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
        return true;
    } else {
        return false;
    }
}
