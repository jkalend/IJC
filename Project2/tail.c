// tail.c
// Řešení IJC-DU2, příklad 1), 14.4.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 4096

void tail (FILE *fp, long line_count) {
	bool error = false;
	bool skip = false;
	char **lines = malloc(sizeof(char*) * line_count);
	if (lines == NULL) {
		fprintf(stderr, "Allocation failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < line_count; i++) {
		lines[i] = malloc(sizeof(char) * LIMIT);
		lines[i][0] = '\0';
		if (lines[i] == NULL) {
			fprintf(stderr, "Allocation failed\n");
			exit(EXIT_FAILURE);
		}
	}

	char buffer[LIMIT] = {0};
	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		// skips the rest of the line
		if (skip == true && buffer[strlen(buffer) - 1] != '\n') {
			continue;
		} else if (skip == true) {
			skip = false;
			continue;
		}
		//checks whether the line is a complete line
		if (buffer[strlen(buffer) - 1] != '\n') {
			if (error == false) {
				fprintf(stderr, "At least one line is too long\n");
				error = true;
			}
			buffer[strlen(buffer)] = '\0';
			buffer[strlen(buffer) - 1] = '\n';
			skip = true;
		}
		for (long i = line_count-1; i > 0; i--) {
			memcpy(lines[i], lines[i-1], sizeof(char) * LIMIT);
		}
		memcpy(lines[0], buffer, sizeof(char) * LIMIT);
	}

	for (long i = line_count-1; i >= 0; i--) {
		if (lines[i][0] != 0) {
			printf("%s", lines[i]);
		}
	}
	for (long i = 0; i < line_count; i++) {
		free(lines[i]);
	}
	free(lines);
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		FILE* in = stdin;
		tail(in, 10);
	} else if (argc == 2 && strcmp(argv[1], "-n") == 0) {
		fprintf(stderr, "Option -n without a number\n");
		return 1;
	} else if (argc == 2 && strcmp(argv[1], "-n") != 0) {
		FILE *fp = fopen(argv[1], "r");

		if (fp == NULL) {
			printf("File does not exist\n");
			return 1;
		}

		tail(fp, 10);
		fclose(fp);
	} else if (argc == 3 && strcmp(argv[1], "-n") == 0) {
		char *errptr=NULL;
		strtol(argv[2], &errptr, 10);
		if (*errptr != 0) {
			fprintf(stderr, "Invalid number of lines\n");
			return 1;
		}

		tail(stdin, strtol(argv[2], NULL, 10));
	} else if (argc == 4) {
		if (strcmp(argv[1], "-n") == 0) {
			if (strtol(argv[2], NULL, 10) < 0) {
				fprintf(stderr, "Invalid number of lines\n");
				return 1;
			}

			FILE *fp = fopen(argv[3], "r");

			if (fp == NULL) {
				printf("File does not exist\n");
				return 1;
			}

			tail(fp, strtol(argv[2], NULL, 10));
			fclose(fp);
		}
		if (strcmp(argv[1], "-n") != 0) {
			if (strcmp(argv[2], "-n") != 0) {
				fprintf(stderr, "Invalid option\n");
				return 1;
			}
			if (strtol(argv[3], NULL, 10) < 0) {
				fprintf(stderr, "Invalid number of lines\n");
				return 1;
			}

			FILE *fp = fopen(argv[1], "r");

			if (fp == NULL) {
				printf("File does not exist\n");
				return 1;
			}

			tail(fp, strtol(argv[3], NULL, 10));
			fclose(fp);
		}

	} else {
		fprintf(stderr, "Invalid arguments\n");
		return 1;
	}

	return 0;
}
