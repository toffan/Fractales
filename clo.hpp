#ifndef CLO_H_INCLUDED
#define CLO_H_INCLUDED

#include <SFML/System/Vector2.hpp> //sf::Vector2
#include <sstream> //std::stringstream
#include <complex> //std::complex

using calc_t = double;

class CLO{

public:

    //Constructeur
    CLO(int argc, char **argv);

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


    template <class T>
    static sf::Vector2<T> str_to_vect(const std::string &pair) {
        sf::Vector2<T> result;
        std::size_t delim{pair.find_first_of(",;")};
        std::stringstream ss;
        
        ss.str(pair.substr(0, delim));
        ss >> result.x;

        ss.clear();
        ss.str(pair.substr(delim + 1));
        ss >> result.y;

        return result;
    }
};

#endif // CLO_H_INCLUDED
