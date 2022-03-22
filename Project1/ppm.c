// ppm.c
// Řešení IJC-DU1, příklad b), 16.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2
// limit pole nastaven na 8000 * 8000 * 3

#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"

struct ppm* ppm_read(const char* filename) {
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        warning_msg("%s nelze otevrit\n", filename);
        return NULL;
    }

    struct ppm* PPM = malloc(sizeof(struct ppm));
    if (PPM == NULL) {
        fclose(fp);
        error_exit("Alokace selhala\n");
    }

    char format[3]; // P + 6 + \0
    fgets(format, sizeof(format), fp);
    if (format[0] != 'P' && format[1] != '6') {
        fclose(fp);
        ppm_free(PPM);
        warning_msg("Soubor %s ma neplatny format\n", filename);
        return NULL;
    }

    unsigned int bitrate;
    int args = fscanf(fp, "%u %u %u", &PPM->xsize, &PPM->ysize, &bitrate);
    if (args != 3 || bitrate != 255) {
        fclose(fp);
        ppm_free(PPM);
        warning_msg("Soubor %s ma neplatny format\n", filename);
        return NULL;
    }

    if (PPM->xsize * PPM->ysize * 3 > MAX_SIZE) {
        warning_msg("Rozliseni obrazku je prilis velke\n");
        fclose(fp);
        ppm_free(PPM);
        return NULL;
    }

    PPM->data = malloc(3 * PPM->xsize * PPM->ysize);

    if (PPM->data == NULL) {
        ppm_free(PPM);
        fclose(fp);
        error_exit("Alokace selhala\n");
    }


    if (fread(PPM->data, sizeof(char), (3* PPM->xsize * PPM->ysize), fp) != (3* PPM->xsize * PPM->ysize)) {
        warning_msg("Chyba pri cteni souboru %s\n", filename);
        ppm_free(PPM);
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    return PPM;
}

void ppm_free(struct ppm *p) {
    if (p->data != NULL)
        free(p->data);
    free(p);
}
