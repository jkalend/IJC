// ppm.h
// Řešení IJC-DU1, příklad b), 16.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2
// limit pole nastaven na 8000 * 8000 * 3

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

#ifndef IJC_PPM_H
#define IJC_PPM_H

#define MAX_SIZE 8000*8000*3

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char *data;    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

#endif //IJC_PPM_H
