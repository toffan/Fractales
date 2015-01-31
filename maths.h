#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#include <complex>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "vect2.h"

#define JULIA_CSTE_REAL -0.8
#define JULIA_CSTE_IMAG 0.2

typedef double calc_t;

std::size_t algo_color(std::complex<calc_t> z, std::size_t color_max);

std::complex<calc_t> affixe_rel(
        Vect2<calc_t> pix_pos,
        Vect2<calc_t> win_pix_size,
        Vect2<calc_t> win_math_size);

void generate_fractal(
        sf::Image &fractal,
        const std::vector<sf::Color> &colors_table);

#endif // MATHS_H_INCLUDED
