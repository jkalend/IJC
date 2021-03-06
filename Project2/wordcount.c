// main.c
// Řešení IJC-DU2, příklad 2), 16.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include "htab.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 200
#define STARTING_SIZE 150961

void print_data(htab_pair_t* pair) {
	printf("%s\t%d\n", pair->key, pair->value);
}

int main(void) {

	htab_t *htab = htab_init(STARTING_SIZE);
	if (htab == NULL) {
		goto exit_failure;
	}

	htab_pair_t *check;
	char *word = malloc(MAX_LENGTH * sizeof(char));
	if (word == NULL) {
		goto exit_failure;
	}
	while (read_word(word, MAX_LENGTH, stdin) != EOF) {
		if ((check = htab_find(htab, word)) == NULL) {
			check = htab_lookup_add(htab, word);
			if (check == NULL) {
				printf("Memory allocation failed.\n");
				free(word);
				goto exit_failure;
			}
		} else {
			check->value++;
		}
	}
	free(word);

	void (*print)(htab_pair_t *) = print_data;
	htab_for_each(htab, print);

	htab_free(htab);
	return EXIT_SUCCESS;

exit_failure:
	fprintf(stderr, "Memory allocation failed.\n");
	htab_free(htab);
	return EXIT_FAILURE;
}
