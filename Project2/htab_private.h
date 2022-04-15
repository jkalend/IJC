//
// Created by kalen on 10.04.22.
//

#ifndef IJC_HTAB_PRIVATE_H
#define IJC_HTAB_PRIVATE_H

#include "htab.h"

typedef struct htab_listitem {
	htab_pair_t *data;
	struct htab_listitem *next;
}htab_listitem_t;

struct htab {
	size_t size;
	size_t arr_size;
	htab_listitem_t **list;
};

#endif //IJC_HTAB_PRIVATE_H
