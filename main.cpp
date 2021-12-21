#include <iostream>
#include <bits/stdc++.h>
#include <ray.h>

// A tuple structure for storing three variables
struct tuple{
    int x;
    int y;
    int z = 0;
};

int main()
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

    // Create a tuple that stores the resolution of an image
    tuple resolution = {1000, 1000};

    // P3 means colors are in ASCII, then number of columns and rows, and max color value e.g. image precision
    file << "P3\n" << resolution.x << " " << resolution.y << "\n255\n";

    // Color data-type for printing a color
    color col;

    for (int j = 0; j < resolution.y; j++)
    {
        for (int i = 0; i < resolution.x; i++)
        {
            float u = float(i) / float(resolution.x) * 2 - 1;
            float v = float(j) / float(resolution.y) * 2 - 1;

            ray r(vector3(0,0,0), origin - vector3(u, v, -1.0));
            vector3 point = r.intersectionPoint();

            bool hitSphere = r.sphereIntersection(vector3(0.0, 0.0, -3.0), 1.0);

            if (hitSphere){
                col.r = 255;
                col.g = 0;
                col.b = 0;
            }
            else{
                col.r = int(255.99*point.x);
                col.g = int(255.99*point.y);
                col.b = int(255.99*point.z);
            }

            file << col;
        }
    }

    file.close();

    return 0;
}
