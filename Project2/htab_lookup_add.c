//
// Created by kalen on 15.04.22.
//

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key) {
	htab_pair_t *pair = htab_find(t, key);
	if (pair == NULL) {
		size_t index = htab_hash_function(key) % t->arr_size;
		htab_listitem_t *item = malloc(sizeof(htab_listitem_t));
		if (item == NULL) {
			return NULL;
		}
		item->data = malloc(sizeof(htab_pair_t));
		if (item->data == NULL) {
			free(item);
			return NULL;
		}
		item->data->key = malloc(strlen(key) + 1);
		if (item->data->key == NULL) {
			free(item->data);
			free(item);
			return NULL;
		}
		item->next = NULL;

		//memcpy(item->data->key, key, strlen(key) + 1);
		//strcpy(item->data->key, key);
		//item->data->key = key;
		item->data->value = 1;


		if (t->list[index] == NULL) {
			t->list[index] = item;
			pair = item->data;
			t->size++;
		} else {
			bool found = false;
			htab_listitem_t *step = t->list[index];
			while (step != NULL) {
				if (strcmp(step->data->key, key) == 0) {
					step->data->value++;
					pair = step->data;
					found = true;
				}
				step = step->next;
			}
			if (found == false) {
				step = t->list[index];
				while (step->next != NULL) {
					step = step->next;
				}
				step->next = item;
				pair = item->data;
				t->size++;
			}
		}
	}
	if ((double)t->size/(double)t->arr_size >  AVG_LEN_MAX) {
		htab_resize(t, t->arr_size * 2);
	}
	return pair;
}
