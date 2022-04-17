cmake_minimum_required(VERSION 3.21)
project(IJC C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -pedantic -Wall -lm -Wextra")


add_executable(IJC Project1/bitset.c Project1/bitset.h Project1/primes.c Project1/error.h Project1/error.c Project1/Eratosthenes.h Project1/Eratosthenes.c)
add_executable(ppm Project1/ppm.h Project1/ppm.c Project1/error.h Project1/error.c Project1/steg-decode.c Project1/Eratosthenes.h Project1/Eratosthenes.c)
add_executable(tail Project2/tail.c)
add_executable(hash Project2/htab_private.h Project2/htab.h Project2/htab_hash_function.c Project2/htab_init.c Project2/htab_bucket_count.c Project2/htab_size.c Project2/htab_resize.c Project2/htab_for_each.c Project2/htab_clear.c Project2/htab_free.c Project2/htab_find.c Project2/htab_erase.c Project2/htab_lookup_add.c Project2/main.c Project2/io.c Project2/io.h)