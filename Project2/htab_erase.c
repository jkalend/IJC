//
// Created by kalen on 15.04.22.
//
//TODO resize when size drops below 1/2 of the macro

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

bool htab_erase(htab_t * t, htab_key_t key) {
	if (t == NULL || key == NULL)
		return false;

	size_t index = htab_hash_function(key) % t->arr_size;
	htab_listitem_t *item = t->list[index];

	if (item != NULL) {
		if (strcmp(item->data->key, key) == 0) {
			t->list[index] = item->next;
			free(item->data);
			free(item);
			t->size--;

			if ((double)t->size/(double)t->arr_size < AVG_LEN_MIN) {
				htab_resize(t, t->arr_size / 2);
			}

			return true;
		} else {
			//to store the previous item
			htab_listitem_t *before = item;
			item = item->next;
			while (item != NULL) {
				if (strcmp(item->data->key, key) == 0) {
					before->next = item->next;
					free(item->data);
					free(item);
					t->size--;

					if ((double)t->size/(double)t->arr_size < AVG_LEN_MIN) {
						htab_resize(t, t->arr_size / 2);
					}

					return true;
				}
				//moves the last item to the current one
				before = item;
				//moves the current item to the next one
				item = item->next;
			}
		}
	}

	return false;
}
