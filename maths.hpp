#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#include <complex> //std::complex

#include <SFML/Graphics/Image.hpp> //sf::Image
#include <SFML/System/Vector2.hpp> //sf::Vector2

using calc_t = double;

std::size_t algo_color(
        std::complex<calc_t> z,
        const std::complex<calc_t> julia_cst,
        std::size_t color_max);

std::complex<calc_t> affixe_rel(
        sf::Vector2<calc_t> pix_pos,
        sf::Vector2<calc_t> win_pix_size,
        sf::Vector2<calc_t> win_math_size);

void generate_fractal(
        sf::Image &fractal,
        const std::vector<sf::Color> &colors_table,
        const std::complex<calc_t> jula_cst);


#endif // MATHS_H_INCLUDED
