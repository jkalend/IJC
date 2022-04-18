// htab_free.c
// Řešení IJC-DU2, příklad 2), 15.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

void htab_free(htab_t *t) {
	if (t == NULL)
		return;

	htab_clear(t);
	free(t);
}
