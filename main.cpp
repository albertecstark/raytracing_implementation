#include "rt_implement.h"

color ray_color(const ray& r, const hittable& world, int depth) {
    hit_record rec;

    // If exceed ray bounce limit, stop gathering light
    if (depth <= 0)
        return color(0,0,0);

    if (world.hit(r, 0.00001, infinity, rec)){
        point3 target = rec.p + rec.normal + random_in_hemisphere(rec.normal);
        return 0.5 * ray_color(ray(rec.p, target - rec.p), world, depth -1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t) * color(1.0, 1.0, 1.0) + t*color(0.5,0.7,1.0);
}

int main() {
// std::pair mode = get_mode();

#pragma region file_handling
    std::time_t image_gen_time_start = std::time(0);
    std::string start_time = std::to_string(image_gen_time_start);
    std::string main_file_name = "test_at_" + start_time + ".ppm";
    //std::string normals_file_name = "normals_of_test_at_" + start_time + ".ppm";
#pragma endregion

#pragma region image_parameters
    const auto aspect_ratio = 16.0 / 9.0;
    const int width = 1600;
    const int height = width / aspect_ratio;
    const int samples_per_pixel = 100; //std::get<0>(mode);
    const int max_depth = 50; //std::get<1>(mode);
#pragma endregion

#pragma region world
hittable_list world;
world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));
#pragma endregion

#pragma region camera
    camera cam;
#pragma endregion

#pragma region render
    std::ofstream image_file(main_file_name);
    image_file<<"P3\n"<<width<<' '<<height<<"\n255\n";
    for(int j = height - 1; j >= 0; --j){
        std::cerr<<j<<" lines left\n"<< std::flush;
        for(int i = 0; i < width; ++i){
           color pixel_color(0,0,0);
           for(int s = 0; s < samples_per_pixel; ++s){
               auto u = (i + random_double()) / (width - 1);
               auto v = (j + random_double()) / (height - 1);
               ray r = cam.get_ray(u, v);
               pixel_color += ray_color(r, world, max_depth);
           }
            write_color(image_file, pixel_color, samples_per_pixel);
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