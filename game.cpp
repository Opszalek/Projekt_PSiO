#include "game.h"



game::game()
{
    font.loadFromFile("arial.ttf");
    punkty.setFont(font);
    punkty.setCharacterSize(24);
    punkty.setFillColor(sf::Color::Green);
    punkty.setStyle(sf::Text::Bold);
    punkty.setString("Points");
    punkty.setPosition(300, 0);
    box_tex.loadFromFile("Tekstury/box.png");
    zombie_tex.loadFromFile("Tekstury/emove1.png");
    napis.setFont(font);
    napis.setCharacterSize(24);
    napis.setFillColor(sf::Color::White);
    napis.setStyle(sf::Text::Bold);
    napis.setPosition(400, 120);
    napis2.setFont(font);
    napis2.setCharacterSize(24);
    napis2.setFillColor(sf::Color::White);
    napis2.setStyle(sf::Text::Bold);
    napis2.setPosition(550, 0);

}

void game::level(sf::Window &window, character & player,weapons & weapon)
{
    if (zombieVec.empty()) {
        Box skrzynka(box_tex, window);
        boxvec.emplace_back(skrzynka);
        for (int i = 0; i < iloscenemy; i++) {
            enemy zombie(zombie_tex,window,trudnosc);
            zombieVec.emplace_back(zombie);
        }
        iloscenemy += 3;
        if ((poziom % 4) == 0) {
            weapon.max_ammo += 50;
            weapon.dmg_uzi += 2;
            weapon.dmg_pistol += 1;
            napis.setString("+++Uzi ammo +50+++\n +++Uzi dmg +2+++\n +++Pistol dmg +1+++");
            timer.restart();
        }

        napis2.setString("Lvl:" + std::to_string(poziom));
        poziom++;
    }
    if (timer.getElapsedTime().asMilliseconds() > 2000) {
        napis.setString("");
    }
    for (unsigned int i = 0; i < boxvec.size(); i++) {
        if (boxvec[i].getGlobalBounds().intersects(player.getGlobalBounds())) {
            boxvec.erase(boxvec.begin() + i);
            weapon.ammo = weapon.max_ammo;
            if (player.health_ < 100) {
                player.health_ += 50;
                if (player.health_ > 100) {
                    player.health_ = 100;
                }
                player.zdrowie(0);//aby odświeżyć hp
            }
            if (weapon.nr == 2) {
                weapon.ile_ammo.setString(std::to_string(weapon.ammo) + "/"
                                          + std::to_string(weapon.max_ammo));
            }
        }
    }

}

void game::level(sf::Window &window)
{
    int x = rand() % 10;
    if(x==3)
    {
        Box skrzynka(box_tex, window);
        boxvec.emplace_back(skrzynka);
    }
}
void game::begin()
{
    std::string bufor;
    std::cout << "Witaj poszukiwaczu przygod\n wlasnie znalazles moja okropna gierke" << std::endl;
    std::cout << "Milo mi cie widziec w Menel Defender" << std::endl;
    std::cout << "Sterowanie: \n Poruszanie sie - WSAD \n Zmiana broni - Q \n Strzelanie - Space \n Sprint - LShift" << std::endl;
    std::cout << "Wybierz poziom trudnosci \n1-easy \n2-medium \n3-hard(sprint nie dziala :()" << std::endl;
    std::cin >> bufor;
    while (bufor != "1" && bufor != "2" && bufor !="3") {
        std::cout << "Nie jasne??" << std::endl;
        std::cin >> bufor;
    }
    trudnosc = std::stoi(bufor);

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
    if (player.getGlobalBounds().intersects(enemy.getGlobalBounds())
        && (enemy.hit.getElapsedTime().asMilliseconds() > 300)) {
        enemy.hit.restart();
        return true;
    } else {
        return false;
    }
}

void game::rysowanie(sf::RenderWindow &win)
{
    for (auto &r : boxvec) {
        win.draw(r);
    }
    win.draw(punkty);
    win.draw(napis);
    win.draw(napis2);

}

void game::play_again(sf::RenderWindow &win)
{
    int rekord = 0;
    int linia;
    std::fstream plik;

    plik.open("rekordy.txt", std::ios::in);


    plik >> linia;
     plik.close();
    if (points < linia) {
        rekord = linia;
    } else if (points > linia){
        rekord = points;
        plik.open("rekordy.txt", std::ios::out);
        plik << rekord << std::endl;
        plik.close();
    }



    if (points >= rekord) {
        punkty.setString("New Record:" + std::to_string(points));
    } else if (points < rekord) {
        punkty.setString("Twoj wynik:"+std::to_string(points)+"   "+"Rekord:"+std::to_string(rekord));
    }

    restart.setFont(font);
    restart.setCharacterSize(24);
    restart.setFillColor(sf::Color::Red);
    restart.setStyle(sf::Text::Bold);
    restart.setString("Press G to Play Again!");
    restart.setPosition(1000, 600);
    win.draw(punkty);
    win.draw(restart);
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
     poziom = 1;
     zombieVec.clear();
     boxvec.clear();
}

