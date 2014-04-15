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
		return;
	}

   	 char buffer[100][1];

	unsigned int i=0;
	fgets(buffer[i],1024,f);
  
	 while(buffer[i][0]=='#'){
        entry_t* entry = init_entry();
        
        if(entry==NULL) break;
        
 		fgets(entry->name,1024,f);
 		fgets(entry->surname,1024,f); 
 		fgets(entry->tel,1024,f);
 		fgets(entry->address,1024,f);
 		
 		entry->name[ strlen(entry->name) - 1 ] = '\0';  //suppress \n character
 		entry->surname[ strlen(entry->surname) - 1 ] = '\0';
 		entry->tel[ strlen(entry->tel) - 1 ] = '\0';
 		entry->address[ strlen(entry->address) - 1 ] = '\0';
 		
       	hash_table_insert(table,entry);
   	 	i++;

 		fgets(buffer[i],1024,f);
 
	}

	fclose(f);
}


void write(hash_table_t* table, const char* filename) { 
  
	FILE* f = fopen(filename,"w");

	for(unsigned int i=0; i<table->size*table->size; i++) {	
		list_t l = table->tab[i];

  		while (l != NULL){
			char towrite[4*1024+5+1];  //4*1024 for entry data, 5 newlines, 1 new entry delimiter (#)
			entry_t* entry_p = l->value;
  	   		sprintf(towrite,"#\n%s\n%s\n%s\n%s\n",entry_p->name, entry_p->surname, entry_p->tel, entry_p->address);
  			fwrite(towrite, sizeof(char), strlen(towrite), f);
    		
			l = l->next;
		}	 

	}

	fclose(f);

}


