#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"
#include "parser.h"

int main(int argc, const char* argv[])
{
	printf("Welcome to NoteWorks\n********\n");
	printf("Loading repertory.txt ...\n");
	write();
	list_t list = read();
	if(list==NULL){
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
   			      parsed_entry* entry_p = malloc(sizeof(parsed_entry));
   			      
   			      printf("Please enter entry name:\n");
   			   	 fgets(entry_p->data[1],1023,stdin);
   			    if(length(entry_p->data[1])==0){
   			      			printf("Name cannot be empty\n");
   			      			free(entry_p);
   			      			break;
				}
   			    
   			    
 				 printf("Please enter entry surname:\n");
   			   	 fgets(entry_p->data[2],1023,stdin);
   			    if(length(entry_p->data[2])==0){
   			      			printf("Surname cannot be empty\n");
   			      				free(entry_p);
   			      			break;
				}
				
				
				printf("Please enter entry phone number:\n");
 						fgets(entry_p->data[3],1023,stdin);
 						
 				printf("Please enter entry address:\n");
 						fgets(entry_p->data[4],1023,stdin);
   			      
                //add entry to hashmap here
   			      	free(entry_p);
   			} break;
   		
   		
   		   	case 3: {
   			      parsed_entry* entry_p = malloc(sizeof(parsed_entry));
   			      
   			      printf("Please enter name to erase:\n");
   			   	 fgets(entry_p->data[1],1023,stdin);
   			    if(length(entry_p->data[1])==0){
   			      			printf("Name cannot be empty\n");
   			      			free(entry_p);
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
   			
   		     case 6: print(list); break;

   			default: printf("Invalid selection\n"); break;
   		
   		
  	 	}
  	}
     
    destroy_list(list);
	return 0;
}
