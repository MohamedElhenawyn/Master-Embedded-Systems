#include <stdio.h>

int main(void)
{
    int i,arr[15],elmNum, *ptr;
    printf("Input the number of elements to store in the array (max 15) : ");
    fflush(stdout);
    scanf("%d",&elmNum);
    printf("Input 5 number of elements in the array : \n");
    for(i = 0; i <elmNum;i++)
    {
        printf("element - %d: ",i + 1);
        fflush(stdout);
        scanf("%d",&arr[i]);
    }
    ptr = &arr[elmNum - 1];
    puts("The elements of array in reverse order are : ");
    fflush(stdout);
    for(i = elmNum; i > 0; i--)
    {
       printf("element - %d: %d \n",i,*ptr);
       fflush(stdout);
       ptr--;
    }
    return 0;
}
