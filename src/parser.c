#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "linked_list.h"

void read(hash_table_t* table, const char* filename) {
  
	FILE* f = fopen(filename,"r");
	if(f == NULL){
		printf("Could not find %s\nCreating file...\n",filename);
		FILE* f = fopen(filename,"r");
		fclose(f);
		return;
	}

    char buffer[100][1];

	unsigned int i=0;
	fgets(buffer[i],1023,f);
  
	 while(buffer[i][0]=='#'){
        entry_t* entry = init_entry();
 		fgets(entry->name,1023,f);
 		fgets(entry->surname,1023,f); 
 		fgets(entry->tel,1023,f);
 		fgets(entry->address,1023,f);
 		
 		entry->name[ strlen(entry->name) - 1 ] = '\0';  //suppress \n character
 		entry->surname[ strlen(entry->surname) - 1 ] = '\0';
 		entry->tel[ strlen(entry->tel) - 1 ] = '\0';
 		entry->address[ strlen(entry->address) - 1 ] = '\0';
 		
        hash_table_insert(table,entry);
   	 	i++;

 		fgets(buffer[i],1023,f);
 
	}

	fclose(f);
}


void write(hash_table_t* table, const char* filename) { 
  
FILE* f = fopen(filename,"w");

for(unsigned int i=0; i<table->size*table->size; i++) {
	if(table->tab[i]!=NULL) {
		while (table->tab[i] != NULL){
  			entry_t* entry_p = table->tab[i]->value;
  			char towrite[4*1024+2];
  			sprintf(towrite,"#\n%s\n%s\n%s\n%s\n",entry_p->name, entry_p->surname, entry_p->tel, entry_p->address);
  			fwrite(towrite, sizeof(char), strlen(towrite), f);
  				  
   			table->tab[i] = table->tab[i]->next;
 		}
	}
}

fclose(f);

}
