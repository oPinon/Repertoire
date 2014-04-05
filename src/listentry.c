#include "listentry.h"

bool eq_str ( char* s1, char* s2 ) {
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
