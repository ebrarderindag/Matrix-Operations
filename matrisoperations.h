/*
* @file proje1
* @description iki boyutlu matrislerin çarpımı
* @assignment 1.ödev
* @date 12.12.2021
* @author Ebrar Derindağ ebrar.derindag@stu.fsm.edu.tr
*/
#ifndef MATRISOPERATIONS_H
#define MATRISOPERATIONS_H


void operation1(int **matris1, int **matris2, int islemTipi, int matris1Size, int matris2Size);
void operation2(int **matris1, int **matris2, int **outputMatris, int matris1_Size, int matris2_Size, int OutputMatris_size);
int **FillMatris(int **matris, int matrisSize, int range);
int calculate_Padding(int islemTipi, int matris2_length);
void printMatris(int **matris, int matrisSize);
int calculate_OutputMatrisSize(int dolgu, int matris1_length, int matris2_length);

#endif