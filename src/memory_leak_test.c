#include "listentry.h"
#include "linked_list.h"
#include "hash_table.h"

#include <stdlib.h>
#include <stdio.h>

entry_t* init_entries();
void copy_string(unsigned char* src, unsigned char* dst);

int main() {

	entry_t* e1 = init_entries();
	entry_t* e2 = init_entries();
	entry_t* e3 = init_entries();

	// testing listentry
	{
		// WARNING !! Do not declare entries this way, as they are destroyed when you get out of their scope !
		/*entry_t e2 = { (unsigned char*)"pa", (unsigned char*)"Durand",
		(unsigned char*)"01023442", (unsigned char*)"xoOXOox-PA-xoOXOox@yahoo.fr"};*/

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
	copy_string(e1->name,(unsigned char*) "pa");
	copy_string(e1->surname,(unsigned char*) "Durand");
	copy_string(e1->tel,(unsigned char*) "013020323");
	copy_string(e1->address,(unsigned char*) "pa@yamail.fr");
	return e1;
}

void copy_string(unsigned char* src, unsigned char* dst) {
	while(*src!='\0') {
		*dst = *src;
		dst++;
		src++;
	}
	dst = '\0';
}