#include <stdexcept> //std::invalid_argument

#include "clo.hpp"


const sf::Vector2<std::size_t> CLO::WINDOW_SIZE_DEF{1280, 720};
const sf::Vector2<std::size_t> CLO::TEXTURE_SIZE_DEF{2560, 1440};
const sf::Vector2<calc_t> CLO::PLAN_SIZE_DEF{2.4, 2.4};
const sf::Vector2<calc_t> CLO::PLAN_CENTER_DEF{0, 0};

CLO::CLO(int argc, char **argv):
    _options{0},
    _julia_cst{JULIA_CST_DEF},
    _window_size{WINDOW_SIZE_DEF},
    _texture_size{TEXTURE_SIZE_DEF},
    _plan_size{PLAN_SIZE_DEF},
    _plan_center{PLAN_CENTER_DEF} {
    std::string option;

    for(char **it{argv + 1}; it < argv + argc; ++it) {
        option = *it;

        //JULIA_CST
        if(option == "-j") {
            _julia_cst = parse_option<std::complex<calc_t>>(
                    it, JULIA_CST, _options);
        }
        //WINDOW_SIZE 
        else if(option == "-w") {
            _window_size = parse_option<sf::Vector2<std::size_t>>(
                    it, WINDOW_SIZE, _options);
        }
        //TEXTURE_SIZE 
        else if(option == "-t") {
            _texture_size = parse_option<sf::Vector2<std::size_t>>(
                    it, TEXTURE_SIZE, _options);
        }
        //PLAN_SIZE 
        else if(option == "-p") {
            _plan_size = parse_option<sf::Vector2<calc_t>>(
                    it, PLAN_SIZE, _options);
        }
        //PLAN_CENTER 
        else if(option == "-c") {
            _plan_center = parse_option<sf::Vector2<calc_t>>(
                    it, PLAN_CENTER, _options);
        }
        //HELP
        // L'aide n'est pas implémentée pour l'instant
        else if(option == "-h") {
            _options |= HELP;
        }

        //OTHERS
        else {
            throw std::invalid_argument(
                    "Error CLO: unkown option " + option);
        }
    }
}

