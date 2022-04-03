# Makefile
# Řešení IJC-DU1, příklad c), 16.3.2022
# Autor: Jan Kalenda, FIT
# Přeloženo: gcc 11.2


LC_ALL=cs._CZ.utf8
CC=gcc
CFLAGS = -g -O2 -std=c11 -Wall -Wextra -pedantic -lm

all: primes primes-i steg-decode

run: primes primes-i steg-decode
		ulimit -s 40000 && ./primes
		ulimit -s 40000 && ./primes-i


primes: bitset.o Eratosthenes.o primes.o error.o
		$(CC) $(CFLAGS) bitset.o Eratosthenes.o bitset.o primes.o error.o -o primes

primes-i: bitset-i.o Eratosthenes-i.o primes.o error.o
		$(CC) $(CFLAGS) -DUSE_INLINE bitset-i.o Eratosthenes-i.o primes.o error.o -o primes-i

steg-decode: ppm.o Eratosthenes.o error.o steg-decode.o
		$(CC) $(CFLAGS) ppm.o Eratosthenes.o error.o steg-decode.o -o steg-decode



error.o: error.c error.h
		$(CC) $(CFLAGS) -c error.c -o error.o

primes.o: primes.c
		$(CC) $(CFLAGS) -c primes.c -o primes.o

bitset.o: bitset.c bitset.h
		$(CC) $(CFLAGS) -c bitset.c -o bitset.o

Eratosthenes.o: Eratosthenes.c Eratosthenes.h
		$(CC) $(CFLAGS) -c Eratosthenes.c -o Eratosthenes.o




bitset-i.o: bitset.c bitset.h
		$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o

Eratosthenes-i.o: Eratosthenes.c Eratosthenes.h
		$(CC) $(CFLAGS) -DUSE_INLINE -c Eratosthenes.c -o Eratosthenes-i.o




ppm.o: ppm.c ppm.h
	 	$(CC) $(CFLAGS) -c ppm.c -o ppm.o

steg-decode.o: steg-decode.c  ppm.h error.h
		$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o


clean:
	rm *.o primes primes-i steg-decode

zip:
	zip xkalen07.zip *.c *.h Makefile
