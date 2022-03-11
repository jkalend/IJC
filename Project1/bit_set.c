//
// Created by kalen on 2022-03-11.
//


#include "bit_set.h"

#ifdef USE_INLINE

    extern inline unsigned long bitset_getbit(bitset_t jmeno_pole, unsigned long index);
    extern inline unsigned long bitset_size(bitset_t jmeno_pole);
    extern inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, unsigned long value);
    extern inline void bitset_free(bitset_t jmeno_pole);

#endif