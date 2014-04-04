#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

struct _hash_table_t {
	unsigned long size;
	list_t* tab;
};
typedef struct _hash_table_t hash_table_t;

unsigned long hash ( unsigned char * str );

unsigned long hash ( unsigned char * first_name, unsigned char * last_name, unsigned long key_half_size);

// Initialize an hash table. Return NULL if it fails.
hash_table_t* hash_table_init(unsigned long size);

// Destroy the hash table.
void hash_table_destroy(hash_table_t* table);

// Insert a value in the hash table. It the insertion took place, true is returned, false otherwise.
bool hash_table_insert(hash_table_t* table, char* value);

// Return true if the value was found, false otherwise.
bool hash_table_find_by_first_name(hash_table_t* table, char* value);
bool hash_table_find_by_last_name(hash_table_t* table, char* value)

// Remove a value in the hash table. It the deletion took place, true is returned, false otherwise.
bool hash_table_remove(hash_table_t* table, char* value);

// Return the number of values.
unsigned long hash_table_size(hash_table_t* table);

// Print all the values.
void hash_table_print(hash_table_t* table);
