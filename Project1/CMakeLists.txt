cmake_minimum_required(VERSION 3.21)
project(IJC C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm -Wall -Wextra -pedantic")


add_executable(IJC bit_set.c bit_set.h Eratosthenes.c Eratosthenes.h primes.c ppm.h ppm.c)
add_executable(ppm ppm.h ppm.c error.h error.c steg-decode.c Eratosthenes.h Eratosthenes.c)
