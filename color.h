//
// Created by albert on 17/01/2022.
//

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>
#include <cmath>

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    out << static_cast<int>(255.99 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(255.99 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(255.99 * clamp(b, 0.0, 0.999)) << "\n";
}

#endif //COLOR_H
