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


       }
       sum = sum + temp;
       counter++;
   }
   return sum;
}
