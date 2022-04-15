//
// Created by kalen on 11.04.22.
//

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

void htab_resize(htab_t *t, size_t size)
{
	htab_t *new_htab = htab_init(size);

	for (unsigned int i = 0; i < t->arr_size; i++) {
		htab_listitem_t *item = t->list[i];

		new_htab->list[i] = item;
		t->list[i] = NULL;
	}

	htab_free(t);
	*t = *new_htab;
}
