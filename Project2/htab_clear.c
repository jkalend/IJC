//
// Created by kalen on 14.04.22.
//
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
			free(tmp);
		}
	}
	free(t->list);

	// reset all values
	t->arr_size = 0;
	t->size = 0;
	t->list = NULL;
}
