cmake_minimum_required(VERSION 3.1.0)
project (poker)

file(GLOB SRC
    "main.cpp"
    "libdivide/*.h"
    "libdivide/*.cpp"
    "omp/*.h"
    "omp/*.cpp"
)

add_executable(main ${SRC})

set(CMAKE_BUILD_TYPE Release)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(main PRIVATE Threads::Threads)

