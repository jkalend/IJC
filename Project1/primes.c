//
// Created by kalen on 2022-03-11.
//

#include <stdio.h>
#include <stdlib.h>
#include "bit_set.h"
#include "Eratosthenes.h"


//TODO zvetsit + pridat cas + dodelat error + makefile
//TODO cist zadani znovu
#define N 100

int main () {
    bitset_create(pole, N)
    unsigned long out[100] = {0};

    int ord = 0;
    Eratosthenes(pole);

    for (unsigned long i = 0; i < N; ++i) {
        if (bitset_getbit(pole, i) == 0) {
            out[ord] = i;
            ord++;
        }
        if (ord == 100)
            break;
    }
    for (unsigned long i = 0; i < N; ++i) {
        if (out[i] != 0)
            printf("%lu\n", out[i]);
    }

}
