/*
* @file proje1
* @description iki boyutlu matrislerin çarpımı
* @assignment 1.ödev
* @date 12.12.2021
* @author Ebrar Derindağ ebrar.derindag@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrisoperations.h"


void operation1(int **matris1, int **matris2, int islemTipi, int matris1_Size, int matris2_Size)
{
    int **outputMatris;
    int i, j;
    int dolgu = 0;

    if (islemTipi == 0)
    {
        int outputMatris_size = calculate_OutputMatrisSize(dolgu, matris1_Size, matris2_Size);
        outputMatris = FillMatris(outputMatris, outputMatris_size, 0);
        
        operation2(matris1, matris2, outputMatris, matris1_Size, matris2_Size, outputMatris_size);
    }
    else if (islemTipi == 1)
    {
        int **matris1New;
        int matris1New_size;
        dolgu = calculate_Padding(islemTipi, matris2_Size);
        int outputMatris_size = calculate_OutputMatrisSize(dolgu, matris1_Size, matris2_Size);

        outputMatris = FillMatris(outputMatris, outputMatris_size, 0);

        matris1New_size = matris1_Size + (2 * dolgu);
        matris1New = FillMatris(matris1New, matris1New_size, 0);

        for (i = dolgu; i < (matris1New_size - dolgu); i++)
        {
            for (j = dolgu; j < (matris1New_size - dolgu); j++)
            {
                matris1New[i][j] = matris1[i - dolgu][j - dolgu];
            }
        }

        printf("--Matris1 New--");
        printMatris(matris1New, matris1New_size);
        operation2(matris1New, matris2, outputMatris, matris1New_size, matris2_Size, outputMatris_size);
    }
}
void operation2(int **matris1, int **matris2, int **outputMatris, int matris1_Size, int matris2_Size, int OutputMatris_size)
{
    int counterSatır = 0;
    int counterSütun = 0;
    int temp = 0;
    int counter1 = 0;
    int counter2 = 0;

    while (counter1 < OutputMatris_size)
    {
        while (counter2 < OutputMatris_size)
        {
            for (int i = counterSatır; i < (matris2_Size + counterSatır); i++)
            {
                for (int j = counterSütun; j < (matris2_Size + counterSütun); j++)
                {
                    temp += matris1[i][j] * matris2[i - counterSatır][j - counterSütun];
                }
            }
            outputMatris[counterSatır][counterSütun] = temp;
            temp = 0;
            counterSütun++;
            counter2++;
        }
        counterSatır++;
        counterSütun = 0;
        counter1++;
        counter2 = 0;
    }
    printf("--Output Matris--\n");
    printMatris(outputMatris, OutputMatris_size);
    
   
}

int **FillMatris(int **matris, int matrisSize, int range)
{
    int i, j;

    matris = (int **)(malloc(matrisSize * sizeof(int)));
    for (i = 0; i < matrisSize; i++)
    {
        matris[i] = (int *)(malloc(matrisSize * sizeof(int)));
    }
    if (range != 0)
    {
        for (i = 0; i < matrisSize; i++)
        {
            for (j = 0; j < matrisSize; j++)
            {
                matris[i][j] = (rand() % range);
            }
        }
    }
    else
    {
        for (i = 0; i < matrisSize; i++)
        {
            for (j = 0; j < matrisSize; j++)
            {
                matris[i][j] = 0;
            }
        }
    }
    return matris;
}

void printMatris(int **matris, int matrisSize)
{
    printf("\n");
    int i, j;
    for (i = 0; i < matrisSize; i++)
    {
        for (j = 0; j < matrisSize; j++)
        {
            printf("%d  ", matris[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int calculate_Padding(int islemTipi, int matris2_length)
{
    int dolgu = ((matris2_length - 1) / 2);
    return dolgu;
}

int calculate_OutputMatrisSize(int dolgu, int matris1_length, int matris2_length)
{
    int ciktiBoyut = (matris1_length - matris2_length + (2 * dolgu)) + 1;
    return ciktiBoyut;
}
