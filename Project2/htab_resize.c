//
// Created by kalen on 11.04.22.
//

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>
#include <stdio.h>


void htab_resize(htab_t *t, size_t size) {
	htab_t *tmp = htab_init(t->arr_size);
	if (tmp == NULL) {
		exit(EXIT_FAILURE);
	}


	for (unsigned int i = 0; i < t->arr_size; i++) {
		htab_listitem_t *item = t->list[i];
		if (item != NULL) {
			tmp->list[i] = item;
		}
		t->list[i] = NULL;
	}

	htab_clear(t);
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


	for (unsigned int i = 0; i < tmp->arr_size; i++) {
		htab_listitem_t *item = tmp->list[i];
		while (item != NULL) {
			//returns pointer -> can be modified here
			htab_pair_t *check = htab_lookup_add(t, item->data->key);
			if (check == NULL) {
				fprintf(stderr, "Allocation failed\n");
				exit(EXIT_FAILURE);
			}
			check->value = item->data->value;
			item = item->next;
		}
	}

	htab_free(tmp);

}
