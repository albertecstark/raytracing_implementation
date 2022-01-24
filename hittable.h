//
// Created by albert on 24/01/2022.
//

#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record{
    point3 p;
    vec3 normal;
    double t;
    bool front_face;
    // Imma be honest, i have no idea what any of this code does
    // TODO: learn what this code does!!
    inline void set_face_normal(const ray& r, const vec3& outward_normal){
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal :-outward_normal;
    }
};

class hittable{
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif //HITTABLE_H
