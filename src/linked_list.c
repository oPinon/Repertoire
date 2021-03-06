#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// Create a new linked list.
list_t init_list()
{
  // An empty list is just a NULL pointer.
  return NULL;
}

// Erase a list and its elements.
void destroy_list_elements(list_t list)
{
  list_t current = list;
  while (current != NULL)
  {
    list_t to_erase = current;
    current = current->next;
	destroy_entry(to_erase->value);
    free(to_erase);
  }
}

// Erase a list but not its elements
void destroy_list(list_t list)
{
  list_t current = list;
  while (current != NULL)
  {
    list_t to_erase = current;
    current = current->next;
    free(to_erase);
  }
}

// Compute the size of a list.
size_t size(list_t list)
{
  size_t res = 0;
  if (list != NULL)
  {
    while (list != NULL)
    {
      ++res;
      list = list->next;
    }
  }
  return res;
}

// Find a value
bool find(list_t list, entry_t* value)
{
	
    while (list != NULL)
    {
      if(list->value == value) { return true; }
      list = list->next;
    }

  return false;
}

bool has_name(list_t list, char* name){

    while (list != NULL)
    {
      if(eq_str(list->value->name , name)) { return true; }
      list = list->next;
    }
  
  return false;
	
}

bool has_surname(list_t list, char* surname){

    while (list != NULL)
    {
      if(eq_str(list->value->surname , surname)) { return true; }
      list = list->next;
    }
  
  return false;
	
}


list_t find_by_name(list_t list, char* value) {
	
  list_t toReturn = init_list();

    while (list != NULL)
    {
      if( eq_str(list->value->name, value)) {
        push_front(&toReturn,list->value);
      }
      list = list->next;
    }
  
  return toReturn;
}

list_t find_by_surname(list_t list, char* value) {
	list_t toReturn = init_list();

    while (list != NULL)
    {
      if( eq_str(list->value->surname, value)) {
        push_front(&toReturn,list->value);
      }
      list = list->next;
    }
  
  return toReturn;
}

// Push a new value in front of the list.
int push_front(list_t* list, entry_t* value)
{
  // Allocate a new head.
  list_t new_head = malloc(sizeof(struct cell));

  // Did the memory allocation succeeded?
  if (new_head != NULL)
  {
    // Set the head's content.
    new_head->value = value;
    new_head->next = *list;

    // Change the list's head.
    *list = new_head;

    // Everything is OK.
    return 0;
  }
  else
  {
    // Error, could not allocate.
    return -1;
  }
}

// Remove the first value, and put it at the address pointed by value_ptr.
int pop_front(list_t* list, entry_t** value_ptr)
{
  if (*list != NULL)
  {
    // Copy the value stored in the old head.
    *value_ptr = (*list)->value;

    // We need to keep the old head, in order to erase it.
    list_t to_erase = *list;

    // Change the list's head.
    *list = (*list)->next;

    // Erase old head.
		free(to_erase->value);
    free(to_erase);

    // Everything is OK.
    return 0;
  }
  else
  {
    // It's an error to pop the first value of an empty list.
    return -1;
  }
}

// Push a new value at the end of the list.
int push_back(list_t* list, entry_t* value)
{
  // The list is empty, push_front will do the work nicely.
  if (*list == NULL)
  {
    return push_front(list, value);
  }

  // Allocate a new queue.
  list_t new_queue = malloc(sizeof(struct cell));

  // Did the memory allocation succeeded?
  if (new_queue != NULL)
  {
    // Loop until we found the last cell.
    list_t current = *list;
    while (current->next != NULL)
    {
      current = current->next;
    }

    // Set the new queue.
    current->next = new_queue;
    current->next->value = value;
    current->next->next = NULL;

    // Everything is OK.
    return 0;
  }
  else
  {
    // Error, could not allocate.
    return -1;
  }
}


void append(list_t* l1, list_t* l2) {
  if(*l1 == NULL) { *l1=*l2; }
  else {
    list_t current = *l1;
    while (current->next != NULL)
    {
      current = current->next;
    
    }
    current->next = *l2;
  }
}

// Remove the last value, and put it at the address pointed by value_ptr.
int pop_back(list_t* list, entry_t** value_ptr)
{
  if (*list != NULL)
  {
    // Loop until we found the last cell.
    list_t previous = NULL;
    list_t current = *list;
    while (current->next != NULL)
    {
      previous = current;
      current = current->next;
    }

    // Copy the value of the last cell.
    *value_ptr = current->value;

    // Erase the last cell.
    free(current);

    // previous could be NULL if the list had only 1 element.
    if (previous == NULL)
    {
      *list = NULL;
    }
    else
    {
      previous->next = NULL;
    }

    // Everything is OK.
    return 0;
  }
  else
  {
    // It's an error to pop the first value of an empty list.
    return -1;
  }
}

int erase(list_t* list, entry_t* value)
{
  if (*list != NULL)
  {
    // Loop until we found the last cell.
    list_t previous = NULL;
    list_t current = *list;
    while (current != NULL && current->value != value)
    {
      previous = current;
      current = current->next;
    }

    // End of list, value not found.
    if (current == NULL)
    {
      return -1;
    }

    // Remove first element.
    if (previous == NULL)
    {
      *list = current->next;
    }
    else
    {
      previous->next = current->next;
    }

    // Erase the last cell.
    destroy_entry(current->value);
    free(current);
    
    // Everything is OK.
    return 0;
  }
  else
  {
    // It's an error to pop the first value of an empty list.
    return -1;
  }
}

// Apply a function pointer, whose name is 'fun', which takes an entry pointer as a parameter and returns
// nothing.
void apply(list_t list, void (*fun)(entry_t*))
{
  while (list != NULL)
  {
    // Apply the 'fun' function to the current cell's value.
    (*fun)(list->value);
    list = list->next;
  }
}

void print_list(list_t list) {
	apply(list, &print_entry);
}

void print_list_with_index(list_t list) {
  unsigned long index = 0;
  while (list != NULL) {
    printf("%lu -> ",index);
    print_entry(list->value);
    index++;
    list = list->next;
  }
}


entry_t* get(list_t list, unsigned int value){
	if(value >= size(list)) return NULL;
	entry_t* result = list->value;
	
	for(unsigned int i=0; i<value; i++){
		 list = list->next;
		 result = list->value;
	}
	
	return result;  
}
