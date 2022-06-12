/*
 * main.c
 *
 *  Created on: June 9, 2022
 *      Author: Mohamed_Ahmed
 *      Ex6: C program to find the frequency of characters in a string
 *
 */
#include <stdio.h>

int main(void)
{
    char  text[100],search;
    int freq = 0,i = 0;
    printf("Enter a string: ");
    gets(text);
    printf("Enter a character to find frequency: ");
    scanf("%c",&search);
    while(text[i] != 0)
    {
     if(search == text[i])
     {
         freq++;
     }
     i++;
    }
    printf("Frequency of %c is %d",search,freq);
    return 0;
}


or

#include <stdio.h>
#include <string.h>

int main(void)
{
    char  str[50],ch,flag;
    printf("Enter a string: ");
    gets(str);
    printf("Enter a character to find frequency: ");
    scanf("%c",&ch);
    flag = 0;
    for(int i = 0; i < strlen(str);i++)
    {
        if(ch == str[i])
        {
            flag++;
        }
    }
    printf("Frequency of %c = %d\n",ch,flag);
    return 0;
}
