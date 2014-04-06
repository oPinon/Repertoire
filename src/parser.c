#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "linked_list.h"
#include "parser.h"


list_t read() {
  
	FILE* f = fopen("repertory.txt","r");

	parsed_entry* entries = malloc(500*sizeof(parsed_entry));
	if(entries==NULL){
		printf("Could not allow memory for parsing\n");
		return NULL;
	}

	unsigned int i=0;
	fgets(entries[i].data[0],1023,f);
  
	 while(entries[i].data[0][0]=='#'){

 		fgets(entries[i].data[1],1023,f);
 		fgets(entries[i].data[2],1023,f);
 		fgets(entries[i].data[3],1023,f);
 		fgets(entries[i].data[4],1023,f);

   	 	i++;

 		fgets(entries[i].data[0],1023,f);
 
	}

//convert to list
	list_t people= init_list();  
	
	int j;
	for(j=0;j<i;j++){
		entry_t entry = {entries[j].data[1],
						entries[j].data[2],
						entries[j].data[3],
						entries[j].data[4]};
						
		push_front(&people,entry);
	}

	fclose(f);

	return people;
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
