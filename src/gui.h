#pragma once
#define _GUI_H_

#include "hash_table.h"

int run(const char* argv[]); //runs the GUI

void save(hash_table_t* table, const char* filename);
void quit_menu(hash_table_t* table, const char* filename);

bool has_combination(hash_table_t* table, char* name, char* surname);
int add_entry(hash_table_t* table);
int erase_entry(hash_table_t* table, entry_t* entry_p);

int change_name(hash_table_t* table, entry_t* entry_p);
int change_surname(hash_table_t* table, entry_t* entry_p);
int change_tel(entry_t* entry_p);
int change_address(entry_t* entry_p);

void modify_menu(hash_table_t* table, entry_t* entry_p);

list_t search_entries(hash_table_t* table, int choice);
