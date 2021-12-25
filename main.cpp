#include <iostream>
#include <bits/stdc++.h>
#include <ray.h>

// A tuple structure for storing three variables
struct tuple2{
    int x;
    int y;
    int z = 0;
};

inline float sphereIntersection(const vector3& center, float radius, const ray& r){
    vector3 dirToSphere = r.origin - center;

    float b = 2.0 * dot(dirToSphere, r.direction);
    float c = dirToSphere.magnitude() * dirToSphere.magnitude() - radius * radius;
    float discriminant = b*b - 4*c;

    if (discriminant < 0.0){
        return -1.0;
    }
    else{
        float x1 = (-b + sqrt(discriminant)) / 2;
        float x2 = (-b - sqrt(discriminant)) / 2;

        if (x1 > 0 && x2 > 0){
            return std::min(x1, x2);
        }
    }
}

inline color render(const vector3& center, float radius, const ray& r){
    float t = sphereIntersection(center, radius, r);

    if (t > 0.0){
        vector3 intersection = r.origin + (r.direction * t);
        vector3 normal = (intersection - center);
        normal.normalize();
        return color(int(255.99* 0.5 * (normal.x + 1)), int(255.99 * 0.5 * (normal.y + 1)), int(255.99 * 0.5 * (normal.z + 1)));
    }

    t = 0.5 * (r.direction.y + 1.0);
    vector3 temp = (1.0 - t) * vector3(0.5, 0.7, 1.0) + t * vector3(1.0, 1.0, 1.0);

    return color(int(255.99 * temp.x), int(255.9 * temp.y), int(255.9 * temp.z));
};

int main(int argc, char** argv[])
{

    // Create a ppm file into which we can write
    std::fstream file;
    file.open("image.ppm", std::ios::out);

    // Check if file was created successfully
    if(!file)
    {
        std::cout << "Error, creating a file...";
        return 0;
    }

    std::cout << "Enter resolution for the screen in X and Y: \n";

    int x, y;

    std::cin >> x >> y;

    // Create a tuple that stores the resolution of an image
    tuple2 resolution = {x, y};

    // P3 means colors are in ASCII, then number of columns and rows, and max color value e.g. image precision
    file << "P3\n" << resolution.x << " " << resolution.y << "\n255\n";

    for (int j = 0; j < resolution.y; j++)
    {
        for (int i = 0; i < resolution.x; i++)
        {
            float u = float(i) / float(resolution.x) * 2 - 1;
            float v = float(j) / float(resolution.y) * 2 - 1;

            ray r(vector3(0,0,0), vector3(u, v, -1.0) - vector3(0, 0, 0));

            color col = render(vector3(0.0, 0.0, -3.0), 1.5, r);

            file << col;
        }
    }

    file.close();

    return 0;
}
