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
		printf("(3): erase entry by name\n");
		printf("(4): erase entry by surname\n");
		printf("(5): look for entry\n");
		printf("(6): modify entry by name\n");
		printf("(7): modify entry by surname\n");
		printf("(8): display all entries\n");
		printf("\n>");
		

        char selection[10];
        fgets(selection,sizeof(selection)+1,stdin);
        
        int choice = atol(selection);
        if(choice>9) choice=9;

  	 	switch(choice){
   			
   			case 1: {
   				write(table);
   				printf("Exiting with save\n");
   				running = false;	
   			} break;
   		
   		    case 2: {
   			    entry_t* entry = init_entry();
   			      
   			      printf("Please enter entry name:\n");
   			   	 fgets(entry->name,1023,stdin);
   			   	 	entry->name[ strlen(entry->name) - 1 ] = '\0';
   			    if(strlen(entry->name)==0){
   			      			printf("Name cannot be empty\n");
   			      			free(entry);
   			      			break;
				}
   			    
   			    
   			      printf("Please enter entry surname:\n");
   			   	 fgets(entry->surname,1023,stdin);
   			   	 	entry->surname[ strlen(entry->surname) - 1 ] = '\0';
   			    if(strlen(entry->surname)==0){
   			      			printf("Name cannot be empty\n");
   			      			free(entry);
   			      			break;
				}
				
				list_t check = hash_table_find_by_surname(table, entry->surname);

				if(has_name(check,entry->name)){
						printf("This name/surname combo already exists\n");
						free(entry);
						break; 
				}
				
				
				printf("Please enter entry phone number:\n");
 						fgets(entry->tel,1023,stdin);
 					entry->tel[ strlen(entry->tel) - 1 ] = '\0';
 						
 				printf("Please enter entry address:\n");
 						fgets(entry->address,1023,stdin);
 					entry->address[ strlen(entry->address) - 1 ] = '\0';
   			      
   			      
				hash_table_insert(table,entry);
                
   			} break;
   		
   		
   		   	case 3: {
   			        char buffer[1023];
   			      
   			      printf("Please enter entry name to erase:\n");
   			      	 fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			    if(strlen(buffer)==0){
   			      			printf("Name cannot be empty\n");
   			      			break;
				}			      
   			      
   			   	list_t check = hash_table_find_by_name(table, buffer);

   			   	if(size(check)==0){
   			   		printf("No such name found\n");
   			   		break;
   			   	}
   			   	printf("The following entries were found:\n");
   			   	 print_list(check)	;
                
   			    	printf("Type the surname of the one you wish to remove:\n");
   			    fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      check = find_by_surname(check, buffer);
   			      
   			    if(size(check)==0){
   			   		printf("No such surname found\n");
   			   		break;
   			   	}
   			   	
   			   		printf("You are going to delete:\n");
   			      	print_entry(check->value);
   			      	printf("Are you sure? y/n\n");
   			      	
   			      	fgets(buffer,1023,stdin);
   			      	while(buffer[0]!='y' && buffer[0]!='n'){
   			      			fgets(buffer,1023,stdin);
   			      	}
   			      	
   			      	if(buffer[0]=='y'){
   			      		hash_table_remove(table, check->value);
   			      		printf("Entry removed\n");
   			      	} else printf("Erase cancelled\n");

   			      
   			} break;
   			
   			
   			case 4: {
   			        char buffer[1023];
   			      
   			      printf("Please enter entry surname to erase:\n");
   			      	 fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			    if(strlen(buffer)==0){
   			      			printf("Surame cannot be empty\n");
   			      			break;
				}			      
   			      
   			   	list_t check = hash_table_find_by_surname(table, buffer);

   			   	if(size(check)==0){
   			   		printf("No such surname found\n");
   			   		break;
   			   	}
   			   	printf("The following entries were found:\n");
   			   	 print_list(check)	;
                
   			    	printf("Type the name of the one you wish to remove:\n");
   			    fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      check = find_by_name(check, buffer);
   			      
   			    if(size(check)==0){
   			   		printf("No such name found\n");
   			   		break;
   			   	}
   			   	
   			   		printf("You are going to delete:\n");
   			      	print_entry(check->value);
   			      	printf("Are you sure? y/n\n");
   			      	
   			      	fgets(buffer,1023,stdin);
   			      	while(buffer[0]!='y' && buffer[0]!='n'){
   			      			fgets(buffer,1023,stdin);
   			      	}
   			      	
   			      	if(buffer[0]=='y'){
   			      		hash_table_remove(table, check->value);
   			      		printf("Entry removed\n");
   			      	} else printf("Erase cancelled\n");

   			      
   			} break;
   			
   			
   		     case 5: {
   				char buffer[1023];
   			      
   			      printf("Please enter entry name or name to look for:\n");
   			      	 fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			if(strlen(buffer)==0){
   			      			printf("Name or surname cannot be empty\n");
   			      			break;
				}			      
   			      
   			   	list_t check1 = hash_table_find_by_name(table, buffer);
   			   	list_t check2 = hash_table_find_by_surname(table, buffer);
   			   	
   			   	append(&check1,&check2);

   			   	if(size(check1)==0){
   			   		printf("No such name or surname found\n");
   			   		break;
   			   	}
   			   	printf("The following entries were found:\n");
   			   	 print_list(check1);

   			      
   			} break;
   			
   			case 6: {
   			        char buffer[1023];
   			      
   			      printf("Please enter entry name to modify:\n");
   			      	 fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			    if(strlen(buffer)==0){
   			      			printf("Name cannot be empty\n");
   			      			break;
				}			      
   			      
   			   	list_t check = hash_table_find_by_name(table, buffer);

   			   	if(size(check)==0){
   			   		printf("No such name found\n");
   			   		break;
   			   	}
   			   	printf("The following entries were found:\n");
   			   	 print_list(check)	;
                
   			    	printf("Type the surname of the one you wish to modify:\n");
   			    fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      check = find_by_surname(check, buffer);
   			      
   			    if(size(check)==0){
   			   		printf("No such surname found\n");
   			   		break;
   			   	}
   			   	
   			   	 entry_t* entry_p = check->value;
   			   		printf("You are going to modify:\n");
   			      	print_entry(entry_p);
   			      	
   		   		 bool modifying = true;
    
           		 while(modifying){	
					      	
					printf("\nMODIFY MENU\n");
					printf("Choose an option\n");
		
  			  		printf("(1): quit modify\n");
					printf("(2): change name\n");
					printf("(3): change surname\n");
					printf("(4): change tel number\n");
					printf("(5): change address\n");
		
					printf("\n>");
		
					fgets(selection,sizeof(selection)+1,stdin);
        
     			   int choice = atol(selection);
     			   if(choice>9) choice=9;
		
	 		 		  switch(choice){
  	 	    			case 1: {
  	 	    				modifying = false;
  	 	    			}	break;
  	 	    	
  	 	    			case 2: {
  	 	    				  char buffer[1023];
  	 	    				printf("Please enter the new name:\n");
   			  		    	 fgets(buffer,1023,stdin);
   			   				   buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			  			  if(strlen(buffer)==0){
   			      					printf("Name cannot be empty\n");
   			      					break;
								}
				
							entry_p->name = strcpy(entry_p->name,buffer);
							printf("The entry is now:\n");
   			      			print_entry(entry_p);
					
  	 	    			}	break;
  	 	    	
  	 	  				  case 3: {
  	 	  				  	  char buffer[1023];
  	 	   					 	printf("Please enter the new surname:\n");
   			   				   	 fgets(buffer,1023,stdin);
   			   					   buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			  				  if(strlen(buffer)==0){
   			      						printf("Surname cannot be empty\n");
   			      						break;
									}
				
								entry_p->surname = strcpy(entry_p->surname,buffer);
								printf("The entry is now:\n");
   			      				print_entry(entry_p);

  	 			    	}	break;
  	 	    	
  	 	  				  case 4: {
  	 	  				  	  char buffer[1023];
  	 	    					printf("Please enter the new telephone number:\n");
   			    			  	 fgets(buffer,1023,stdin);
   			     				 buffer[ strlen(buffer) - 1 ] = '\0';
					
								entry_p->tel = strcpy(entry_p->tel,buffer);
								printf("The entry is now:\n");
   			   					 print_entry(entry_p);
								
  	 	    	
  	 	    				}	break;
  	 	    	
  	 	  				  case 5: {
  	 	  				  	  char buffer[1023];
  	 	    					printf("Please enter the new address:\n");
   			     			 	 fgets(buffer,1023,stdin);
   			     				 buffer[ strlen(buffer) - 1 ] = '\0';

								entry_p->address = strcpy(entry_p->address,buffer);
								printf("The entry is now:\n");
   			   				   	print_entry(entry_p);		
				
  	 	    			
  	 	   			 	}	break;
   			      
   						default: printf("Invalid selection\n"); break;
   			
   					} 
			     } 
			  } break;
			   
			  
   			
   			
    			case 7: {
   			        char buffer[1023];
   			      
   			      printf("Please enter entry surname to modify:\n");
   			      	 fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			    if(strlen(buffer)==0){
   			      			printf("Surname cannot be empty\n");
   			      			break;
				}			      
   			      
   			   	list_t check = hash_table_find_by_surname(table, buffer);

   			   	if(size(check)==0){
   			   		printf("No such surname found\n");
   			   		break;
   			   	}
   			   	printf("The following entries were found:\n");
   			   	 print_list(check)	;
                
   			    	printf("Type the name of the one you wish to modify:\n");
   			    fgets(buffer,1023,stdin);
   			      buffer[ strlen(buffer) - 1 ] = '\0';
   			      check = find_by_name(check, buffer);
   			      
   			    if(size(check)==0){
   			   		printf("No such name found\n");
   			   		break;
   			   	}
   			   	
   			   	 entry_t* entry_p = check->value;
   			   		printf("You are going to modify:\n");
   			      	print_entry(entry_p);
   			      	
   		   		 bool modifying = true;
    
           		 while(modifying){	
					      	
					printf("\nMODIFY MENU\n");
					printf("Choose an option\n");
		
  			  		printf("(1): quit modify\n");
					printf("(2): change name\n");
					printf("(3): change surname\n");
					printf("(4): change tel number\n");
					printf("(5): change address\n");
		
					printf("\n>");
		
					fgets(selection,sizeof(selection)+1,stdin);
        
     			   int choice = atol(selection);
     			   if(choice>9) choice=9;
		
	 		 		  switch(choice){
  	 	    			case 1: {
  	 	    				modifying = false;
  	 	    			}	break;
  	 	    	
    	 	    		case 2: {
  	 	    				  char buffer[1023];
  	 	    				printf("Please enter the new name:\n");
   			  		    	 fgets(buffer,1023,stdin);
   			   				   buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			  			  if(strlen(buffer)==0){
   			      					printf("Name cannot be empty\n");
   			      					break;
								}
				
							entry_p->name = strcpy(entry_p->name,buffer);
							printf("The entry is now:\n");
   			      			print_entry(entry_p);
					
  	 	    			}	break;
  	 	    	
  	 	  				  case 3: {
  	 	  				  	  char buffer[1023];
  	 	   					 	printf("Please enter the new surname:\n");
   			   				   	 fgets(buffer,1023,stdin);
   			   					   buffer[ strlen(buffer) - 1 ] = '\0';
   			      
     			  				  if(strlen(buffer)==0){
   			      						printf("Surname cannot be empty\n");
   			      						break;
									}
				
								entry_p->surname = strcpy(entry_p->surname,buffer);
								printf("The entry is now:\n");
   			      				print_entry(entry_p);

  	 			    	}	break;
  	 	    	
  	 	  				  case 4: {
  	 	  				  	  char buffer[1023];
  	 	    					printf("Please enter the new telephone number:\n");
   			    			  	 fgets(buffer,1023,stdin);
   			     				 buffer[ strlen(buffer) - 1 ] = '\0';
					
								entry_p->tel = strcpy(entry_p->tel,buffer);
								printf("The entry is now:\n");
   			   					 print_entry(entry_p);
								
  	 	    	
  	 	    				}	break;
  	 	    	
  	 	  				  case 5: {
  	 	  				  	  char buffer[1023];
  	 	    					printf("Please enter the new address:\n");
   			     			 	 fgets(buffer,1023,stdin);
   			     				 buffer[ strlen(buffer) - 1 ] = '\0';

								entry_p->address = strcpy(entry_p->address,buffer);
								printf("The entry is now:\n");
   			   				   	print_entry(entry_p);		
				
  	 	    			
  	 	   			 	}	break;
   			      
   						default: printf("Invalid selection\n"); break;
   			
   					} 
			     } 
			  } break;
   			
   		     case 8: hash_table_print(table); break;

   			default: printf("Invalid selection\n"); break;
   		
   		
  	 	}
  	}
     
    hash_table_destroy(table);
	return 0;
}
