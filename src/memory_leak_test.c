#include "listentry.h"
#include "linked_list.h"
#include "hash_table.h"

#include <stdlib.h>
#include <stdio.h>

entry_t* init_entries();
void copy_string(char* src, char* dst);

int main() {

	entry_t* e1 = init_entries();
	entry_t* e2 = init_entries();
	entry_t* e3 = init_entries();

	// testing listentry
	{
		// WARNING !! Do not declare entries this way, as they are destroyed when you get out of their scope !
		/*entry_t e2 = { (char*)"pa", (char*)"Durand",
		(char*)"01023442", (char*)"xoOXOox-PA-xoOXOox@yahoo.fr"};*/

		destroy_entry(e1);
		destroy_entry(e2);
		destroy_entry(e3);
	}

	// testing linked_list
	{
		e1 = init_entries();
		e2 = init_entries();
		e3 = init_entries();

		list_t list = init_list();
		push_front(&list, e1);
		push_back(&list,e2);
		push_front(&list,e3);
		erase(&list,e1);


	}

	return 0;
}

entry_t* init_entries() {
	entry_t* e1 = init_entry();
	copy_string(e1->name, "pa");
	copy_string(e1->surname, "Durand");
	copy_string(e1->tel, "013020323");
	copy_string(e1->address, "pa@yamail.fr");
	return e1;
}

void copy_string(char* src, char* dst) {
	while(*src!='\0') {
		*dst = *src;
		dst++;
		src++;
	}
	dst = '\0';
}