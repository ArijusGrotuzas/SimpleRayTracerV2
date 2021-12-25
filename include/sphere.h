#ifndef SPHERE_H
#define SPHERE_H

#include <object.h>

class sphere: public object {
    public:
        vector3 center;
        float radius;

        sphere(){}
        sphere (vector3 center, float radius){
            this->center = center;
            this->radius = radius;
        }

        virtual bool hit(const ray &r, float t_min, float t_max, record &rec) const;

};

bool sphere::hit (const ray &r, float t_min, float t_max, record &rec){
    return false;
}

#endif // SPHERE_H
