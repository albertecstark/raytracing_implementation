//
// Created by albert on 24/01/2022.
//

#ifndef RT_IMPLEMENT_H
#define RT_IMPLEMENT_H

#include <cmath>
#include <limits>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees){
    return degrees * pi / 180;
}

#include "ray.h"
#include "vec3.h"

#endif //RT_IMPLEMENT_H