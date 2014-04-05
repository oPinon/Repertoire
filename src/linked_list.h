#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdbool.h>
#include "listentry.h"

// A linked list cell.
struct cell
{
  // The stored value.
  entry_t* value;

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

// Apply a function pointer, which takes an int as a parameter and returns
// nothing.
void apply(list_t list, void (*fun)(entry_t*));

#endif // _LINKED_LIST_H_
