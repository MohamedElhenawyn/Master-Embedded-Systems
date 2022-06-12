/*
 * main.c
 *
 *  Created on: June 9, 2022
 *      Author: Mohamed_Ahmed
 *      Ex3: Example of find transpose of a matrix
 *
 */

#include <stdio.h>

int main(void)
{
    int rows,columns,i,j;
    printf("Enter rows and columns of matrix: ");
    scanf("%d%d",&rows,&columns);
    float a[rows][columns],trans[columns][rows];
    printf("Enter elements of matrix:\n");
    for(i = 0; i <rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("Enter element a[%d][%d]: ", i + 1, j + 1 );
            scanf("%f",&a[i][j]);
        }
    }
    puts("");
     for(i = 0; i <columns; i++)
    {
        for(j = 0; j < rows; j++)
        {
            trans[i][j] = a[j][i];
        }
    }
    puts("");
    printf("Transpose of Matrix:\n");
    for(i = 0; i <columns; i++)
    {
        for(j = 0; j < rows; j++)
        {
            printf("%0.1f\t",trans[i][j]);
        }
        puts("");
    }
    return 0;
}