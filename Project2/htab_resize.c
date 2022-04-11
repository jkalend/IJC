//
// Created by kalen on 11.04.22.
//

#include "htab.h"
#include "htab_private.h"

void htab_resize(htab_t *t, size_t size)
{
	htab_t *new_htab = htab_init(size);

	for (unsigned int i = 0; i < t->arr_size; i++) {
		htab_listitem_t *item = t->list[i];

		while (item != NULL) {
			htab_insert(new_htab, item->key, item->data);
			item = item->next;
		}
	}

	htab_free(t);
	*t = *new_htab;
	free(new_htab);
}