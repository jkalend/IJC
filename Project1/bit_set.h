//bit_set.h
//author: Jan Kalenda (xkalen07), VUT FIT

#include <limits.h>
#include <stdlib.h>
#include "error.h"
#include <stdio.h>
#include <assert.h>

#ifndef BIT_SET_H
#define BIT_SET_H

typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;

#define UL_BIT (sizeof(unsigned long) * CHAR_BIT)


#define bitset_create(jmeno_pole, velikost)_Static_assert(!((velikost) < 1), "Velikost pole nemuze byt mensi jak 1");\
                unsigned long (jmeno_pole) [((velikost) / UL_BIT) + 1 + (((velikost) % UL_BIT) ? 1 : 0)] = {velikost};

#define bitset_alloc(jmeno_pole, velikost) assert((velikost) > 0);\
                unsigned long *(jmeno_pole) = calloc(((velikost) / UL_BIT) + 1 + \
                (((velikost) % UL_BIT) ? 1 : 0), sizeof(unsigned long)); \
                if ((jmeno_pole) == NULL)                     \
                { error_exit("Aloakce pameti selhala\n");                                   \
                } *(jmeno_pole) = velikost;


#ifdef USE_INLINE
    inline unsigned long bitset_size(bitset_t jmeno_pole) {return jmeno_pole[0];}

        //TODO add errotexit
    inline unsigned long bitset_getbit(bitset_t jmeno_pole, unsigned long index) {
         return (((jmeno_pole)[(index) / UL_BIT + 1] & (1UL<< ((index) % UL_BIT)))!= 0 );
        }

    inline void bitset_setbit(bitset_t jmeno_pole, unsigned long index, unsigned long vyraz) {
        if (vyraz) {
            unsigned long one = 0x00000001;
            (jmeno_pole)[(index) / UL_BIT + 1] |= (one << ((index) % UL_BIT));
        }
        else {
           unsigned long one = 0x00000001;
            (jmeno_pole)[(index) / UL_BIT + 1] &= ~(one << ((index) % UL_BIT));
        }
    }

    inline void bitset_free(bitset_t jmeno_pole) {free((jmeno_pole));}

#else
    #define bitset_free(jmeno_pole) assert((jmeno_pole) != NULL); \
                    free((jmeno_pole));
    #define bitset_size(jmeno_pole) ((jmeno_pole)[0])

    #define bitset_setbit(jmeno_pole, index, vyraz) \
        if (vyraz) {                                                        \
        (jmeno_pole)[(index) / UL_BIT + 1] |= (1UL << ((index) % UL_BIT));  \
        }                                                \
        else {                                          \
        (jmeno_pole)[(index) / UL_BIT + 1] &= ~(1UL << ((index) % UL_BIT)); \
        }

    #define bitset_getbit(jmeno_pole, index) \
        (((jmeno_pole)[(index) / UL_BIT + 1] & (1UL << ((index) % UL_BIT)))!= 0 )



#endif

#endif

