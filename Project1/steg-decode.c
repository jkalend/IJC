// steg-decode.c
// Řešení IJC-DU1, příklad b), 17.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include "Eratosthenes.h"
#include "bitset.h"
#include "error.h"
#include "ppm.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		warning_msg("Neplatne argumenty\n");
		return 1;
	}
	struct ppm *PPM = ppm_read(argv[1]);
	if (PPM == NULL) {
		error_exit("fail\n");
	}
	bitset_alloc(numbers, PPM->xsize * PPM->ysize * 3) Eratosthenes(numbers);

	char out[2] = { CHAR_BIT, 0 }; //struktura pole pro potreby setbitu a getbitu
	int char_index = 0;
	int done = 0;

	for (unsigned int i = 29; i < PPM->xsize * PPM->ysize * 3; i++) {
		if (!(bitset_getbit(numbers, i))) {
			unsigned long bit = bitset_getbit((&(PPM->data[i])), 0);
			bitset_setbit(out, char_index, bit);
			char_index++;
		}
		if (char_index >= 8) {
			if (out[1] == '\0') {
				printf("\n");
				done = 1;
				break;
			}
			printf("%c", out[1]);
			char_index = 0;
			out[1] = 0;
		}
	}

	ppm_free(PPM);
	bitset_free(numbers);
	if (!done) {
		error_exit("Zprava nenalezena\n");
	} else {
		return EXIT_SUCCESS;
	}
}
