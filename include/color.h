#ifndef COLOR_H
#define COLOR_H
#include <stdlib.h>
#include <iostream>

class color
{
    public:
        int r, g, b, a;

        color(){}

        color(int r, int g, int b){
            this->r = r;
            this->g = g;
            this->b = b;
            a = 255;
        }

        color(int r, int g, int b, int a){
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }

    private:
};

/*
inline color operator*(const color& c, int a){
    return color(c.r * a, c.g * a, c.b * a);
}
*/

inline std::istream& operator>>(std::istream& is, color &c){
    is >> c.r >> c.g >> c.b;
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const color &c){
    os << c.r << " " << c.g << " " << c.b << "\n";
    return os;
}

#endif // COLOR_H
