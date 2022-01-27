//
// Created by albert on 24/01/2022.
//

#ifndef RT_IMPLEMENT_H
#define RT_IMPLEMENT_H

#include <iostream>// writing to file
#include <ctime>// file handling + performance monitoring
#include <fstream>// file handling
#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

// ignore this, will get this running eventually
#pragma region render_mode
/*
std::pair<int, int> get_mode() {
    std::pair<int, int> mode ;
    int samples = 0;
    int depth = 0;
    std::string response;
    std::cin >> response;
    std::cout<<"what mode do you want the program to run in?\n" <<"enter\n"<<" 'quickie' - 20 samples\n"
             <<" 'test - 40 samples\n"
             <<" 'release' - 200 samples, max_depth of 50";
    if (response == "quickie"){
        samples = 20;
        depth = 5;
    } else if (response == "test") {
        samples = 40;
        depth = 10;
    } else if (response == "release"){
        samples = 200;
        depth = 50;
    } else {
        std::cout << "please input a valid configuration";
        get_mode();
    }
    mode = std::make_pair(samples, depth);
    return mode;
}
*/
#pragma endregion

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees){
    return degrees * pi / 180;
}

inline double random_double(){
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max){
    return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max){
    if (x<min) return min;
    if (x>max) return max;
    return x;
}

#include "ray.h"
#include "vec3.h"

#endif //RT_IMPLEMENT_H
