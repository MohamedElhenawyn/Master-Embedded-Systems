/*
 * main.c
 *
 *  Created on: June 9, 2022
 *      Author: Mohamed_Ahmed
 *      Ex1: Example of multidimentional array in c
 *
 */


#include <stdio.h>
int main ()
{
	int i,j;
	float a[2][2];
	float b[2][2];
	printf("Enter the elements of 1st matrix: \n");
	for (i = 0 ; i < 2 ; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			scanf("%f",&a[i][j]);
			puts("");
		}
	}
	printf("Enter the elements of 2nd matrix: \n");

	for (i = 0 ; i < 2 ; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("Enter b%d%d: ",i+1,j+1);
			scanf("%f",&b[i][j]);
			puts("");
		}
	}
	printf("Sum of Matrix:\n");
	for (i = 0 ; i < 2 ; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%.1f\t", a[i][j] + b[i][j]);
		}
		puts("");
	}
	return 0;
}
