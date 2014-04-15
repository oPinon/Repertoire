#include "hash_table.h"
#include <stdio.h>

int main() {
	
	hash_table_t* people = hash_table_init(100);
	
	entry_t oliv = { "Pinon", "Olivier", "01 02 03 04", "Paris" };
	entry_t pa = { "Durand", "Pierre-Alexandre", "33 04 10", "Lyon" };

	printf("Does string equality work ? %d\n", eq_str(pa.name, "Durand"));

	hash_table_insert( people, &oliv );
	hash_table_insert( people, &pa );

	hash_table_print( people );

	list_t test = hash_table_find_by_name(people, "Durand");
	printf("%s\n   ", "Is M.Durand here ?");
	print_list(test);
	destroy_list(test);

	test = hash_table_find_by_surname(people, "Pierre-Alexandre");
	printf("%s\n   ", "Is Pierre-Alexandre here ?");
	print_list(test);
	destroy_list(test);

	printf("hash map test done\n");
	hash_table_print(people);

	hash_table_destroy( people );

	return 0;
};
