#include <stdio.h>

int main(void)
{
    int i = 0;
    char ch = 'A';
    char * ptr = &ch;
    for(i = 0;i<26;i++)
    {
        printf("%c ",*ptr);
        ch++;
    }
    return 0;
}