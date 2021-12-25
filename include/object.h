#ifndef OBJECT_H
#define OBJECT_H

#include <ray.h>

struct record {
    float t;
    vector3 position;
    vector3 normal;
};

class object
{
    public:
        virtual bool hit(const ray& r, float t_min, float t_max, record &rec) const = 0;
};

#endif // OBJECT_H
