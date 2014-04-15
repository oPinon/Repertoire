#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"
#include "entry.h"

struct _hash_table_t {
	unsigned long size;
	list_t* tab;
};
typedef struct _hash_table_t hash_table_t;

unsigned long hash (unsigned char * str);

unsigned long hash_entry (unsigned char * first_name, unsigned char * last_name, unsigned long key_half_size);

// Initialize an hash table. Return NULL if it fails.
hash_table_t* hash_table_init(unsigned long size);

// Destroy the hash table.
void hash_table_destroy(hash_table_t* table);

// Insert a value in the hash table. It the insertion took place, true is returned, false otherwise.
bool hash_table_insert(hash_table_t* table, entry_t* value);

// Return a linked_list of all the entries corresponding to that name
list_t hash_table_find_by_name(hash_table_t* table, unsigned char* value);
list_t hash_table_find_by_surname(hash_table_t* table, unsigned char* value);

// Remove a value in the hash table. It the deletion took place, true is returned, false otherwise.
bool hash_table_remove(hash_table_t* table, entry_t* value);

// Return the number of values.
unsigned long hash_table_size(hash_table_t* table);

// Print all the values.
void hash_table_print(hash_table_t* table);
