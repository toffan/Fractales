#ifndef CLO_H_INCLUDED
#define CLO_H_INCLUDED

#include <sstream> //std::stringstream
#include <complex> //std::complex
#include <stdexcept> //std::invalid_argument

#include <SFML/System/Vector2.hpp> //sf::Vector2

using calc_t = double;
using namespace std::literals;


class CLO {

public:

    //Constructeur
    CLO();
    CLO(int argc, char **argv);

    void parse(int argc, char **argv);

    // Getters
    bool flag(const unsigned int f) const {
        return (_options & f) != 0;
    }
    unsigned int get_options() const {
        return _options;
    }
    std::complex<calc_t> get_julia_cst() const {
        return _julia_cst;
    }
    sf::Vector2<std::size_t> get_window_size() const {
        return _window_size;
    }
    sf::Vector2<std::size_t> get_texture_size() const {
        return _texture_size;
    }
    sf::Vector2<calc_t> get_plan_size() const {
        return _plan_size;
    }
    sf::Vector2<calc_t> get_plan_center() const {
        return _plan_center;
    }

    static constexpr unsigned int JULIA_CST{1};
    static constexpr unsigned int WINDOW_SIZE{2};
    static constexpr unsigned int TEXTURE_SIZE{4};
    static constexpr unsigned int PLAN_SIZE{8};
    static constexpr unsigned int PLAN_CENTER{16};
    static constexpr unsigned int HELP{32};

    static constexpr std::complex<calc_t> JULIA_CST_DEF{-0.8, 0.2};

    static const sf::Vector2<std::size_t> WINDOW_SIZE_DEF;
    static const sf::Vector2<std::size_t> TEXTURE_SIZE_DEF;
    static const sf::Vector2<calc_t> PLAN_SIZE_DEF;
    static const sf::Vector2<calc_t> PLAN_CENTER_DEF;
    
protected:

    //Attributs
    unsigned int _options;
    std::complex<calc_t> _julia_cst;
    sf::Vector2<std::size_t> _window_size;
    sf::Vector2<std::size_t> _texture_size;
    sf::Vector2<calc_t> _plan_size;
    sf::Vector2<calc_t> _plan_center;

    template<class T>
    static T parse_option(
            char **it,
            unsigned int f,
            unsigned int &options) {
        if((f & options) != 0) {
            throw std::invalid_argument(
                    "Error CLO: option "s + *it
                    + " found more than once."s);
        }
        else if(std::string(*(++it)) == "\0") {
            throw std::invalid_argument(
                    "Error CLO: no value found for option "s + *(--it) + "."s);
        }
        else {
            options |= f;

            T result;
            std::stringstream ss;
            ss.str(*it);
            ss >> result;
            return result;
        }
    }
};


template <class T>
std::istream& operator>>(std::istream &is, sf::Vector2<T>& vect) {
    char trash;
    is >> trash;
    if(trash != '(') {
        throw std::invalid_argument(
                "Error CLO: un vecteur doit être sous la forme (a,b).");
    }

    is >> vect.x >> trash;
    if(trash != ',') {
        throw std::invalid_argument(
                "Error CLO: un vecteur doit être sous la forme (a,b).");
    }
    is >> vect.y >> trash;

    if(trash != ')') {
        throw std::invalid_argument(
                "Error CLO: un vecteur doit être sous la forme (a,b).");
    }
    
    return is;
}

#endif // CLO_H_INCLUDED
