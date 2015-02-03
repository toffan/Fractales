#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#include <complex> //std::complex

#include <SFML/Graphics/Image.hpp> //sf::Image
#include <SFML/System/Vector2.hpp> //sf::Vector2


template<class T>
std::size_t algo_color(
        std::complex<T> z,
        const std::complex<T> julia_cst,
        std::size_t color_max);

template<class T>
std::complex<T> affixe_rel(
        sf::Vector2<T> pix_pos,
        sf::Vector2<T> win_pix_size,
        sf::Vector2<T> win_math_size);

template<class T>
void generate_fractal(
        sf::Image &fractal,
        const std::vector<sf::Color> &colors_table,
        const std::complex<T> jula_cst);



template<class T>
std::size_t algo_color(
        std::complex<T> z,
        const std::complex<T> julia_cst,
        std::size_t color_max) {
    std::size_t color{0};

    while(color < color_max && norm(z) < 4){
        z = z * z + julia_cst;
        ++color;
    }

    return color;
}


template<class T>
std::complex<T> affixe_rel(
        sf::Vector2<T> pix_pos,
        sf::Vector2<T> win_pix_size,
        sf::Vector2<T> win_math_size) {
    return {
            (pix_pos.x - win_pix_size.x/2) * win_math_size.x / win_pix_size.x,
            (win_pix_size.y/2 - pix_pos.y) * win_math_size.y / win_pix_size.y};
}


template<class T>
void generate_fractal(
        sf::Image &fractal,
        const std::vector<sf::Color> &colors_table,
        const std::complex<T> julia_cst) {
    std::complex<T> affixe;
    std::size_t color;
    for(std::size_t i(0) ; i!=fractal.getSize().x ; ++i){
        for(std::size_t j(0) ; j!=fractal.getSize().y ; ++j){
            affixe = affixe_rel(
                    sf::Vector2<T>(i,j),
                    sf::Vector2<T>(fractal.getSize()),
                    sf::Vector2<T>(2.4, 2.4));
            color = algo_color(affixe, julia_cst, colors_table.size()-1);
            fractal.setPixel(i, j, colors_table[color]);
        }
    }
}

#endif // MATHS_H_INCLUDED
