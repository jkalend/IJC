// htab_resize.c
// Řešení IJC-DU2, příklad 2), 17.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>
#include <stdio.h>


void htab_resize(htab_t *t, size_t size) {
	//temporal table to hold content of the old table
	htab_t *tmp = htab_init(t->arr_size);
	if (tmp == NULL) {
		exit(EXIT_FAILURE);
	}

	//copy content of the old table to the temporal table
	//and clear the old table
	for (unsigned int i = 0; i < t->arr_size; i++) {
		htab_listitem_t *item = t->list[i];
		if (item != NULL) {
			tmp->list[i] = item;
		}
		t->list[i] = NULL;
	}
	free(t->list);

	//resize the old table
	t->list = malloc(size * sizeof(htab_listitem_t *));
	if (t->list == NULL) {
		fprintf(stderr, "Allocation failed\n");
		exit(EXIT_FAILURE);
	}
	t->arr_size = size;
	t->size = 0;
	for (size_t i = 0; i < size; i++) {
		t->list[i] = NULL;
	}

	//rehash the content of the temporal table to the new table
	for (unsigned int i = 0; i < tmp->arr_size; i++) {
		htab_listitem_t *item = tmp->list[i];
		while (item != NULL) {
			htab_pair_t *check = htab_lookup_add(t, item->data->key);
			if (check == NULL) {
				fprintf(stderr, "Allocation failed\n");
				exit(EXIT_FAILURE);
			}
			check->value = item->data->value;
			item = item->next;
		}
	}

	//free the temporal table
	htab_free(tmp);
}
