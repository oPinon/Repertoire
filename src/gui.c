#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "parser.h"
#include "hash_table.h"

void save(hash_table_t* table, const char* filename){
	printf("Saving %s...\n",filename);
   	write(table,filename);
   	printf("Done\n");
	
}

void quit_menu(hash_table_t* table, const char* filename){
	char buffer[1024];
   				  	 	  				  	
   	printf("Do you want to save before leaving? y/n\n");
   	printf("\n>>");
   				
   	fgets(buffer,sizeof(buffer),stdin);
   	while(buffer[0]!='y' && buffer[0]!='n'){
   		printf("\n>>");
		fgets(buffer,sizeof(buffer),stdin);
    }
   			      	
	if(buffer[0]=='y')	save(table, filename);
	else printf("Quitting without save\n");	
   				
   	printf("\nSee you soon!\n");	
	
}

bool has_combination(hash_table_t* table, char* name, char* surname){
	list_t check = hash_table_find_by_surname(table, surname);

	bool result = false;
	if(has_name(check,name)) result = true; 	
	
	destroy_list(check);
	
	return result;
	
}

int add_entry(hash_table_t* table){
	entry_t* entry = init_entry();
   			      
	printf("Please enter entry first name:\n");
   	printf("\n>>");
   	fgets(entry->name,1024,stdin);
   	entry->name[ strlen(entry->name) - 1 ] = '\0';
   			   	
    while(strlen(entry->name)==0){
   		printf("First name cannot be empty\n");
   		printf("\n>>");
   		fgets(entry->name,1024,stdin);
   		entry->name[ strlen(entry->name) - 1 ] = '\0';
   	}
   			    
   			    
   	printf("Please enter entry last name:\n");
   	printf("\n>>");
   	fgets(entry->surname,1024,stdin);
	entry->surname[ strlen(entry->surname) - 1 ] = '\0';
   			   	
    while(strlen(entry->surname)==0){
   		printf("Last name cannot be empty\n");
   		printf("\n>>");
   		fgets(entry->surname,1024,stdin);
   		entry->surname[ strlen(entry->surname) - 1 ] = '\0';
   	}
				
	if( has_combination(table, entry->name, entry->surname) ){
		printf("This name/surname combination already exists\n");
		destroy_entry(entry);
		return -1;
	}
				
				
	printf("Please enter entry phone number:\n");
	printf("\n>>");
 	fgets(entry->tel,1024,stdin);
 	entry->tel[ strlen(entry->tel) - 1 ] = '\0';
 						
 	printf("Please enter entry address:\n");
 	printf("\n>>");
 	fgets(entry->address,1024,stdin);
 	entry->address[ strlen(entry->address) - 1 ] = '\0';
   			      
	hash_table_insert(table,entry);
	
	return 0;
	
}

int erase_entry(hash_table_t* table, entry_t* entry_p){
	char buffer[1024];
	
	printf("You are going to delete:\n");
   	print_entry(entry_p);
   	printf("Are you sure? y/n\n");
  	printf("\n>>");
   			      	
	fgets(buffer,sizeof(buffer),stdin);
   	while(buffer[0]!='y' && buffer[0]!='n'){
   		printf("\n>>");
		fgets(buffer,sizeof(buffer),stdin);		      				   				
   	}
   			      	
	if(buffer[0]=='y'){
   		hash_table_remove(table, entry_p);
   		printf("Entry removed\n");
   		return 0;
   	} else {
   		printf("Erase cancelled\n");
		return 1;
	}
	
}

int change_name(hash_table_t* table, entry_t* entry_p){
	char buffer[1024];
  	printf("Please enter the new first name:\n");
	printf("\n>>");
   	fgets(buffer,sizeof(buffer),stdin);
	buffer[ strlen(buffer) - 1 ] = '\0';
   			      
    	while(strlen(buffer)==0){
   		printf("First name cannot be empty\n");
   		printf("\n>>");
		fgets(buffer,sizeof(buffer),stdin);
   		buffer[ strlen(buffer) - 1 ] = '\0';
   	}
   	
   	if( has_combination(table, buffer, entry_p->surname) ){
		printf("This name/surname combination already exists\n");
		return -1;
	}
				
	entry_p->name = strcpy(entry_p->name,buffer);
	printf("The entry is now:\n");
   	print_entry(entry_p);	
   	
   	return 0;
	
}

int change_surname(hash_table_t* table, entry_t* entry_p){
  	char buffer[1024];
  	printf("Please enter the new last name:\n");
	printf("\n>>");
   	fgets(buffer,sizeof(buffer),stdin);
   	buffer[ strlen(buffer) - 1 ] = '\0';
   			      
   	while(strlen(buffer)==0){
		printf("Last name cannot be empty\n");
   		printf("\n>>");
   		fgets(buffer,sizeof(buffer),stdin);
   		buffer[ strlen(buffer) - 1 ] = '\0';
   	}
   	
   	if( has_combination(table, entry_p->name, buffer) ){
		printf("This name/surname combination already exists\n");
		return -1;
	}
				
	entry_p->surname = strcpy(entry_p->surname,buffer);
	printf("The entry is now:\n");
	print_entry(entry_p);
	
	return 0;
		
}

int change_tel(entry_t* entry_p){
	char buffer[1024];
	printf("Please enter the new phone number:\n");
  	printf("\n>>");
   	fgets(buffer,sizeof(buffer),stdin);
	buffer[ strlen(buffer) - 1 ] = '\0';
					
	entry_p->tel = strcpy(entry_p->tel,buffer);
	printf("The entry is now:\n");
   	print_entry(entry_p);	
	   
	return 0;							
	
}

