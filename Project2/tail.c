//
// Created by kalen on 03.04.22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void *Realloc(void *ptr, size_t size)
{
	if (size <= 0)
	{
		if (ptr != NULL) free(ptr);
		return NULL;
	}

	void *tmp = realloc(ptr, size);
	if (tmp == NULL)
	{
		if (ptr != NULL) free(ptr);
		return NULL;
	}

	else
		return tmp;
}

//create a tail function that takes a file name and number of lines to output
//the last number of lines of the file

void tail (FILE *fp, long line_count) {
	bool error = false;
	bool skip = false;
	long line_number = 0;
	char **lines = malloc(sizeof(char*));

	char buffer[4096] = {0};
	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		// skips the rest of the line
		if (skip == true) {
			skip = false;
			continue;
		}
		//checks whether the line is a complete line
		if (buffer[strlen(buffer) - 2] != '\n') {
			if (error == false) {
				fprintf(stderr, "A least one line is too long\n");
				error = true;
			}
			buffer[strlen(buffer) - 1] = '\0';
			buffer[strlen(buffer) - 2] = '\n';
			skip = true;
		}

		line_number++;
		lines = Realloc(lines, sizeof(char*) * line_number);
		if (lines == NULL) {
			fprintf(stderr, "Allocation failed\n");
			exit(EXIT_FAILURE);
		}
		lines[line_number - 1] = malloc(sizeof(char) * (strlen(buffer) + 1));
		if (lines[line_number - 1] == NULL) {
			fprintf(stderr, "Allocation failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(lines[line_number - 1], buffer);
	}

	for (long i = line_number - line_count; i < line_number; i++) {
		printf("%s", lines[i]);
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		tail(stdin, 10);
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
		if (strtol(argv[2], NULL, 10) < 0) {
			fprintf(stderr, "Invalid number of lines\n");
			return 1;
		}

		tail(stdin, strtol(argv[2], NULL, 10));
	} else if (argc == 4) {
		if (strcmp(argv[1], "-n") != 0) {
			fprintf(stderr, "Invalid option\n");
			return 1;
		}

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
	} else {
		fprintf(stderr, "Invalid number of arguments\n");
		return 1;
	}

	return 0;
}

