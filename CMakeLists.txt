cmake_minimum_required(VERSION 3.21)
project(rt_implement)

set(CMAKE_CXX_STANDARD 20)

add_executable(rt_implement main.cpp ray.h hittable.h sphere.h hittable_list.h rt_implement.h)
