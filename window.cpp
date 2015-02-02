#include "window.h"

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
    sf::Vector2<int> mouse_pos, mouse_prev_pos;

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
                    mouse_pos = sf::Mouse::getPosition(window);
                    rect_sprite.left += mouse_prev_pos.x - mouse_pos.x;
                    rect_sprite.top += mouse_prev_pos.y - mouse_pos.y;
                    sprite.setTextureRect(rect_sprite);
                    mouse_prev_pos = mouse_pos;

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
