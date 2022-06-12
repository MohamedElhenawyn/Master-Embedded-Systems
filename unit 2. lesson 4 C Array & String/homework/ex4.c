/*
 * main.c
 *
 *  Created on: June 9, 2022
 *      Author: Mohamed_Ahmed
 *      Ex4: C program to insert an element in an array
 *
 */

#include <stdio.h>

int main(void)
{
    int j,nOfElements,element,location;
    printf("Enter no of elements: ");
    scanf("%d",&nOfElements);
    int arr[nOfElements ],toBeInserted[nOfElements + 1];
    for (int i = 0; i < nOfElements; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d",&element);

    printf("Enter the location: ");
    scanf("%d",&location);
    j = 0;
    for(int i = 0; i <nOfElements + 1;i++ )
    {
        if( i == location - 1)
            continue;
        toBeInserted[i] = arr[j];
        j++;
    }
    toBeInserted[location - 1] = element;
    for(int i = 0; i < nOfElements + 1;i++)
    {
        printf("%d ",toBeInserted[i]);
    }

    return 0;
}
