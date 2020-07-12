#ifndef BOX_H
#define BOX_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Box : public sf::Sprite
{
public:
    Box(sf::Texture&,sf::Window&);
};

#endif // BOX_H
