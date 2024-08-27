#ifndef HASH_FUNCTIONS_H_INCLUDED
#define HASH_FUNCTIONS_H_INCLUDED

#define WORDLEN 25

typedef struct item{
   char word[WORDLEN];
   int quantity;
} Item;


typedef struct HTnode{
   Item item;
} HTnode;


int hash_function(const char *string, int size_array);
int hash_function1(const char *string, int size_array);

#endif // HASH_FUNCTIONS_H_INCLUDED
