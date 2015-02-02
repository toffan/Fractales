#include <vector> //std:vector

#include <SFML/Graphics.hpp> //sf::Image, sf::Texture
#include <SFML/Window.hpp> //sf::RenderWindow, sf::VideoMode

#include "maths.h"
#include "clo.h"
#include "window.h"

const std::string WINDOW_TITLE = "Fractale de Julia";
const std::size_t NB_COLORS = 256;

int main(int argc, char** argv) {
    try {
        // Définitions les couleurs
        std::vector<sf::Color> colors_table(NB_COLORS);
        for(std::size_t i{0}; i<colors_table.size(); ++i) {
            colors_table[i].r = 0;
            colors_table[i].g = 255-i;
            colors_table[i].b = 255-i;
            colors_table[i].a = 255;
        }

        // Récupération des options
        CLO clo(argc, argv);

        // Ouverture de la fenêtre
        sf::RenderWindow window(
                sf::VideoMode(
                    clo.get_window_size().x,
                    clo.get_window_size().y),
                WINDOW_TITLE);

        // Création de l'image
        sf::Image fractal;
        fractal.create(
                clo.get_texture_size().x,
                clo.get_texture_size().y,
                colors_table[0]);

        generate_fractal(fractal, colors_table, clo.get_julia_cst());

        #ifndef DNDEBUG
        fractal.saveToFile("debug.png");
        #endif

        // Chargement de la texture
        sf::Texture texture;
        texture.loadFromImage(fractal);

        // Gestion de la fenêtre
        manage_window(window, texture);

    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
