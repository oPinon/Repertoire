#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "parser.h"
#include "hash_table.h"

int main(int argc, const char* argv[])
{
	printf("Welcome to NoteWorks\n********\n");
	printf("Loading repertory.txt ...\n");
	
	hash_table_t* table = hash_table_init(100);
	write();
	read(table);
	
	
	if(table==NULL){
		printf("Cannot read repertory.txt\nClosing...");
		return -1;
	}
    printf("Done\n");
    
    bool running = true;
    
    while(running){
    
		printf("\nMAIN MENU\n");
		printf("Choose an option\n");
    
		printf("(1): save & quit\n");
		printf("(2): add entry\n");
		printf("(3): erase entry\n");
		printf("(4): look for entry\n");
		printf("(5): modify entry\n");
		printf("(6): display all entries\n");
		printf("\n>");
		

        char selection[10];
        fgets(selection,sizeof(selection)+1,stdin);
        
        int choice = atol(selection);
        if(choice>9) choice=9;

  	 	switch(choice){
   			
   			case 1: {
   				write();
   				 printf("Exiting with save\n");
   				running = false;	
   			} break;
   		
   		    case 2: {
   			      parsed_entry* parsed = malloc(sizeof(parsed_entry));
   			      
   			      printf("Please enter entry name:\n");
   			   	 fgets(parsed->data[1],1023,stdin);
   			   	 	parsed->data[1][ strlen(parsed->data[1]) - 1 ] = '\0';
   			    if(length(parsed->data[1])==0){
   			      			printf("Name cannot be empty\n");
   			      			free(parsed);
   			      			break;
				}
   			    
   			    
 				 printf("Please enter entry surname:\n");
   			   	 fgets(parsed->data[2],1023,stdin);
   			   	 	parsed->data[2][ strlen(parsed->data[2]) - 1 ] = '\0';
   			    if(length(parsed->data[2])==0){
   			      			printf("Surname cannot be empty\n");
   			      				free(parsed);
   			      			break;
				}
				
				if( hash_table_find_by_name(table, parsed->data[1]) == true && hash_table_find_by_surname(table, parsed->data[2]) == true  ){
						printf("This name/surname combo already exists\n");
   			      				free(parsed);
   			      				break;
				}
				
				
				printf("Please enter entry phone number:\n");
 						fgets(parsed->data[3],1023,stdin);
 					parsed->data[3][ strlen(parsed->data[3]) - 1 ] = '\0';
 						
 				printf("Please enter entry address:\n");
 						fgets(parsed->data[4],1023,stdin);
 					parsed->data[4][ strlen(parsed->data[4]) - 1 ] = '\0';
   			      
   			      
   			      
   			    entry_t* entry=malloc(sizeof(entry_t));
	     
				entry->name= parsed->data[1];
				entry->surname=	parsed->data[2];
				entry->tel=	parsed->data[3];
				entry->address=	parsed->data[4];
						
				hash_table_insert(table,entry);
                
   			} break;
   		
   		
   		   	case 3: {
   			        parsed_entry* parsed = malloc(sizeof(parsed_entry));
   			      
   			      printf("Please enter name to erase:\n");
   			   	  fgets(parsed->data[1],1023,stdin);
   			      if(length(parsed->data[1])==0){
   			      			printf("Name cannot be empty\n");
   			      			free(parsed);
   			      			break;
			   	}
   			    
   			    //computing

   			      
   			} break;
   			
   			
   			case 4: {
   			      parsed_entry* entry_p = malloc(sizeof(parsed_entry));
   			      
   			      printf("Please enter name to search:\n");
   			   	 fgets(entry_p->data[1],1023,stdin);
   			    if(length(entry_p->data[1])==0){
   			      			printf("Name cannot be empty\n");
   			      			free(entry_p);
   			      			break;
				}
   			    
   			    //computing

   			      
   			} break;
   			
   			
   		     case 5: {
   			      parsed_entry* entry_p = malloc(sizeof(parsed_entry));
   			      
   			      printf("Please enter entry name to change:\n");
   			   	 fgets(entry_p->data[1],1023,stdin);
   			    if(length(entry_p->data[1])==0){
   			      			printf("Name cannot be empty\n");
   			      			free(entry_p);
   			      			break;
				}
   			    
   			    //computing

   			      
   			} break;
   			
   		     case 6: hash_table_print(table); break;

   			default: printf("Invalid selection\n"); break;
   		
   		
  	 	}
  	}
     
    hash_table_destroy(table);
	return 0;
}
