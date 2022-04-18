// htab_clear.c
// Řešení IJC-DU2, příklad 2), 15.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

void htab_clear(htab_t *t) {
	// empty table
	if (t == NULL) {
		return;
	}

	htab_listitem_t *item;
	for (size_t i = 0; i < t->arr_size; i++) {
		item = t->list[i];
		while (item != NULL) {
			htab_listitem_t *tmp = item;
			item = item->next;
			if (tmp->data->key != NULL) {
				free((char *)tmp->data->key);
			}
			free(tmp->data);
			free(tmp);
		}
		t->list[i] = NULL;
	}
	free(t->list);

	// reset size
	t->size = 0;
}
