#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "hash_functions.h"
//#define WORDLEN 25

void word_cleaning(char *ptr);

int counter_words = 0;
char read_word[WORDLEN];
int sum_words = 0;


int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *fs;
    int read_symbol = 0;
    int size = 0;
    double coefficient_filling = 0.0;
    int index = 0;
    int counter_collision = 0;
    int counter_writes = 0;




    HTnode *pointer_htnode;

    if(argc < 2)
    {
        if((fs = fopen("proza.txt", "r")) == NULL )
        {
            fprintf(stderr, "Не удается открыть файл %s\n", "proza.txt");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fs, "%s", read_word) != EOF)
        {
            counter_words++;
            fprintf(stdout, "%s ", read_word);
            if(getc(fs) == '\n')
               putc('\n', stdout);
        }
        fprintf(stdout, "\nВ данном текстовом файле %d слов.\n", counter_words);
        fseek(fs, 0L, SEEK_SET); // перейти в начало файла

        size = counter_words * 1.5;
        if((pointer_htnode = (HTnode *)calloc(size, sizeof(HTnode))) == NULL)
        {
            fprintf(stdout, "Не хватает места в оперативной памяти для построения данного массива хеш-таблицы, при условии анализа исходного текстового файла целиком.\n"
                   "Рассмотрите вариант анализа исходного текстового файла частями.\n");
            exit(1);
        }
        else
        {
            fprintf(stdout, "Хватает места в оперативной памяти для построения данного массива хеш-таблицы, при условии анализа исходного текстового файла целиком.\n");

        }
        printf("Размер выделенного массива равен %d элемента.\n", size);
        fseek(fs, 0L, SEEK_SET); // перейти в начало файла
        while(fscanf(fs, "%s", read_word) != EOF)
        {
            word_cleaning(read_word);
            read_word[0] = tolower(read_word[0]); // если этого не делать, то коллизий больше на 30%
            index = hash_function(read_word, size);
            if((pointer_htnode + index)->item.word[0] == '\0')
            {
                strcpy((pointer_htnode + index)->item.word, read_word);
                (pointer_htnode + index)->item.quantity++;
                counter_writes++;
                coefficient_filling = (double)counter_writes / size;
            }
            else
            {
                if(strcmp((pointer_htnode + index)->item.word, read_word) == 0)
                    (pointer_htnode + index)->item.quantity++;
                else
                    counter_collision++;
            }

        }
        printf("У нас вышло %d коллизий.\n", counter_collision);
        printf("У нас вышел коэффициент заполнения равен %.2f\n", coefficient_filling);
        for(int i = 0; i < size; i++)
        {
            sum_words = sum_words + (pointer_htnode + i)->item.quantity;
        }
        printf("Количество слов в файле по записям в хеш-таблице %d.\n", sum_words);

    }
    if(argc >= 2)
    {

    }
    printf("Hello world!\n");
    return 0;
}
void word_cleaning(char *ptr)
{
    int counter;

    for(counter = 0; *(ptr + counter) != '\0'; counter++)
    {
        switch(*(ptr + counter))
        {
           case '.': *(ptr + counter) = '\0';
                      goto end_for;
           case ',': *(ptr + counter) = '\0';
                      goto end_for;
           case '!': *(ptr + counter) = '\0';
                      goto end_for;
           case '?': *(ptr + counter) = '\0';
                      goto end_for;
           case ':': *(ptr + counter) = '\0';
                      goto end_for;
           case ';': *(ptr + counter) = '\0';
                      goto end_for;
           default :
                   continue;
        }
        end_for:
            break;
    }
}

