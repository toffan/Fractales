#include "maths.h"


std::size_t algo_color(
        std::complex<calc_t> z,
        const std::complex<calc_t> julia_cst,
        std::size_t color_max) {
    std::size_t color{0};

    while(color < color_max && norm(z) < 4){
        z = z * z + julia_cst;
        ++color;
    }

    return color;
}


std::complex<calc_t> affixe_rel(
        Vect2<calc_t> pix_pos,
        Vect2<calc_t> win_pix_size,
        Vect2<calc_t> win_math_size) {
    return {
            (pix_pos.x - win_pix_size.x/2) * win_math_size.x / win_pix_size.x,
            (win_pix_size.y/2 - pix_pos.y) * win_math_size.y / win_pix_size.y};
}


void generate_fractal(
        sf::Image &fractal,
        const std::vector<sf::Color> &colors_table,
        const std::complex<calc_t> julia_cst) {
    std::complex<calc_t> affixe;
    std::size_t color;
    for(std::size_t j(0) ; j!=fractal.getSize().y ; ++j){
        for(std::size_t i(0) ; i!=fractal.getSize().x ; ++i){
            affixe = affixe_rel(
                    Vect2<calc_t>(i,j),
                    Vect2<calc_t>(fractal.getSize()),
                    Vect2<calc_t>(2.4, 2.4));
            color = algo_color(affixe, julia_cst, colors_table.size()-1);
            fractal.setPixel(i, j, colors_table[color]);
        }
    }
}
