#include "window.hpp"

void manage_window(sf::RenderWindow &window, sf::Texture &texture) {
    // Création du sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2u w_size{window.getSize()}, t_size{texture.getSize()};
    sf::IntRect rect_sprite(
                (t_size.x - w_size.x)/2,
                (t_size.y - w_size.y)/2,
                (t_size.x + w_size.x)/2,
                (t_size.y + w_size.y)/2);

    window.setFramerateLimit(FPS_MAX);

    sf::Event event;
    sf::Vector2<int> mouse_prev_pos, mouse_dplt;

    int right_lim{t_size.x - w_size.x}, bottom_lim{t_size.y - w_size.y}; 

    while(window.isOpen()){
        sprite.setTextureRect(rect_sprite);

        window.clear();
        window.draw(sprite);
        window.display();


        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed
                    && event.mouseButton.button == sf::Mouse::Left) {
                mouse_prev_pos = sf::Mouse::getPosition(window);
                while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    mouse_dplt = sf::Mouse::getPosition(window) - mouse_prev_pos;
                    rect_sprite.left -= mouse_dplt.x;
                    rect_sprite.top -= mouse_dplt.y;
                    if(rect_sprite.left <= 0) {
                        rect_sprite.left = 0;
                    }
                    else if(rect_sprite.left >= right_lim) {
                        rect_sprite.left = right_lim;
                    }

                    if(rect_sprite.top <= 0) {
                        rect_sprite.top = 0;
                    }
                    else if(rect_sprite.top >= bottom_lim) {
                        rect_sprite.top = bottom_lim;
                    }

                    sprite.setTextureRect(rect_sprite);
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
