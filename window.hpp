#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <tuple> //std::tuple

#include <SFML/Graphics/RenderWindow.hpp> //sf::RenderWindow
#include <SFML/Graphics/Texture.hpp> //sf::Texture


const unsigned int FPS_MAX{60};


void manage_window(
        sf::RenderWindow &window,
        sf::Texture &texture);

void move_rect(
        sf::Rect<int> &rect,
        const sf::Vector2<int> displacement,
        const std::tuple<int, int> limits_left,
        const std::tuple<int, int> limits_top);

#endif // WINDOW_H_INCLUDED
