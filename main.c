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
#include "matrisoperations.c"

int main()
{
    int **matris1;
    int **matris2;
    int satir1, satir2;
    int islemTipi = 0;
    int i, j;

    printf("Buyuk Matris Satir Sayisi: ");
    scanf("%d", &satir1);

    printf("Kucuk Matris Satir Sayisi: ");
    scanf("%d", &satir2);

    printf("islem tipi:  ");
    scanf("%d", &islemTipi);

    printf("--Matris 1--");
    matris1 = FillMatris(matris1, satir1, 10);
    printMatris(matris1, satir1);

    printf("--Matris 2--");
    matris2 = FillMatris(matris2, satir2, 10);
    printMatris(matris2, satir2);

    operation1(matris1, matris2, islemTipi, satir1, satir2);

    return 0;
}