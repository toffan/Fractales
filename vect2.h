#ifndef VECT2_H_INCLUDED
#define VECT2_H_INCLUDED

#include <iostream>
#include <SFML/System/Vector2.hpp>


template <class T>
class Vect2
{
public :
    // Attributs
    T x, y;

    // Constructeurs - Destructeurs
    Vect2<T>(T x1 = 0, T y1 = 0):
        x{x1}, y{y1} {}
    template<class U>
    Vect2<T>(U x1, U y1):
        x{static_cast<T>(x1)},
        y{static_cast<T>(y1)} {}
    Vect2<T>(sf::Vector2<T> v):
        x{v.x}, y{v.y} {}
    template <class U>
    Vect2<T>(sf::Vector2<U> v):
        x{static_cast<T>(v.x)},
        y{static_cast<T>(v.y)} {}

    ~Vect2<T>(){}

    // Methodes arithmetiques
    Vect2<T>& operator+=(const Vect2<T> v){
        x += v.x; y += v.y;
        return *this;
    }
    Vect2<T>& operator-=(const Vect2<T> v){
        x -= v.x; y -= v.y;
        return *this;
    }
    Vect2<T>& operator*=(const T a){
        x *= a; y *= a;
        return *this;
    }
    Vect2<T>& operator/=(const T a){
        x /= a; y /= a;
        return *this;
    }
    Vect2<T>& operator=(const Vect2<T> v){
        x = v.x; y = v.y;
        return *this;
    }

    T norme2() const{
        return x*x + y*y;
    }
    Vect2<T> proj(const Vect2<T> p) const{
        return ((*this * p)/p.norme2()) * p;
    }
    sf::Vector2<T> to_sf() const{
        return sf::Vector2<T>(x, y);
    }
};

template <class T>
Vect2<T> operator-(Vect2<T> u) {
    u.x = -u.x; u.y = -u.y;
    return u;
}
template <class T>
Vect2<T> operator+(Vect2<T> u, const Vect2<T> &v) {
    return u += v;
}
template <class T>
Vect2<T> operator-(Vect2<T> u, const Vect2<T> &v) {
    return u -= v;
}
template <class T>
Vect2<T> operator*(Vect2<T> u, const T a) {
    return u *= a;
}
template <class T>
Vect2<T> operator*(const T a, Vect2<T> u) {
    return u *= a;
}
template <class T>
Vect2<T> operator/(Vect2<T> u, const T a) {
    return u /= a;
}
template <class T>
T operator*(const Vect2<T> &u, const Vect2<T> &v) {
    return u.x * v.x + u.y * v.y;
}
template <class T>
T distance2(Vect2<T> u, const Vect2<T> &v) {
    return (u -= v).norme2();
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Vect2<T> &u) {
    os << '(' << u.x << ',' << ' ' << u.y << ')';
    return os;
}

#endif
