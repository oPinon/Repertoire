#pragma once

#include <stdbool.h>

typedef struct _entry_t {
	char* name;
	char* surname;
	char* tel;
	char* address;
} entry_t;

bool eq_str ( char* s1, char* s2 );

bool eq_entry ( entry_t* e1, entry_t* e2 );

void print_entry(entry_t* entry);

entry_t* init_entry();

void destroy_entry(entry_t* entry);





