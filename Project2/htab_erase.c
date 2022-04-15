//
// Created by kalen on 15.04.22.
//
//TODO resize when size drops below 1/2 of the macro

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

bool htab_erase(htab_t * t, htab_key_t key)
{
	if (t == NULL || key == NULL)
		return false;

	//FIXME only one?
	//htab_pair_t *erased = htab_find(t, key);
	size_t index = htab_hash_function(key) % t->arr_size;
	htab_listitem_t *item = t->list[index];

	if (item != NULL)
	{
		if (item->data->key == key)
		{
			t->list[index] = item->next;
			free(item);
			t->size--;
			return true;
		}
		else
		{
			//to store the previous item
			htab_listitem_t *before = item;
			item = item->next;
			while (item != NULL)
			{
				if (item->data->key == key)
				{
					before->next = item->next;
					free(item);
					t->size--;
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
