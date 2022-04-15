//
// Created by kalen on 14.04.22.
//

#include "htab.h"
#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
	if (t == NULL || f == NULL) {
		return;
	}

	htab_listitem_t *item;
	for (size_t i = 0; i < t->arr_size; i++) {
		item = t->list[i];

		while (item != NULL) {
			f(item->data);
			item = item->next;
		}
	}
}
