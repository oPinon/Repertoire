#include <stdio.h>
#include "hash_table.h"

unsigned long hash ( unsigned char * str ) {
	unsigned long hash = 5381;
	int c;
	while ( c = * str ++) {
		hash = (( hash << 5) + hash ) + c ; /* hash * 33 + c */
	}
	return hash ;
}

// key is coded as : first_name + key_half_size * last_name
unsigned long hash ( unsigned char * first_name, unsigned char * last_name, unsigned long key_half_size) {
	return (hash(first_name) % key_half_size) + key_half_size*(hash(last_name) % key_half_size);
};

hash_table_t* hash_table_init(unsigned long size) {
	hash_table_t* toReturn = malloc(sizeof(hash_table_t));
	if(toReturn != NULL) {
		toReturn->size = size;
		toReturn->tab = malloc(sizeof(list_t)*(size*size)); //TODO is that the correct size ?
		if(toReturn->tab == NULL) { return NULL; }
		else {
			for(unsigned long i=0; i<size; i++) {
				toReturn->tab[i] = NULL;
			}
		}
	}
	return toReturn;
};

void hash_table_destroy(hash_table_t* table) {
	if(table==NULL) { return; }	
	for(unsigned long i=0; i<table->size; i++) {
		destroy_list(table->tab[i]);
	}
	free(table->tab);
	free(table);
};

bool hash_table_insert(hash_table_t* table, char* value) {
	if(table==NULL) { return false; }
	unsigned long position = hash(value) % table->size;
	list_t* list = &table->tab[position];
	if(!find(*list,value)) {
		if(push_front(list,value)==0) { return true; }
	}
	return false;	
};

bool hash_table_find_by_first_name(hash_table_t* table, char* value) {
	if(table==NULL) { return false; }
	for(unsigned long i = hash(value)%table->size; i < table->size*table->size; i += table->size) {
		if(find(*table->tab[i],value) { return true; } //TODO shall return the entry
	}
	return false;
};

bool hash_table_find_by_last_name(hash_table_t* table, char* value) {
	if(table==NULL) { return false; }
	for(unsigned long i = (hash(value)%table->size)*table->size; i < (hash(value)%table->size)*table->size + table->size; i++) {
		if(find(*table->tab[i],value) { return true; } //TODO shall return the entry
	}
	return false;
};

bool hash_table_remove(hash_table_t* table, //entry_ptr) { //TODO
	if(table==NULL) { return false; }
	unsigned long position = hash(value) % table->size; // hash(entry_prt->name)....
	list_t* list = &table->tab[position];
	if(erase(list,value)==0) { return true; }
	return false;
};

unsigned long hash_table_size(hash_table_t* table) {
	if(table==NULL) { return 0; }	
	unsigned long toReturn = 0;
	for(unsigned long i=0; i<table->size*table->size; i++) {
		toReturn += size(table->tab[i]);
	}
	return toReturn;
};
