#pragma once
#define _PARSER_H_

#include "hash_table.h"

typedef struct _parsed_entry{
    char data[5][1023];	   //0: check new entry, 1: name, 2: surname, 3: tel, 4: address
} parsed_entry;


void read(hash_table_t* table);
void write();
size_t length(char* chaine);





