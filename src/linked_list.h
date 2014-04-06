#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listentry.h"


typedef struct _entry_t {
	char* name;
	char* surname;
	char* tel;
	char* address;
} entry_t;

// A linked list cell.
struct cell
{
  // The stored value.
<<<<<<< HEAD
  entry_t value;
=======
  entry_t* value;
>>>>>>> 9dabe3d649aa78eab56617c92af5468b6cd99c2f

  // The next cell.
  struct cell* next;
};

// A linked list.
typedef struct cell* list_t;

// Create a new linked list.
list_t init_list();

// Erase a list.
void destroy_list(list_t list);

// Compute the size of a list.
size_t size(list_t list);

// Push a new value in front of the list.
<<<<<<< HEAD
int push_front(list_t* list, entry_t value);

// Remove the first value, and put it at the address pointed by value_ptr.
int pop_front(list_t* list, entry_t* value_ptr);

// Push a new value at the end of the list.
int push_back(list_t* list, entry_t value);

// Remove the last value, and put it at the address pointed by value_ptr.
int pop_back(list_t* list, entry_t* value_ptr);

// Erase the given value.
int erase(list_t*, entry_t value);

// Find a value.
bool find(list_t, entry_t value);

// Apply a function pointer, which takes an int as a parameter and returns
// nothing.
void apply(list_t list, void (*fun)(entry_t));

// Print the list.
void print(list_t list);
=======
int push_front(list_t* list, entry_t* value);

// Remove the first value, and put it at the address pointed by value_ptr.
int pop_front(list_t* list, entry_t** value_ptr);

// Push a new value at the end of the list.
int push_back(list_t* list, entry_t* value);

// Remove the last value, and put it at the address pointed by value_ptr.
int pop_back(list_t* list, entry_t** value_ptr);

// Erase the given value.
int erase(list_t*, entry_t* value);

// Find a value.
bool find(list_t, entry_t* value);
bool find_by_name(list_t, unsigned char* value);
bool find_by_surname(list_t, unsigned char* value);

// Apply a function pointer, which takes an int as a parameter and returns
// nothing.
void apply(list_t list, void (*fun)(entry_t*));
>>>>>>> 9dabe3d649aa78eab56617c92af5468b6cd99c2f

#endif // _LINKED_LIST_H_
