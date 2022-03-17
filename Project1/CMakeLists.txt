cmake_minimum_required(VERSION 3.21)
project(IJC C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -pedantic -Wall -lm -Wextra")


add_executable(IJC bitset.c bitset.h Eratosthenes.c Eratosthenes.h primes.c error.h error.c)
add_executable(ppm ppm.h ppm.c error.h error.c steg-decode.c Eratosthenes.h Eratosthenes.c)
