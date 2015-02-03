#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SFML/Graphics/Texture.hpp> //sf::Texture
#include <SFML/Graphics/RenderWindow.hpp> //sf::RenderWindow

const unsigned int FPS_MAX{60};

void manage_window(sf::RenderWindow &window, sf::Texture &texture);

#endif // WINDOW_H_INCLUDED
