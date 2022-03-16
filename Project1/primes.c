//
// Created by kalen on 2022-03-11.
//

#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "Eratosthenes.h"


//TODO zvetsit + pridat cas + dodelat error + makefile
//TODO cist zadani znovu
//TODO static assert for array size
#define N 300000000
//300000000
int main () {
    bitset_create(pole, N)
    clock_t start;
    int ord = 0;
    unsigned long out[10] = {0};

    start = clock();
    Eratosthenes(pole);

    for (unsigned long i = 299999999; i > 0; --i) { //299999999
        if (bitset_getbit(pole, i) == 0) {
            out[ord] = i;
            ord++;
        }
        if (ord == 10) {
            break;
        }
    }
    for (int i = 9; i >= 0; --i) {
        printf("%lu\n", out[i]);
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);

}
