/*
 * main.c
 *
 *  Created on: June 9, 2022
 *      Author: Mohamed_Ahmed
 *      Ex1: program to reverse a giving string
 *
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50],rev[50];
    printf("Enter a string: ");
    gets(str);
    int x = 0;
   // printf("%d",strlen(str));

    for(int i = strlen(str) - 1; i >= 0; i--)
    {
        rev[x] = str[i];
        x++;
        if(x == strlen(str))
        {
            rev[x] = 0;
            break;

        }

    }
    printf("Reversing string: %s\n",rev);
    return 0;
}
