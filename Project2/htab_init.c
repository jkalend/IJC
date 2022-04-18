// htab_init.c
// Řešení IJC-DU2, příklad 2), 11.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

htab_t *htab_init(size_t size) {
	htab_t *htab = malloc(sizeof(htab_t));
	if (htab == NULL)
		return NULL;
	htab->arr_size = size;
	htab->size = 0;

	htab->list = malloc(sizeof(struct htab_listitem*) * size);
	if (htab->list == NULL)
		return NULL;

	for (unsigned int i = 0; i < size; i++) {
		htab->list[i] = NULL;
	}

	return htab;
}
