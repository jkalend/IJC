# Makefile
# Řešení IJC-DU2, příklad 2), 17.4.2022
# Autor: Jan Kalenda, FIT
# Přeloženo: gcc 11.2

CC=gcc
CFLAGS = -g -O2 -std=c11 -Wall -Wextra -pedantic

all: tail wordcount wordcount-dynamic libhtab.a libhtab.so

wordcount-dynamic: main.o io.o libhtab.so
	$(CC) $(CFLAGS)  $^ -o $@
wordcount: main.o io.o libhtab.a
	$(CC) $(CFLAGS) $^ -o $@
main.o: main.c
	$(CC) $(CFLAGS) -c $<
io.o: io.c io.h
	$(CC) $(CFLAGS) -c $<

tail: tail.o
	$(CC) $(CFLAGS) $^ -o $@
tail.o: tail.c
	$(CC) $(CFLAGS) -c $<

libhtab.a: htab_clear.o htab_bucket_count.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o
	ar rcs $@ $^

libhtab.so: htab_clear.o htab_bucket_count.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_resize.o htab_size.o
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^

htab_clear.o: htab_clear.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_bucket_count.o: htab_bucket_count.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_erase.o: htab_erase.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_find.o: htab_find.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_for_each.o: htab_for_each.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_free.o: htab_free.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_hash_function.o: htab_hash_function.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_init.o: htab_init.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_lookup_add.o: htab_lookup_add.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_resize.o: htab_resize.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

htab_size.o: htab_size.c htab.h htab_private.h
	$(CC) $(CFLAGS) -fPIC -c $<

zip:
	zip xkalen07.zip *.c *.h Makefile

clean:
	rm *.o *.a *.so tail wordcount wordcount-dynamic
