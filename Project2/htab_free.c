//
// Created by kalen on 15.04.22.
//

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

void htab_free(htab_t *t) {
	if (t == NULL)
		return;

	htab_clear(t);
	free(t);
}
