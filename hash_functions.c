//#include <ctype.h>
int hash_function(const char *string, int size_array)
{
   int counter = 0;
   int temp = 0;
   int sum = 0;
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
       }
       sum = sum + temp;
       counter++;
   }
   sum = sum * 103;
   sum = sum % size_array;
   return sum;
}

int hash_function1(const char *string, int size_array)
{
   int counter = 0;
   int temp = 0;
   int sum = 0;
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
       }
       sum = sum + temp;
       counter++;
   }
   return sum;
}
