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


long long int hash_function(const char *string, long long int size_array);
long long int hash_function1(const char *string, long long int size_array);
long long int hash_function2(const char *string, long long int size_array);
long long int hash_function3(const char *string, long long int size_array);
long long int hash_function4(const char *string, long long int size_array);
long long int hash_function5(const char *string, long long int size_array);

#endif // HASH_FUNCTIONS_H_INCLUDED
