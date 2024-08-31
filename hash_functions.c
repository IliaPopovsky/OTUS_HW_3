#include <ctype.h>

long long int hash_function(const char *string, long long int size_array)
{
   int counter = 0;
   long long int temp = 0;
   long long int sum = 0;
   while(*(string + counter) != '\0')
   {
       switch(tolower(*(string + counter)))
       {
           case 'a': temp = 1;
                     break;
           case 'b': temp = 2;
                     break;
           case 'c': temp = 3;
                     break;
           case 'd': temp = 5;
                     break;
           case 'e': temp = 7;
                     break;
           case 'f': temp = 11;
                     break;
           case 'g': temp = 13;
                     break;
           case 'h': temp = 17;
                     break;
           case 'i': temp = 19;
                     break;
           case 'j': temp = 23;
                     break;
           case 'k': temp = 29;
                     break;
           case 'l': temp = 31;
                     break;
           case 'm': temp = 37;
                     break;
           case 'n': temp = 41;
                     break;
           case 'o': temp = 43;
                     break;
           case 'p': temp = 47;
                     break;
           case 'q': temp = 53;
                     break;
           case 'r': temp = 59;
                     break;
           case 's': temp = 61;
                     break;
           case 't': temp = 67;
                     break;
           case 'u': temp = 71;
                     break;
           case 'v': temp = 73;
                     break;
           case 'w': temp = 79;
                     break;
           case 'x': temp = 83;
                     break;
           case 'y': temp = 89;
                     break;
           case 'z': temp = 97;
                     break;
           case '\'': temp = 101;
                     break;
           case '-': temp = 103;
                     break;
       }
       sum = sum + temp;
       counter++;
   }
   sum = sum * 107;
   sum = sum % size_array;
   return sum;
}

long long int hash_function1(const char *string, long long int size_array)
{
   int counter = 0;
   long long int temp = 0;
   long long int sum = 0;
   while(*(string + counter) != '\0')
   {
       switch(tolower(*(string + counter)))
       {
           case 'a': temp = 1;
                     break;
           case 'b': temp = 3;
                     break;
           case 'c': temp = 7;
                     break;
           case 'd': temp = 13;
                     break;
           case 'e': temp = 19;
                     break;
           case 'f': temp = 29;
                     break;
           case 'g': temp = 37;
                     break;
           case 'h': temp = 43;
                     break;
           case 'i': temp = 53;
                     break;
           case 'j': temp = 61;
                     break;
           case 'k': temp = 71;
                     break;
           case 'l': temp = 79;
                     break;
           case 'm': temp = 89;
                     break;
           case 'n': temp = 101;
                     break;
           case 'o': temp = 107;
                     break;
           case 'p': temp = 113;
                     break;
           case 'q': temp = 131;
                     break;
           case 'r': temp = 139;
                     break;
           case 's': temp = 151;
                     break;
           case 't': temp = 163;
                     break;
           case 'u': temp = 173;
                     break;
           case 'v': temp = 181;
                     break;
           case 'w': temp = 193;
                     break;
           case 'x': temp = 199;
                     break;
           case 'y': temp = 223;
                     break;
           case 'z': temp = 229;
                     break;
           case '\'': temp = 239;
                     break;
           case '-': temp = 251;
                     break;
       }
       sum = sum + temp;
       counter++;
   }
   sum = sum * 263;
   sum = sum % size_array;
   return sum;
}

long long int hash_function2(const char *string, long long int size_array)
{
   int counter = 0;
   long long int temp = 0;
   long long int sum = 0;
   while(*(string + counter) != '\0')
   {
       switch(tolower(*(string + counter)))
       {
           case 'a': temp = 1;
                     break;
           case 'b': temp = 5;
                     break;
           case 'c': temp = 13;
                     break;
           case 'd': temp = 13;
                     break;
           case 'e': temp = 23;
                     break;
           case 'f': temp = 37;
                     break;
           case 'g': temp = 47;
                     break;
           case 'h': temp = 61;
                     break;
           case 'i': temp = 73;
                     break;
           case 'j': temp = 89;
                     break;
           case 'k': temp = 103;
                     break;
           case 'l': temp = 113;
                     break;
           case 'm': temp = 137;
                     break;
           case 'n': temp = 151;
                     break;
           case 'o': temp = 167;
                     break;
           case 'p': temp = 179;
                     break;
           case 'q': temp = 193;
                     break;
           case 'r': temp = 211;
                     break;
           case 's': temp = 229;
                     break;
           case 't': temp = 241;
                     break;
           case 'u': temp = 263;
                     break;
           case 'v': temp = 277;
                     break;
           case 'w': temp = 293;
                     break;
           case 'x': temp = 313;
                     break;
           case 'y': temp = 337;
                     break;
           case 'z': temp = 359;
                     break;
           case '\'': temp = 379;
                     break;
           case '-': temp = 397;
       }
       sum = sum + temp;
       counter++;
   }
   sum = sum * 419;
   sum = sum % size_array;
   return sum;
}

long long int hash_function3(const char *string, long long int size_array)
{
   int counter = 0;
   long long int sum = 0;
   while(*(string + counter) != '\0')
   {
       sum = sum + tolower(*(string + counter)) * pow(23, counter);
       counter++;
   }
   sum = sum % size_array;
   return sum;
}

long long int hash_function4(const char *string, long long int size_array)
{
   int counter = 0;
   long long int temp = 0;
   long long int sum = 0;
   while(*(string + counter) != '\0')
   {
       switch(tolower(*(string + counter)))
       {
           case 'a': temp = 1;
                     break;
           case 'b': temp = 5;
                     break;
           case 'c': temp = 7;
                     break;
           case 'd': temp = 11;
                     break;
           case 'e': temp = 13;
                     break;
           case 'f': temp = 23;
                     break;
           case 'g': temp = 29;
                     break;
           case 'h': temp = 31;
                     break;
           case 'i': temp = 37;
                     break;
           case 'j': temp = 47;
                     break;
           case 'k': temp = 53;
                     break;
           case 'l': temp = 59;
                     break;
           case 'm': temp = 61;
                     break;
           case 'n': temp = 73;
                     break;
           case 'o': temp = 79;
                     break;
           case 'p': temp = 83;
                     break;
           case 'q': temp = 89;
                     break;
           case 'r': temp = 103;
                     break;
           case 's': temp = 107;
                     break;
           case 't': temp = 109;
                     break;
           case 'u': temp = 113;
                     break;
           case 'v': temp = 137;
                     break;
           case 'w': temp = 139;
                     break;
           case 'x': temp = 149;
                     break;
           case 'y': temp = 151;
                     break;
           case 'z': temp = 167;
                     break;
           case '\'': temp = 179;
                     break;
           case '-': temp = 193;
                     break;
       }
       sum = sum + temp;
       counter++;
   }
   sum = sum * 211;
   sum = sum % size_array;
   return sum;
}

long long int hash_function5(const char *string, long long int size_array)
{
   int counter = 0;
   long long int sum = 0;
   while(*(string + counter) != '\0')
   {
       sum = sum + *(string + counter);
       counter++;
   }
   sum = sum * sum;
   sum = sum % size_array;
   return sum;
}




