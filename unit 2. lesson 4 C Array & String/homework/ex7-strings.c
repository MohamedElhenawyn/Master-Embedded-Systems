#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50];
    int i = 0;
    printf("Enter a string: ");
    gets(str);
    while(str[i] != 0)
    {
        i++;
    }
    printf("Length of string: %d",i);
    return 0;
}
