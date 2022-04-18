// io.c
// Řešení IJC-DU2, příklad 2), 16.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include <stdio.h>

int read_word(char *s, int max, FILE *f) {
	int c;
	int length = 0;
	while ((c = getc(f)) != ' ' && c != '\n') {
		if (c == EOF) {
			return EOF;
		}
		if (length < max - 1) {
			s[length] = (char) c;
			length++;
		} else {
			continue;
		}
	}
	s[length] = '\0';
	return length;
}
