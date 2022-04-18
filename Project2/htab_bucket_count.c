// htab_bucket_count.c
// Řešení IJC-DU2, příklad 2), 11.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include "htab.h"
#include "htab_private.h"

size_t htab_bucket_count(const htab_t *t) {
	return t->arr_size;
}