int change_address(entry_t* entry_p){
  	char buffer[1024];
  	printf("Please enter the new address:\n");
  	printf("\n>>");
   	fgets(buffer,sizeof(buffer),stdin);
	buffer[ strlen(buffer) - 1 ] = '\0';

	entry_p->address = strcpy(entry_p->address,buffer);
	printf("The entry is now:\n");
   	print_entry(entry_p);	
	   
	return 0;	
				 	    			
}

void modify_menu(hash_table_t* table, entry_t* entry_p){    									 
	bool modifying = true;
	char buffer[1024];
				
	while(modifying){ 
		printf("\nSelect an option:\n");
      	printf("(1): Modify entry first name\n");
      	printf("(2): Modify entry last name\n");
      	printf("(3): Modify entry phone number\n");
      	printf("(4): Modify entry address\n");
		printf("(5): Erase entry\n");
		printf("(6): Return to main menu\n");
		printf("\n>>");
      				
   		fgets(buffer, sizeof(buffer)+1, stdin);
       	int modify_choice = atol(buffer);
      	if(modify_choice>9) modify_choice=9; 	
					  
		switch(modify_choice){
						
    	 	case 1: change_name(table, entry_p); break;
  	 		case 2: change_surname(table, entry_p); break;
  	 	  	case 3: change_tel(entry_p); break;
  	 	  	case 4: change_address(entry_p); break;	 	
  	 	   	case 5: {
  	 	   		int e = erase_entry(table, entry_p);
  	 	   		if(e == 0) modifying = false;
  	 	   	} break;		 	
  	 	   	case 6: modifying = false; break;	 	   			 	
  	 	   	default: printf("Invalid selection\n"); break;  
												
		}			
	
	
	}
	
}

list_t search_entries(hash_table_t* table, int choice){
   
    list_t check = init_list();
    char buffer[1024];
      			 
    switch(choice){
      					
      	case 1: {
			printf("Please enter entry first name:\n");
			printf("\n>>");
			fgets(buffer,sizeof(buffer),stdin);
   			buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     		while(strlen(buffer)==0){
   			    printf("First name cannot be empty\n");
   			    printf("\n>>");
   			    fgets(buffer,sizeof(buffer),stdin);
   			    buffer[ strlen(buffer) - 1 ] = '\0';
   			}
      					
      		check = hash_table_find_by_name(table, buffer);	
			if(size(check)==0) printf("No such first name found\n");
   							
      	} break;
      				
      	case 2: {
			printf("Please enter entry last name:\n");
			printf("\n>>");
			fgets(buffer,sizeof(buffer),stdin);
   			buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     		while(strlen(buffer)==0){
   			    printf("Last name cannot be empty\n");
   			    printf("\n>>");
   			    fgets(buffer,sizeof(buffer),stdin);
   			    buffer[ strlen(buffer) - 1 ] = '\0';
   			}	
      					
      		check = hash_table_find_by_surname(table, buffer);	
			if(size(check)==0) printf("No such last name found\n");
   			   		
   			  		 				
      	} break;
      				
      	default: {
      		printf("Invalid selection\n"); 
			check=NULL; 
      	} break;

	}	 
				
	return check;
	
}


int run(const char* argv[])
{
	printf("Welcome to NoteWorks !\n********\n");
	printf("This software allows you to store and modify a repertory\n");
	
	const char* filename = argv[1];
	if(filename==NULL){
		printf("Please enter repertory file name in the command line\nClosing...");
		return -1;
	}
	
	printf("Loading %s...\n",filename);
	
	hash_table_t* table = hash_table_init(100);	
	if(table==NULL){
		printf("Cannot read %s\nClosing...",filename);
		return -1;
	}
 
  	read(table,filename);  
  	printf("Done\n");
	
  	bool running = true; 
	char buffer[1024];
    
	while(running){
    
		printf("\nMAIN MENU\n");
		printf("Please enter a number to continue :\n");
    
		printf("(1): Display all\n");
		printf("(2): Search-Modify-Erase\n");
		printf("(3): Add\n");
		printf("(4): Save\n");
		printf("(5): Quit\n");
		printf("\n>>");
		

       	fgets(buffer, sizeof(buffer), stdin);      
       	int choice = atol(buffer);
        if(choice>9) choice=9;

  	 	switch(choice){
  	 		
			case 1: hash_table_print(table); break;
			
			case 2: {
				printf("\nEnter search criteria:\n");
				printf("(1): Search by first name\n");
				printf("(2): Search by last name\n");
				printf("\n>>");
   				
   				
   				fgets(buffer, sizeof(buffer)+1, stdin);       
       			int choice = atol(buffer);
      			if(choice>9) choice=9;
      			
 				list_t check = search_entries (table, choice);
				
				if(check==NULL || size(check)==0){
					destroy_list(check);
  					break;
				}
				
				printf("The following entries were found:\n");		
				print_list_with_index(check);
				
				printf("Which one do you wish to interact with (0 is first)?\n");
				printf("\n>>");	
				
				fgets(buffer, sizeof(buffer)+1, stdin);      
       			int interact_choice = atol(buffer);
       			
       			entry_t* entry_p = get(check,interact_choice);
       			destroy_list(check);
       			
       			if(entry_p==NULL){
       				printf("Invalid selection\n");				    
					break;	
       			}
				   		
       			printf("You are going to modify:\n");
				print_entry(entry_p);

 				modify_menu(table, entry_p);
																		      							  		    				
      		} break;
      		
			
			case 3: add_entry(table); break;     	
    		case 4: save(table, filename); break;	
   			case 5: {
   				quit_menu(table, filename);
				running = false;
   			} break;
      			 
   			default: printf("Invalid selection\n"); break;   		
  	 	}
  	}
     
    hash_table_destroy(table);
	return 0;
}
