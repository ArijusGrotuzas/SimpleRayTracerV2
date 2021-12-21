#ifndef RAY_H
#define RAY_H
#include <vector3.h>
#include <color.h>

class ray
{
    public:
        vector3 origin, direction;

        ray(){
            origin = vector3();
            direction = vector3();
        }

        ray(vector3 origin, vector3 direction){
            this->origin = origin;

            direction.normalize();
            this->direction = direction;
        }

        inline vector3 intersectionPoint();

        inline bool sphereIntersection(const vector3& center, float radius);
};

inline vector3 ray::intersectionPoint(){
    float t = 0.5 * (direction.y + 1.0);
    return (1.0 - t) * vector3(1.0, 1.0, 1.0) + t * vector3(0.5, 0.7, 1.0);
};

inline bool ray::sphereIntersection(const vector3& center, float radius){
    vector3 dirToSphere = origin - center;
    float b = 2.0 * dot(dirToSphere, direction);
    float c = dirToSphere.magnitude() * dirToSphere.magnitude() - radius * radius;
    float discriminant = b*b - 4*c;
    return (discriminant > 0);
}

#endif // RAY_H
