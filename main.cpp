#include <vector> //std:vector
#include <iostream> //std::cerr

#include <SFML/Graphics/Image.hpp> //sf::Image
#include <SFML/Graphics/Texture.hpp> //sf::Texture
#include <SFML/Graphics/RenderWindow.hpp> //sf::RenderWindow, sf::VideoMode

#include "maths.hpp"
#include "clo.hpp"
#include "window.hpp"


const std::string WINDOW_TITLE{"Fractale de Julia"};
constexpr std::size_t NB_COLORS{256};


int main(int argc, char **argv) {
    try {
        // Définitions les couleurs
        std::vector<sf::Color> colors_table(create_colors(NB_COLORS));

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


