//
// Created by kalen on 11.04.22.
//

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

htab_t *htab_init(size_t size)
{
	htab_t *htab = malloc(sizeof(htab_t));
	if (htab == NULL)
		return NULL;
	htab->size = size;
	htab->list = malloc(sizeof(struct htab_listitem*) * size);
	if (htab->list == NULL)
		return NULL;
	for (unsigned int i = 0; i < size; i++)
		htab->list[i] = NULL;
	return htab;
}
