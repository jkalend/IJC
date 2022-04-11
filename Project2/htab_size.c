//
// Created by kalen on 11.04.22.
//

#include "htab.h"
#include "htab_private.h"

size_t htab_size(const htab_t *t)
{
	return t->size;
}
