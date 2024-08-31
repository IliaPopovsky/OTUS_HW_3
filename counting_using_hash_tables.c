#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hash_functions.h"
#define HASH_FUNCTION_NUMBER 3
#define ARRAY_MULTIPLIER 3

void word_cleaning(char *ptr);
double pow(double value, double power);

int main(int argc, char *argv[])
{
    int counter_words = 0;
    char read_word[WORDLEN];
    int sum_words = 0;
    FILE *fs;
    char read_char = 0;
    long long int size = 0;
    double coefficient_filling = 0.0;
    long long int index = 0;
    int counter_collision = 0;
    int counter_writes = 0;
    int flag_technical_information_output = 0;

    HTnode *pointer_htnode = NULL;
    HTnode *collision_words = NULL;
    if(argc != 2)
    {
       printf("Only %d arguments have been entered, but there should be 1\n", argc - 1);
       goto end;
    }

    if(argc == 2)
    {
        if((fs = fopen(argv[1], "rb")) == NULL )
        {
            fprintf(stderr, "Can't open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "Display technical information about hash table construction?\n");
        fprintf(stdout, "Enter 1 if YES or 2 (or any number other than 1) if NO:\n");
        fprintf(stdout, "1) YES\n");
        fprintf(stdout, "2) NO\n");
        fscanf(stdin, "%d", &flag_technical_information_output);
        while(getchar() != '\n')  // clearing the input buffer after a call fscanf()
            continue;

        while(fscanf(fs, "%s", read_word) != EOF)
        {
            if(isalnum(read_word[0]) || isalnum(read_word[1]))
                counter_words++;
            memset(read_word, 0, WORDLEN);
        }
        fprintf(stdout, "\nIn this text file of %d words.\n", counter_words);
        fseek(fs, 0L, SEEK_SET); // go to the beginning of the file

        size = counter_words * ARRAY_MULTIPLIER;
        if((pointer_htnode = (HTnode *)calloc(size, sizeof(HTnode))) == NULL)
        {
            fprintf(stdout, "There is not enough memory space to construct this hash table array, provided that the entire source text file is analyzed.\n"
                   "Consider analyzing the original text file in parts.\n");
            exit(1);
        }
        else
        {
            fprintf(stdout, "There is enough memory space to construct this hash table array, provided that the entire source text file is analyzed.\n");

        }
        if(flag_technical_information_output == 1)
        {
            if((collision_words = (HTnode *)calloc(size, sizeof(HTnode))) == NULL)
            {
               fprintf(stdout, "There is not enough memory space to build this array of collisions, provided that the entire source text file is analyzed.\n"
                   "Consider changing the size of the collision array.\n");
               exit(1);
            }
            else
            {
               fprintf(stdout, "There is enough memory space to build this array of collisions, provided that the entire source text file is analyzed.\n");

            }
        }
        printf("The size of the array allocated for our hash table is equal to the %lld elements.\n", size);
        if(flag_technical_information_output == 1)
            printf("Recorded hash table array indexes:\n");
        while(fscanf(fs, "%s", read_word) != EOF)
        {
            word_cleaning(read_word);
            if(HASH_FUNCTION_NUMBER == 0)
                index = hash_function(read_word, size);
            if(HASH_FUNCTION_NUMBER == 1)
                index = hash_function1(read_word, size);
            if(HASH_FUNCTION_NUMBER == 2)
                index = hash_function2(read_word, size);
            if(HASH_FUNCTION_NUMBER == 3)
                index = hash_function3(read_word, size);
            if(HASH_FUNCTION_NUMBER == 4)
                index = hash_function4(read_word, size);
            if(HASH_FUNCTION_NUMBER == 5)
                index = hash_function5(read_word, size);
            if(index < 0)
                index = -index;
            first_write:
            if(read_word[0] != '\0')  // it is necessary otherwise hyphens will be written replaced by '\0'
            {
               if((pointer_htnode + index)->item.word[0] == '\0')
               {
                  strcpy((pointer_htnode + index)->item.word, read_word);
                  (pointer_htnode + index)->item.quantity++;
                  counter_writes++;
                  coefficient_filling = (double)counter_writes / size;
                  if(flag_technical_information_output == 1)
                         printf("%lld ", index);
               }
               else
               {
                 if(strcmp((pointer_htnode + index)->item.word, read_word) == 0)
                    (pointer_htnode + index)->item.quantity++;
                 else
                 {
                    if(flag_technical_information_output == 1)
                    {
                        strcpy(collision_words[counter_collision].item.word, read_word);
                        collision_words[counter_collision].item.quantity = index;
                    }
                    counter_collision++;
                    index++;
                    goto first_write;
                 }
               }
            }
            memset(read_word, 0, WORDLEN);
        }
        if(flag_technical_information_output == 1)
        printf("\nWe got %d collisions.\n", counter_collision);
        printf("At the moment, the fill factor of our data storage in the form of a hash table is equal to %.2f\n", coefficient_filling);
        for(int i = 0; i < size; i++)
        {
            sum_words = sum_words + (pointer_htnode + i)->item.quantity;
        }
        printf("Number of words in the file based on entries in the hash table %d.\n", sum_words);
        if(flag_technical_information_output == 1)
        {
            printf("Conflicted words:\n");
            for(int i = 0; i < counter_collision; i++)
            {
               printf("%s index %d ", collision_words[i].item.word, collision_words[i].item.quantity);
            }
        }

        menu_consol:
        fprintf(stdout, "Select next action:\n");
        fprintf(stdout, "a) Display a list of all words indicating their repetitions.\n");
        fprintf(stdout, "b) Entering a word to check the number of occurrences of that word in a file %s.:\n", argv[1]);
        fprintf(stdout, "q) Exit the program.\n");
        fscanf(stdin, "%c", &read_char);
        while(getchar() != '\n')  // clearing the input buffer after a call fscanf()
            continue;
        // Outputting the resulting list of words
        if(read_char == 'a')
        {
           printf("\nList of words in our hash table:\n");
           for(int i = 0; i < size; i++)
           {
              if((pointer_htnode + i)->item.word[0] != '\0')
                 printf("Word: %s, meets %d, its index %d\n", (pointer_htnode + i)->item.word, (pointer_htnode + i)->item.quantity, i);
           }
           printf("At the moment, the fill factor of our data storage in the form of a hash table is equal to %.2f\n", coefficient_filling);
           goto menu_consol;
        }
        if(read_char == 'b')
        {
            fprintf(stderr, "Enter a word:\n");
            fscanf(stdin, "%s", read_word);
            while(getchar() != '\n')  // clearing the input buffer after a call fscanf()
                continue;
            word_cleaning(read_word);
            if(HASH_FUNCTION_NUMBER == 0)
                index = hash_function(read_word, size);
            if(HASH_FUNCTION_NUMBER == 1)
                index = hash_function1(read_word, size);
            if(HASH_FUNCTION_NUMBER == 2)
                index = hash_function2(read_word, size);
            if(HASH_FUNCTION_NUMBER == 3)
                index = hash_function3(read_word, size);
            if(HASH_FUNCTION_NUMBER == 4)
                index = hash_function4(read_word, size);
            if(HASH_FUNCTION_NUMBER == 5)
                index = hash_function5(read_word, size);
            if(index < 0)
                index = -index;
            first_read:
            if(read_word[0] != '\0')  // it is necessary otherwise hyphens will be written replaced by '\0'
            {
                if((pointer_htnode + index)->item.word[0] == '\0')
                {
                   printf("The entered word does not appear once in the file %s\n", argv[1]);
                }
                else
                {
                   if(strcmp((pointer_htnode + index)->item.word, read_word) == 0)
                   {
                      printf("Word %s meets %d times in a text file %s\n", read_word, (pointer_htnode + index)->item.quantity, argv[1]);
                   }
                   else
                   {
                      index++;
                      goto first_read;
                   }
                }
            }
            memset(read_word, 0, WORDLEN);
            goto menu_consol;
        }
        if(read_char == 'q')
        {
            goto end;
        }
        if(read_char != 'a' && read_char != 'b' && read_char != 'q')
            goto menu_consol;
    }
    end:
    free(pointer_htnode);
    if(flag_technical_information_output == 1)
       free(collision_words);
    printf("This program exits!\n");
    return 0;
}
void word_cleaning(char *ptr)
{
    int counter = 0;
    int counter_temp = 0;
    char temp[WORDLEN] = {0};
    for(counter = 0; *(ptr + counter) != '\0'; counter++)
    {
        if(('A' <= *(ptr + counter) && *(ptr + counter) <= 'Z') || ('a' <= *(ptr + counter) && *(ptr + counter) <= 'z') ||
           ('0' <= *(ptr + counter) && *(ptr + counter) <= '9') || (*(ptr + counter) == '\'') || (*(ptr + counter) == '-'))
        {
            *(temp + counter_temp) = tolower(*(ptr + counter));
            counter_temp++;
        }
    }
    strcpy(ptr, temp);
}

double pow(double value, double power)
{
    double multiply = 1.0;
    while(power)
    {
        multiply = multiply * value;
        power--;
    }
    return multiply;
}

