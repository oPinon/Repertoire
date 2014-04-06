#include "hash_table.h"
#include <stdio.h>

int main() {
	
	hash_table_t* people = hash_table_init(100);
	
	entry_t oliv = { (unsigned char*) "Pinon", (unsigned char*)"Olivier", (unsigned char*)"01 02 03 04", (unsigned char*)"Paris" };
	entry_t pa = { (unsigned char*)"Durand", (unsigned char*)"Pierre-Alexandre", (unsigned char*)"33 04 10", (unsigned char*)"Lyon" };

	hash_table_insert( people, &oliv );
	hash_table_insert( people, &pa );

	hash_table_print( people );

	bool test = hash_table_find_by_name(people, (unsigned char*) "Durand");
	printf("Is Mr Durand here ? ");
	printf( test ? "Yes !\n" : "No...\n");

	test = hash_table_find_by_name(people, (unsigned char*) "Dupond");
	printf("Is Mr Dupond here ? ");
	printf( test ? "Yes...\n" : "No !\n");

	hash_table_destroy( people );
	
	printf("hash map test done\n");

	return 0;
};
