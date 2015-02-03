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

    for(int i{1}; i < argc; ++i) {
        option = argv[i];

        //JULIA_CST
        if(option == "-j") {
            if(flag(JULIA_CST)) {
                throw std::invalid_argument(
                        "Error CLO: option -c found more than once.");
            }
            else if(i+1 < argc) {
                sf::Vector2<calc_t> c(str_to_vect<calc_t>(std::string(argv[++i])));
                _julia_cst.real(c.x);
                _julia_cst.imag(c.y);
            }
            else{
                throw std::invalid_argument(
                        "Error CLO: no value found for option -c.");
            }
            _options |= JULIA_CST;
        }

        //WINDOW_SIZE 
        else if(option == "-w") {
            if(flag(WINDOW_SIZE)) {
                throw std::invalid_argument(
                        "Error CLO: option -w found more than once.");
            }
            else if(i+1 < argc) {
                _window_size = str_to_vect<std::size_t>(std::string(argv[++i]));
            }
            else{
                throw std::invalid_argument(
                        "Error CLO: no value found for option -w.");
            }
            _options |= WINDOW_SIZE;
        }

        //TEXTURE_SIZE 
        else if(option == "-t") {
            if(flag(TEXTURE_SIZE)) {
                throw std::invalid_argument(
                        "Error CLO: option -t found more than once.");
            }
            else if(i+1 < argc) {
                _texture_size = str_to_vect<std::size_t>(std::string(argv[++i]));
            }
            else{
                throw std::invalid_argument(
                        "Error CLO: no value found for option -t.");
            }
            _options |= TEXTURE_SIZE;
        }

        //PLAN_SIZE 
        else if(option == "-p") {
            if(flag(PLAN_SIZE)) {
                throw std::invalid_argument(
                        "Error CLO: option -p found more than once.");
            }
            else if(i+1 < argc) {
                _plan_size = str_to_vect<calc_t>(std::string(argv[++i]));
            }
            else{
                throw std::invalid_argument(
                        "Error CLO: no value found for option -p.");
            }
            _options |= PLAN_SIZE;
        }

        //PLAN_CENTER 
        else if(option == "-c") {
            if(flag(PLAN_CENTER)) {
                throw std::invalid_argument(
                        "Error CLO: option -c found more than once.");
            }
            else if(i+1 < argc) {
                _plan_center = str_to_vect<calc_t>(std::string(argv[++i]));
            }
            else{
                throw std::invalid_argument(
                        "Error CLO: no value found for option -c.");
            }
            _options |= PLAN_CENTER;
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


