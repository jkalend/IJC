// primes.c
// Řešení IJC-DU1, příklad a), 16.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2
// potreba ulimit -s 40000

#include <stdio.h>
#include <time.h>
#include "bitset.h"
#include "Eratosthenes.h"

#define SIZE 300000000

int main()
{
	bitset_create(pole, SIZE) clock_t start;
	int order = 0;
	unsigned long out[10] = { 0 };

	start = clock();
	Eratosthenes(pole);

	for (unsigned long i = SIZE - 1; i > 0; --i) {
		if (bitset_getbit(pole, i) == 0) {
			out[order] = i;
			order++;
		}
		if (order == 10) {
			break;
		}
	}

	//pro tisk poslednich 10 cisel naopak
	for (int i = 9; i >= 0; --i) {
		printf("%lu\n", out[i]);
	}
	fprintf(stderr, "Time=%.3g\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
