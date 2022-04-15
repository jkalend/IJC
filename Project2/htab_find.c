//
// Created by kalen on 15.04.22.
//

#include "htab.h"
#include "htab_private.h"

htab_pair_t *htab_find(htab_t * t, htab_key_t key)
{
	if (t == NULL || key == NULL) {
		return NULL;
	}

	htab_pair_t *pair = NULL;
	size_t index = htab_hash_function(key) % t->arr_size;
	htab_listitem_t *item = t->list[index];

	while (item != NULL) {
		if (item->data->key == key) {
			pair = item->data;
			break;
		}
		item = item->next; //FIXME why? 1 index will have the same key?
	}
	return pair;
}
