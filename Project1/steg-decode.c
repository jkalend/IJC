//
// Created by kalen on 2022-03-14.
//

#include "ppm.h"
#include "error.h"
#include "bit_set.h"
#include "Eratosthenes.h"

int main (int argc, char **argv) {
    if (argc != 2) {
        warning_msg("Neplatne argumenty\n");
        return 1;
    }
    struct ppm *PPM = ppm_read(argv[1]);
    if (PPM == NULL) {
        error_exit("fail\n");
    }
    bitset_alloc(pole,PPM->xsize*PPM->ysize*3)
    Eratosthenes(pole);

    bitset_create(out, CHAR_BIT)
    //char output[1] = {0};
    int j = 0;
    int done = 0;
    char *data = PPM->data;

    for (unsigned int i = 29; i < PPM->xsize*PPM->ysize*3; i++) {
        if (bitset_getbit(pole, i) == 0) {
            unsigned long bit = bitset_getbit((&(data[i])), 0);
            bitset_setbit(out, j, bit);
            j++;
        }
        if (j >= 8) {
            if (out[1] == '\0'){
                putchar('\n');
                //printf("\n");
                done = 1;
                break;
            }
            putchar(out[1]);
            //printf("%c",output[0]);
            j = 0;
            out[1] = 0;
        }
    }

    ppm_free(PPM);
    bitset_free(pole);
    if (!done) {
        error_exit("Zprava nenalezena\n");
    } else {
        return EXIT_SUCCESS;
    }

}
