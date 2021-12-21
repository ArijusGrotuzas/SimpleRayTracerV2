#ifndef VECTOR3_H
#define VECTOR3_H
#include <math.h>
#include <stdlib.h>
#include <iostream>

class vector3{
public:
    float x, y, z;

    // Default constructor
    vector3() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }

    // Parameterized constructor
    vector3(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    inline float magnitude() const {
        return sqrt(x*x + y*y + z*z);
    }

    inline void normalize();
};

inline void vector3::normalize(){
    float k = 1 / magnitude();
    x *= k; y *= k; z *= k;
}

/*                  Dot and Cross products                  */

inline float dot(const vector3 &v1, const vector3 &v2){
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline vector3 cross(const vector3& v1, const vector3& v2){
    return vector3((v1.y * v2.z - v1.z * v2.y), (v1.z * v2.x - v1.x * v2.z), (v1.x * v2.y - v1.y * v2.x));
}

/*                  Component-wise operations               */

// Component-wise addition
inline vector3 operator+(const vector3& v1, const vector3& v2){
        return vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

// Component-wise subtraction
inline vector3 operator-(const vector3& v1, const vector3& v2){
        return vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

// Component-wise multiplication
inline vector3 operator*(const vector3& v1, const vector3& v2){
        return vector3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

// Component-wise division
inline vector3 operator/(const vector3& v1, const vector3& v2){
        return vector3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

/*                      Scalar operations                   */

// Scalar addition
inline vector3 operator+(const vector3& v, float a){
        return vector3(v.x + a, v.y + a, v.z + a);
}

// Scalar subtraction
inline vector3 operator-(const vector3& v, float a){
        return vector3(v.x - a, v.y - a, v.z - a);
}

// Scalar multiplication
inline vector3 operator*(const vector3& v, float a){
        return vector3(v.x * a, v.y * a, v.z * a);
}

inline vector3 operator*(float a, const vector3& v){
        return vector3(v.x * a, v.y * a, v.z * a);
}

// Scalar division
inline vector3 operator/(const vector3& v, float a){
        return vector3(v.x / a, v.y / a, v.z / a);
}

inline std::istream& operator>>(std::istream& is, vector3 &v){
    is >> v.x >> v.y >> v.z;
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const vector3 &v){
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}


#endif // VECTOR3_H
