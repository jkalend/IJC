//
// Created by kalen on 2022-03-11.
//


#include <math.h>
#include "bit_set.h"
#include "Eratosthenes.h"

void Eratosthenes(bitset_t pole) {
    unsigned long max = sqrt(bitset_size(pole));

    bitset_setbit(pole, 0, 1)
    bitset_setbit(pole, 1, 1)

    for (unsigned long i = 2; i <= max; i++) {
        if (!bitset_getbit(pole, i)) {
            for (unsigned long j = i*i; j < bitset_size(pole); j += i) {
                bitset_setbit(pole, j, 1)
            }
        }
    }

}