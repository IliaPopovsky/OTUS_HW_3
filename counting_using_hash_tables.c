#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#include "hash_functions.h"
#define HASH_FUNCTION_NUMBER 3
#define ARRAY_MULTIPLIER 3


//#define WORDLEN 25

void word_cleaning(char *ptr);

int counter_words = 0;
char read_word[WORDLEN];
int sum_words = 0;
HTnode collision_words[100000] = {0};


int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *fs;
    int read_char = 0;
    long long size = 0;
    double coefficient_filling = 0.0;
    long long int index = 0;
    int counter_collision = 0;
    int counter_writes = 0;

    HTnode *pointer_htnode;

    if(argc < 2)
    {
        //if((fs = fopen("piece_of_advice.txt", "r")) == NULL )
        //if((fs = fopen("deal_of_paint.txt", "r")) == NULL )
        //if((fs = fopen("cup_of_tea1.txt", "r")) == NULL )
        if((fs = fopen("cup_of_tea.txt", "rb")) == NULL )
        //if((fs = fopen("proza.txt", "r")) == NULL )
        //if((fs = fopen("My_Family.txt", "r")) == NULL )
        {
            fprintf(stderr, "Не удается открыть файл %s\n", "proza.txt");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fs, "%s", read_word) != EOF)
        {
            if(isalnum(read_word[0]) || isalnum(read_word[1]))
               counter_words++;
            //fprintf(stdout, "%s ", read_word);
            //if(getc(fs) == '\n')
              // putc('\n', stdout);
            memset(read_word, 0, WORDLEN);
        }
        fprintf(stdout, "\nВ данном текстовом файле %d слов.\n", counter_words);
        fseek(fs, 0L, SEEK_SET); // перейти в начало файла

        size = counter_words * ARRAY_MULTIPLIER; // либо хеш-функция 3 для количество слов * 3  и 2 коллизии
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
        //fseek(fs, 0L, SEEK_SET); // перейти в начало файла
        printf("Записанные индексы массива хеш-таблицы:\n");
        while(fscanf(fs, "%s", read_word) != EOF)
        {
            word_cleaning(read_word);
            //read_word[0] = tolower(read_word[0]); // если этого не делать, то коллизий больше на 30%
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
            first_write0:
            if(read_word[0] != '\0')  // нужно иначе будут записываться дефисы заменяные на '\0'
            if((pointer_htnode + index)->item.word[0] == '\0')
            {
                strcpy((pointer_htnode + index)->item.word, read_word);
                (pointer_htnode + index)->item.quantity++;
                counter_writes++;
                coefficient_filling = (double)counter_writes / size;
                //printf("%s %lld ", read_word, index);
                printf("%lld ", index);
            }
            else
            {
                if(strcmp((pointer_htnode + index)->item.word, read_word) == 0)
                    (pointer_htnode + index)->item.quantity++;
                else
                {
                    strcpy(collision_words[counter_collision].item.word, read_word);
                    collision_words[counter_collision].item.quantity = index;
                    counter_collision++;
                    index++;
                    goto first_write0;
                }

            }
            memset(read_word, 0, WORDLEN);
        }
        printf("\nУ нас вышло %d коллизий.\n", counter_collision);
        printf("У нас вышел коэффициент заполнения равен %.2f\n", coefficient_filling);
        for(int i = 0; i < size; i++)
        {
            sum_words = sum_words + (pointer_htnode + i)->item.quantity;
        }
        printf("Количество слов в файле по записям в хеш-таблице %d.\n", sum_words);
        printf("Слова попавшие в коллизию:\n");
        for(int i = 0; i < counter_collision; i++)
        {
            printf("%s индекс %d ", collision_words[i].item.word, collision_words[i].item.quantity);
        }
        // Вывод получившегося списка слов
        printf("\nСписок слов в нашей хеш-таблице:\n");
        for(int i = 0; i < size; i++)
        {
            if((pointer_htnode + i)->item.word[0] != '\0')
                 printf("Слово: %s, встречается %d, его индекс %d\n", (pointer_htnode + i)->item.word, (pointer_htnode + i)->item.quantity, i);
        }

    }
    if(argc >= 2)
    {
        if((fs = fopen(argv[1], "r")) == NULL )
        {
            fprintf(stderr, "Не удается открыть файл %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
         while(fscanf(fs, "%s", read_word) != EOF)
        {
            if(isalnum(read_word[0]) || isalnum(read_word[1]))
               counter_words++;
            //fprintf(stdout, "%s ", read_word);
            //if(getc(fs) == '\n')
              // putc('\n', stdout);
            memset(read_word, 0, WORDLEN);
        }
        fprintf(stdout, "\nВ данном текстовом файле %d слов.\n", counter_words);
        fseek(fs, 0L, SEEK_SET); // перейти в начало файла

        size = counter_words * ARRAY_MULTIPLIER; // либо хеш-функция 3 для количество слов * 3  и 2 коллизии
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
        printf("Записанные индексы массива хеш-таблицы:\n");
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
            if(read_word[0] != '\0')  // нужно иначе будут записываться дефисы заменяные на '\0'
               if((pointer_htnode + index)->item.word[0] == '\0')
               {
                  strcpy((pointer_htnode + index)->item.word, read_word);
                  (pointer_htnode + index)->item.quantity++;
                  counter_writes++;
                  coefficient_filling = (double)counter_writes / size;
                  //printf("%s %lld ", read_word, index);
                  printf("%lld ", index);
               }
               else
               {
                 if(strcmp((pointer_htnode + index)->item.word, read_word) == 0)
                    (pointer_htnode + index)->item.quantity++;
                 else
                 {
                    strcpy(collision_words[counter_collision].item.word, read_word);
                    collision_words[counter_collision].item.quantity = index;
                    counter_collision++;
                    index++;
                    goto first_write;
                 }

               }
               memset(read_word, 0, WORDLEN);
        }
        printf("\nУ нас вышло %d коллизий.\n", counter_collision);
        printf("У нас вышел коэффициент заполнения равен %.2f\n", coefficient_filling);
        for(int i = 0; i < size; i++)
        {
            sum_words = sum_words + (pointer_htnode + i)->item.quantity;
        }
        printf("Количество слов в файле по записям в хеш-таблице %d.\n", sum_words);
        printf("Слова попавшие в коллизию:\n");
        for(int i = 0; i < counter_collision; i++)
        {
            printf("%s индекс %d ", collision_words[i].item.word, collision_words[i].item.quantity);
        }
        menu_consol:
        fprintf(stdout, "Выберите дальнейшее действие:\n");
        fprintf(stdout, "a) Вывод списка всех слов с указанием их поторений.\n");
        fprintf(stdout, "b) Ввод слова для проверки количества вхождений этого слова в файле %s.:\n", argv[1]);
        fprintf(stdout, "q) Выход из программы.\n");
        fscanf(stdin, "%c", &read_char);
        while(getchar() != '\n')  // очистка буфера ввода после вызова scanf()
            continue;
        // Вывод получившегося списка слов
        if(read_char == 'a')
        {
           printf("\nСписок слов в нашей хеш-таблице:\n");
           for(int i = 0; i < size; i++)
           {
              if((pointer_htnode + i)->item.word[0] != '\0')
                 printf("Слово: %s, встречается %d, его индекс %d\n", (pointer_htnode + i)->item.word, (pointer_htnode + i)->item.quantity, i);
           }
           goto menu_consol;
        }
        if(read_char == 'b')
        {
            fprintf(stderr, "Введите слово:\n");
            fscanf(stdin, "%s", read_word);
            while(getchar() != '\n')  // очистка буфера ввода после вызова scanf()
                continue;
            //word_cleaning(read_word);
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
            if(read_word[0] != '\0')  // нужно иначе будут записываться дефисы заменяные на '\0'
               if((pointer_htnode + index)->item.word[0] == '\0')
               {
                  printf("Введенное слово ни разу не встречается в файле %s\n", argv[1]);
               }
               else
               {
                 if(strcmp((pointer_htnode + index)->item.word, read_word) == 0)
                 {
                     printf("Слово %s встречается %d раз в текстовом файле %s\n", read_word, (pointer_htnode + index)->item.quantity, argv[1]);
                 }
                 else
                 {
                    index++;
                    goto first_read;
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
    printf("\nHello world!\n");
    return 0;
}
void word_cleaning(char *ptr)
{
    int counter = 0;
    int counter_temp = 0;
    char temp[WORDLEN] = {0};
    for(counter = 0; *(ptr + counter) != '\0'; counter++)
    {
        if('A' <= *(ptr + counter) && *(ptr + counter) <= 'Z' || 'a' <= *(ptr + counter) && *(ptr + counter) <= 'z' ||
           '0' <= *(ptr + counter) && *(ptr + counter) <= '9' || *(ptr + counter) == '\'' || *(ptr + counter) == '-')
        {
            *(temp + counter_temp) = tolower(*(ptr + counter));
            counter_temp++;
        }
    }
    strcpy(ptr, temp);
}

