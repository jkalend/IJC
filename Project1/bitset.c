// bitset.c
// Řešení IJC-DU1, příklad a), 16.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2
// modul nutny pro inline funkce

#include "bitset.h"

#ifdef USE_INLINE

extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);
extern inline unsigned long bitset_size(bitset_t jmeno_pole);
extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, unsigned long value);
extern inline void bitset_free(bitset_t jmeno_pole);

#endif
