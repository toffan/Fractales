#include <iostream>
#include <array>
#include <stdexcept>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "maths.h"
#include "window.h"

#define WINDOW_TITLE "Fractale de Julia"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define TEXTURE_WIDTH 4000
#define TEXTURE_HEIGHT 4000
#define NB_COLORS 256

int main()
{
    // Définitions les couleurs
    std::vector<sf::Color> colors_table(NB_COLORS);
    for(std::size_t i{0}; i<colors_table.size(); ++i){
        colors_table[i].r = 0;
        colors_table[i].g = i;
        colors_table[i].b = i;
        colors_table[i].a = 255;
    } 

    // Ouverture de la fenêtre
    sf::RenderWindow window(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
            WINDOW_TITLE);

    // Création de la texture
    sf::Texture texture;
    /*
    if(!texture.create(TEXTURE_WIDTH, TEXTURE_HEIGHT)){
        throw std::runtime_error("Impossible de créer la texture");
    }//*/

    // Création de l'image
    sf::Image fractal;
    fractal.create(TEXTURE_WIDTH, TEXTURE_HEIGHT, colors_table[0]);

    generate_fractal(fractal, colors_table);
    fractal.saveToFile("debug.png");
    
    // Chargement de la texture
    texture.loadFromImage(fractal);

    // Gestion de la fenêtre
    manage_window(window, texture);


    return EXIT_SUCCESS;
}
