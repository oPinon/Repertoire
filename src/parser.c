#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "linked_list.h"



void read(hash_table_t* table) {
  
	FILE* f = fopen("repertory.txt","r");
	if(f == NULL){
		printf("Could not find repertory.txt\nCreating file...\n");
		FILE* f = fopen("repertory.txt","r");
		fclose(f);
		return;
	}

	parsed_entry* parsed = malloc(500*sizeof(parsed_entry));
	if(parsed == NULL){
		printf("Could not allow memory for parsing\n");
		fclose(f);
		return;
	}

	unsigned int i=0;
	fgets(parsed [i].data[0],1023,f);
  
	 while(parsed [i].data[0][0]=='#'){

 		fgets(parsed [i].data[1],1023,f);
 		fgets(parsed [i].data[2],1023,f);
 		fgets(parsed [i].data[3],1023,f);
 		fgets(parsed [i].data[4],1023,f);

   	 	i++;

 		fgets(parsed [i].data[0],1023,f);
 
	}

//convert to entries
	
	entry_t* entries=malloc(i*sizeof(entry_t));
	
	int j;
	int k;
	for(j=0;j<i;j++){
			for(k=1;k<=4;k++){
	    		parsed[j].data[k][ strlen(parsed[j].data[k]) - 1 ] = '\0';  //suppress \n character
	     }
	     
		entries->name= parsed [j].data[1];
		entries->surname=	parsed [j].data[2];
		entries->tel=	parsed [j].data[3];
		entries->address=	parsed [j].data[4];
						
		hash_table_insert(table,entries);
		entries++;
	}

	fclose(f);

}

size_t length(char* chaine){
	size_t i=0;
	while(true){
		if(chaine[i]=='\0') break;
		else i++;
	}
	return i;
	
}

void write() { //will take a hashmap or a list as parameter
  
FILE* f = fopen("repertory.txt","w");


 //char buffer[buffer_size];

 char* buffer1= "#\nPA\nDURAND\n0643539442\nToulouse\n\0";
 char* buffer2= "#\nPA2\nDURAND2\n0123456789\nLyon\n\0";

 //printf("%s\n",buffer1);

 //fgets(buffer,256,stdin);
	
 fwrite(buffer1, sizeof(char), length(buffer1), f);
 fwrite(buffer2, sizeof(char), length(buffer2), f);

 fclose(f);

}
