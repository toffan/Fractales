#ifndef CLO_H_INCLUDED
#define CLO_H_INCLUDED

#include <stdexcept> //std::invalid_argument
#include <sstream> //std::stringstream

#include "maths.h"


class CLO{

public :

    enum class flag : std::uint32_t{
        JULIA_CST = 1,
        WINDOW_SIZE = 2,
        TEXTURE_SIZE = 4,
        PLAN_SIZE = 8,
        PLAN_CENTER = 16,
        HELP = 32};

    //Constructeur - Destructeur
    CLO(int argc, char **argv);
    ~CLO() {}

    // Getters
    bool flag(const std::uint32_t f) const {
        return (_options & f) != 0;
    }
    std::uint32_t get_options() const {
        return _options;
    }
    std::complex<calc_t> get_julia_cst() const {
        return _julia_cst;
    }
    Vect2<std::size_t> get_window_size() const {
        return _window_size;
    }
    Vect2<std::size_t> get_texture_size() const {
        return _texture_size;
    }
    Vect2<calc_t> get_plan_size() const {
        return _plan_size;
    }
    Vect2<calc_t> get_plan_center() const {
        return _plan_center;
    }

    static const std::complex<calc_t> JULIA_CST_DEF(-0.8, 0.2);
    static const Vect2<std::size_t> WINDOW_SIZE_DEF{1280, 720};
    static const Vect2<std::size_t> TEXTURE_SIZE_DEF{2560, 1440};
    static const Vect2<calc_t> PLAN_SIZE_DEF{2.4, 2.4};
    static const Vect2<calc_t> PLAN_CENTER_DEF{0, 0};

protected :

    //Attributs
    std::uint32_t _options;
    std::complex<calc_t> _julia_cst;
    Vect2<std::size_t> _window_size;
    Vect2<std::size_t> _texture_size;
    Vect2<calc_t> _plan_size;
    Vect2<calc_t> _plan_center;

    template <class T>
    static Vect2<T> str_to_vect(const std::string &str) {
        std::size_t delim{str.find_first_of(",;")};
        std::stringstream xss, yss;
        xss.str(pair.substr(0, delim));
        yss.str(pair.substr(delim + 1));

        Vect2<T> result;
        xss >> result.x;
        yss >> result.y;
        return result;
};

#endif // CLO_H_INCLUDED
