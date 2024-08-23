#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int hash_function(const char *string);

int main(void)
{
    FILE fs;
    printf("Hello world!\n");
    return 0;
}
int hash_function(const char *string)
{
   int counter = 0;
   int temp = 0;
   int sum = 0;
   while(*(string + counter) != '\0')
   {
       switch(tolower(*(string + counter)))
       {
           case 'a': temp = 1;
           case 'b': temp = 2;
           case 'c': temp = 3;
           case 'd': temp = 5;
           case 'e': temp = 7;
           case 'f': temp = 11;
           case 'g': temp = 13;
           case 'h': temp = 17;
           case 'i': temp = 19;
           case 'j': temp = 23;
           case 'k': temp = 29;
           case 'l': temp = 31;
           case 'm': temp = 37;
           case 'n': temp = 41;
           case 'o': temp = 43;
           case 'p': temp = 47;
           case 'q': temp = 53;
           case 'r': temp = 59;
           case 's': temp = 61;
           case 't': temp = 67;
           case 'u': temp = 71;
           case 'v': temp = 73;
           case 'w': temp = 79;
           case 'x': temp = 83;
           case 'y': temp = 89;
           case 'z': temp = 97;

           #if 0
           case 'a': temp = 1;
           case 'b': temp = 3;
           case 'c': temp = 7;
           case 'd': temp = 13;
           case 'e': temp = 19;
           case 'f': temp = 29;
           case 'g': temp = 37;
           case 'h': temp = 43;
           case 'i': temp = 53;



           case 'A': temp = 2;
           case 'B': temp = 5;
           case 'C': temp = 11;
           case 'D': temp = 17;
           case 'E': temp = 23;
           case 'F': temp = 31;
           case 'G': temp = 41;
           case 'H': temp = 47;
           case 'I': temp = 59;
           #endif

           case '\'': temp = 101;
       }
       sum = sum + temp;
       counter++;
   }
   return sum;
}
