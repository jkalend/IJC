//
// Created by kalen on 10.04.22.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include "htab_private.h"

/*
//
// Function: hashtable_new
//
// Allocate a new hashtable.
//
// Parameters:
//     capacity - the initial capacity of the hashtable
//
// Returns:
//     a pointer to the new hashtable
//
hashtable_t *hashtable_new(int capacity)
{
	hashtable_t *hashtable = malloc(sizeof(hashtable_t));
	assert(hashtable != NULL);
	hashtable->capacity = capacity;
	hashtable->size = 0;
	hashtable->table = malloc(sizeof(hashtable_entry_t) * capacity);
	assert(hashtable->table != NULL);
	for (int i = 0; i < capacity; i++) {
		hashtable->table[i] = NULL;
	}
	return hashtable;
}


//
// Function: hashtable_free
//
// Free the memory allocated for a hashtable.
//
// Parameters:
//     hashtable - the hashtable to free
//
void hashtable_free(hashtable_t *hashtable)
{
	assert(hashtable != NULL);
	for (int i = 0; i < hashtable->capacity; i++) {
		hashtable_entry_t *entry = hashtable->table[i];
		while (entry != NULL) {
			hashtable_entry_t *next = entry->next;
			free(entry->key);
			free(entry->value);
			free(entry);
			entry = next;
		}
	}
	free(hashtable->table);
	free(hashtable);
}*/


//
// Function: hashtable_insert
//
// Insert a key-value pair into a hashtable.
//
// Parameters:
//     hashtable - the hashtable
//     key - the key to insert
//     value - the value to insert
//
// Returns:
//     nothing
//
void hashtable_insert(hashtable_t *hashtable, char *key, char *value)
{
	assert(hashtable != NULL);
	assert(key != NULL);
	assert(value != NULL);
	int index = hash_function(key, hashtable->capacity);
	hashtable_entry_t *entry = hashtable->table[index];
	while (entry != NULL) {
		if (strcmp(entry->key, key) == 0) {
			free(entry->value);
			entry->value = value;
			return;
		}
		entry = entry->next;
	}
	hashtable_entry_t *new_entry = malloc(sizeof(hashtable_entry_t));
	assert(new_entry != NULL);
	new_entry->key = key;
	new_entry->value = value;
	new_entry->next = hashtable->table[index];
	hashtable->table[index] = new_entry;
	hashtable->size++;
}