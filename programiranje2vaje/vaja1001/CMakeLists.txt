cmake_minimum_required(VERSION 3.21)
project(vaja1001)

set(CMAKE_CXX_STANDARD 14)

add_executable(vaja1001 main.cpp Date.cpp Date.h Gallery.cpp Gallery.h Artwork.cpp Artwork.h Sculpture.cpp Sculpture.h Painting.cpp Painting.h Artist.cpp Artist.h PrintIfPainting.cpp PrintIfPainting.h)
