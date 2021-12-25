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
};


#endif // RAY_H
