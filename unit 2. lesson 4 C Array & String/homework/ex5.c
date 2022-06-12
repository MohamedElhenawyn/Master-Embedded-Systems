/*
 * main.c
 *
 *  Created on: June 9, 2022
 *      Author: Mohamed_Ahmed
 *      Ex5:C program to search an element in an array
 *
 */

#include <stdio.h>

int main(void)
{
    int nOfElem,searched,founded,flag = 0;
    printf("Enter no of elements: ");
    scanf("%d",&nOfElem);
    int arr[nOfElem];
    for (int i = 0; i < nOfElem; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&searched);
    for (int i = 0; i < nOfElem; i++)
    {
        if(searched == arr[i])
        {
            printf("Number found at the location : %d.",i + 1);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Number not found.");
    }
    return 0;
}