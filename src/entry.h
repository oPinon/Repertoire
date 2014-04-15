#pragma once

#include <stdbool.h>

typedef struct _entry_t {
	unsigned char* name;
	unsigned char* surname;
	unsigned char* tel;
	unsigned char* address;
} entry_t;

bool eq_str ( unsigned char* s1, unsigned char* s2 );

bool eq_entry ( entry_t* e1, entry_t* e2 );

void print_entry(entry_t* entry);

entry_t* init_entry();

void destroy_entry(entry_t* entry);





