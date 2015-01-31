#include "window.h"

void manage_window(sf::RenderWindow &window, sf::Texture &texture) {
    // Création du sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::Vector2u w_size{window.getSize()}, t_size{texture.getSize()};
    sprite.setTextureRect(sf::IntRect(
                (t_size.x - w_size.x)/2,
                (t_size.y - w_size.y)/2,
                (t_size.x + w_size.x)/2,
                (t_size.y + w_size.y)/2));


    window.setFramerateLimit(FPS_MAX);

    while(window.isOpen()){
        window.clear();
        window.draw(sprite);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
    }
}
