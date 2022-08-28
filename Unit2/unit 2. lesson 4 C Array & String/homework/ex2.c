/*
 * main.c
 *
 *  Created on: June 9, 2022
 *      Author: Mohamed_Ahmed
 *      Ex2: program to calculate average using arrays
 *
 */



#include <stdio.h>

int main(void)
{
    int nOfData,counter;
    float Average , sum = 0;
    printf("Enter the number of data: ");
    scanf("%d",&nOfData);
    float avg[nOfData];
    for(counter = 0; counter < nOfData; counter++)
    {
        printf("%d. Enter number: ",counter + 1);
        scanf("%f",&avg[counter]);
        sum = sum + avg[counter];
    }
    Average = sum / nOfData;
    printf("Average = %.2f ",Average);
    return 0;
}