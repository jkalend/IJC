// bitset.h
// Řešení IJC-DU1, příklad a), 16.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2
// hlavickovy soubor s makry a definici inline funkci

#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;
typedef unsigned long UL;

#define UL_BITS (sizeof(unsigned long) * CHAR_BIT)

// + 1 na ulozeni velikosti pole, ternarni operator pro pripady kdy velikost
// neni presne delitelne UL_BITS
#define bitset_create(jmeno_pole, velikost)                                                        \
	_Static_assert(((velikost) > 0), "Velikost pole nemuze byt mensi jak 1");                      \
	UL(jmeno_pole)                                                                                 \
	[((velikost) / UL_BITS) + 1 + (((velikost) % UL_BITS) ? 1 : 0)] = { velikost };

#define bitset_alloc(jmeno_pole, velikost)                                                         \
	assert((velikost) > 0);                                                                        \
	UL *(jmeno_pole) = (UL *)calloc(((velikost) / UL_BITS) + 1 + (((velikost) % UL_BITS) ? 1 : 0), \
									sizeof(UL));                                                   \
	if ((jmeno_pole) == NULL) {                                                                    \
		error_exit("Aloakce pameti selhala\n");                                                    \
	}                                                                                              \
	*(jmeno_pole) = velikost;

#ifdef USE_INLINE
inline UL bitset_size(bitset_t jmeno_pole)
{
	return jmeno_pole[0];
}

inline UL bitset_getbit(bitset_t jmeno_pole, bitset_index_t index)
{
	if ((UL)(index) >= (UL)((jmeno_pole)[0]))
		(error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (UL)(index),
					(UL)((jmeno_pole)[0] - 1)));
	return (!!((jmeno_pole)[(index) / UL_BITS + 1] & (1UL << ((index) % UL_BITS))));
}

inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, UL vyraz)
{
	if ((UL)(index) >= (UL)((jmeno_pole)[0]))
		(error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (UL)(index),
					(UL)((jmeno_pole)[0] - 1)));
	if (vyraz) {
		(jmeno_pole)[(index) / UL_BITS + 1] |= (1UL << ((index) % UL_BITS));
	} else {
		(jmeno_pole)[(index) / UL_BITS + 1] &= ~(1UL << ((index) % UL_BITS));
	}
}

inline void bitset_free(bitset_t jmeno_pole)
{
	free((jmeno_pole));
}

#else
#define bitset_free(jmeno_pole) free((jmeno_pole));
#define bitset_size(jmeno_pole) (jmeno_pole)[0]

#define bitset_setbit(jmeno_pole, index, vyraz)                                                    \
	if ((UL)(index) >= (UL)((jmeno_pole)[0]))                                                      \
		(error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (UL)(index),                    \
					(UL)((jmeno_pole)[0] - 1)));                                                   \
	if (vyraz) {                                                                                   \
		(jmeno_pole)[(index) / UL_BITS + 1] |= (1UL << ((index) % UL_BITS));                       \
	} else {                                                                                       \
		(jmeno_pole)[(index) / UL_BITS + 1] &= ~(1UL << ((index) % UL_BITS));                      \
	}

#define bitset_getbit(jmeno_pole, index)                                                           \
	((UL)(index) >= (UL)((jmeno_pole)[0])) ?                                                       \
			(error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (UL)(index),                \
						(UL)((jmeno_pole)[0] - 1)),                                                \
			 0) :                                                                                  \
			  (!!(((jmeno_pole)[(((UL)(index)) / UL_BITS) + 1] &                                   \
				 (1UL << (((UL)(index)) % UL_BITS)))))

// !!() pro prevod jakehokoliv cisla na 0 nebo 1

#endif //USE_INLINE

#endif //BITSET_H
