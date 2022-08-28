#include <stdio.h>

int main(void)
{
    char str[50];
    char * ptr = NULL;
    int i = 0;
    printf("Input a string: ");
    fflush(stdout);
    gets(str);
    while(str[i] != '\0') i++;
    ptr = &str[i - 1];
    printf("Reverse of the string is: ");
    for(;i>0;i--)
    {
        printf("%c",*ptr);
        ptr--;
    }
    return 0;
}
