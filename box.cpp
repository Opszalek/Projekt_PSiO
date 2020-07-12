#include "box.h"

Box::Box(sf::Texture &tex, sf::Window &win)
{
    this->setTexture(tex);
    this->setScale(0.1, 0.1);
    this->setOrigin(25, 25);
    this->setPosition(rand() % win.getSize().x, rand() % win.getSize().y);
}
