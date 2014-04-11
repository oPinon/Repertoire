#include "listentry.h"
#include <stdio.h>
#include <stdlib.h>

bool eq_str ( unsigned char* s1, unsigned char* s2 ) {
	while( *s1 != '\0' ) {
		if( *s1 != *s2 ) { return false; }
		else { s1++; s2++; }
	}
	if( *s1 != *s2 ) { return false; }
	else { return true; }
};

bool eq_entry ( entry_t* e1, entry_t* e2 ) {
	return eq_str(e1->name,e2->name) && eq_str(e1->surname,e2->surname);
};

void print_entry(entry_t* entry) {
	printf("[ %s %s ] %s %s\n", entry->name, entry->surname, entry->tel, entry->address);
};

entry_t* init_entry(){
	 entry_t* entry= malloc(sizeof(entry_t));
	 entry->name = malloc(1023*sizeof(char));
	 entry->surname = malloc(1023*sizeof(char));
	 entry->tel = malloc(1023*sizeof(char));
	 entry->address = malloc(1023*sizeof(char));
	    return entry;
}

void destroy_entry(entry_t* entry){
		 free(entry->name);
		 free(entry->surname);
		 free(entry->tel);
		 free(entry->address);
		 free(entry);
}
