cmake_minimum_required(VERSION 3.21)

project(WebpConverter VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(libwebp)

add_library(WebpConverter SHARED
   converter.cpp
)
target_link_libraries(WebpConverter PRIVATE webp)