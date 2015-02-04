#include "window.hpp"

#include <SFML/Graphics/Sprite.hpp> //sf::Sprite
#include <SFML/Graphics/Rect.hpp> //sf::Rect
#include <SFML/Window/Event.hpp> //sf::Event
#include <SFML/Window/Mouse.hpp> //sf::Mouse

void manage_window(sf::RenderWindow &window, sf::Texture &texture) {
    sf::Rect<int> sprite_rect {
            sf::Vector2<int>(texture.getSize() - window.getSize()) / 2,
            sf::Vector2<int>(window.getSize())};
    const std::tuple<int, int> limits_left {
            0, texture.getSize().x - window.getSize().x};
    const std::tuple<int, int> limits_top {
            0, texture.getSize().y - window.getSize().y}; 

    // Création du sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Event event;
    sf::Vector2<int> mouse_prev_pos;
    sf::Vector2<int> mouse_dplt;


    window.setFramerateLimit(FPS_MAX);

    while(window.isOpen()){
        sprite.setTextureRect(sprite_rect);

        window.clear();
        window.draw(sprite);
        window.display();


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed
                    && event.mouseButton.button == sf::Mouse::Left) {
                mouse_prev_pos = sf::Mouse::getPosition(window);
                while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    mouse_dplt = sf::Mouse::getPosition(window) - mouse_prev_pos; 
                    move_rect(sprite_rect, -mouse_dplt,
                            limits_left, limits_top);


                    sprite.setTextureRect(sprite_rect);
                    mouse_prev_pos += mouse_dplt;

                    window.clear();
                    window.draw(sprite);
                    window.display();
                }
            }
            else if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}


void move_rect(
        sf::Rect<int> &rect,
        const sf::Vector2<int> displacement,
        const std::tuple<int, int> limits_left,
        const std::tuple<int, int> limits_top) {
    rect.left += displacement.x;
    rect.top += displacement.y;
    if(rect.left <= std::get<0>(limits_left)) {
        rect.left = std::get<0>(limits_left);
    }
    else if(rect.left >= std::get<1>(limits_left)) {
        rect.left = std::get<1>(limits_left);
    }

    if(rect.top <= std::get<0>(limits_top)) {
        rect.top = std::get<0>(limits_top);
    }
    else if(rect.top >= std::get<1>(limits_top)) {
        rect.top = std::get<1>(limits_top);
    }
}
