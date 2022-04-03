// Eratosthenes.c
// Řešení IJC-DU1, příklad a), 16.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2
// stredniky za setbit jsou nutne pro inline

#include "Eratosthenes.h"
#include "bitset.h"
#include <math.h>
#include <string.h>

void Eratosthenes(bitset_t pole)
{
	unsigned long max = sqrt(bitset_size(pole));

	//nastavi 2 a nasobky 2 jako 1, tedy neprvocisla
	memset(pole + 1, 0x55,
		   (bitset_size(pole) / CHAR_BIT + ((bitset_size(pole) % CHAR_BIT) ? 1 : 0)));

	bitset_setbit(pole, 0, 1);
	bitset_setbit(pole, 1, 1);
	bitset_setbit(pole, 2, 0); //side-effect memsetu

	for (unsigned long i = 3; i <= max; i++) {
		if (!(bitset_getbit(pole, i))) {
			for (unsigned long j = i * i; j < bitset_size(pole); j += 2 * i) {
				bitset_setbit(pole, j, 1);
			}
		}
	}
}
