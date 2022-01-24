#include "rt_implement.h"

#include "color.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>// writing to file
#include <ctime>// file handling + performance monitoring
#include <fstream>// file handling

color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)){
        return 0.5 * (rec.normal + color(1,1,1));
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t) * color(1.0, 1.0, 1.0) + t*color(0.5,0.7,1.0);
}

int main() {
#pragma region file_handling
    std::time_t image_gen_time_start = std::time(0);
    std::string file_name = std::to_string(image_gen_time_start);
    file_name = "test_at_" + file_name + ".ppm";
#pragma endregion

#pragma region image_parameters
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 1600;
    const int height = width / aspect_ratio;
#pragma endregion

#pragma region world
hittable_list world;
world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));
#pragma endregion

#pragma region camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0,0,0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);
#pragma endregion

#pragma region render
    std::ofstream image_file(file_name);
    image_file<<"P3\n"<<width<<' '<<height<<"\n255\n";
    for(int j = height - 1; j >= 0; --j){
        std::cerr<<j<<" lines left\n"<< std::flush;
        for(int i = 0; i < width; ++i){
            auto u = double(i)/(width-1);
            auto v = double (j)/(height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r, world);
            write_color(image_file, pixel_color);
        }
    }
    std::cerr<<"\nDone!!\n";
    image_file.close();
#pragma endregion

#pragma region performance calculation
    std::time_t image_gen_time_end = std::time(0);
    int gen_time = image_gen_time_end - image_gen_time_start;
    std::cerr<<"Time for generation is " << gen_time << " seconds\n";
#pragma endregion
return 0;
}