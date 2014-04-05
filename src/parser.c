#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

list_t read() {
  
FILE* f = fopen("repertory.txt","r");

 char* buffer= malloc(1023*sizeof(char));

 size_t i=0;
 fgets(buffer,8,f);
  printf("Check: %s\n",buffer);
 while(buffer[0]=='#'){
 	fgets(buffer,1023,f);
 	printf("Name: %s\n",buffer);
 	fgets(buffer,1023,f);
 	printf("Surname: %s\n",buffer);
 	fgets(buffer,1023,f);
 	printf("Tel: %s\n",buffer);
 	fgets(buffer,1023,f);
 	printf("Address: %s\n",buffer);
 	fgets(buffer,8,f);
}
    
	free(buffer);
	buffer=NULL;
 

 fclose(f);

  return NULL;
}

size_t length(char* chaine){
	size_t i=0;
	while(true){
		if(chaine[i]=='\0') break;
		else i++;
	}
	return i;
	
}

void write() {
  
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

int main(int argc, const char* argv[])
{
	write();
	read();

	return 0;
}
