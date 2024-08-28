#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#include "hash_functions.h"
//#define WORDLEN 25

void word_cleaning(char *ptr);

int counter_words = 0;
char read_word[WORDLEN];
int sum_words = 0;
HTnode collision_words[10000] = {0};


int main(int argc, char *argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *fs;
    int read_symbol = 0;
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
        //if((fs = fopen("cup_of_tea.txt", "r")) == NULL )
        if((fs = fopen("proza.txt", "r")) == NULL )
        //if((fs = fopen("My_Family.txt", "r")) == NULL )
        {
            fprintf(stderr, "�� ������� ������� ���� %s\n", "proza.txt");
            exit(EXIT_FAILURE);
        }
        while(fscanf(fs, "%s", read_word) != EOF)
        {
            counter_words++;
            //fprintf(stdout, "%s ", read_word);
            //if(getc(fs) == '\n')
              // putc('\n', stdout);
        }
        fprintf(stdout, "\n� ������ ��������� ����� %d ����.\n", counter_words);
        fseek(fs, 0L, SEEK_SET); // ������� � ������ �����

        size = counter_words * 7; // ���� ���-������� 3 ��� ���������� ���� * 3  � 2 ��������
        if((pointer_htnode = (HTnode *)calloc(size, sizeof(HTnode))) == NULL)
        {
            fprintf(stdout, "�� ������� ����� � ����������� ������ ��� ���������� ������� ������� ���-�������, ��� ������� ������� ��������� ���������� ����� �������.\n"
                   "����������� ������� ������� ��������� ���������� ����� �������.\n");
            exit(1);
        }
        else
        {
            fprintf(stdout, "������� ����� � ����������� ������ ��� ���������� ������� ������� ���-�������, ��� ������� ������� ��������� ���������� ����� �������.\n");

        }
        printf("������ ����������� ������� ����� %d ��������.\n", size);
        fseek(fs, 0L, SEEK_SET); // ������� � ������ �����
        printf("���������� ������� ������� ���-�������:\n");
        while(fscanf(fs, "%s", read_word) != EOF)
        {
            word_cleaning(read_word);
            //read_word[0] = tolower(read_word[0]); // ���� ����� �� ������, �� �������� ������ �� 30%
            index = hash_function3(read_word, size);
            if(index < 0)
                index = -index;
            first_write:
            if(read_word[0] != '\0')
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
        printf("\n� ��� ����� %d ��������.\n", counter_collision);
        printf("� ��� ����� ����������� ���������� ����� %.2f\n", coefficient_filling);
        for(int i = 0; i < size; i++)
        {
            sum_words = sum_words + (pointer_htnode + i)->item.quantity;
        }
        printf("���������� ���� � ����� �� ������� � ���-������� %d.\n", sum_words);
        printf("����� �������� � ��������:\n");
        for(int i = 0; i < counter_collision; i++)
        {
            printf("%s ������ %d ", collision_words[i].item.word, collision_words[i].item.quantity);
        }
        // ����� ������������� ������ ����
        printf("\n������ ���� � ����� ���-�������:\n");
        for(int i = 0; i < size; i++)
        {
            if((pointer_htnode + i)->item.word[0] != '\0')
                 printf("�����: %s, ����������� %d, ��� ������ %d\n", (pointer_htnode + i)->item.word, (pointer_htnode + i)->item.quantity, i);
        }

    }
    if(argc >= 2)
    {

    }
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
           '0' <= *(ptr + counter) && *(ptr + counter) <= '9' || *(ptr + counter) == '\'')
        {
            *(temp + counter_temp) = tolower(*(ptr + counter));
            counter_temp++;
        }
    }
    strcpy(ptr, temp);
}

