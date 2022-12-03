#include "students.h"
extern struct sStudent * gpFirstStudent;
int main(void)
{
    char temp_text[40];
    int index = 0;
    int x;
    while(1)
    {
        printf("\n====================================");
        printf("\n choose on the following options:");
        printf("\n 1: AddStudent");
        printf("\n 2: Delete_Student");
        printf("\n 3: view_students");
        printf("\n 4: DeleteAll students");
        printf("\n 5: getValue with index");
        printf("\n 6: findLength of the linkerList");
        printf("\n 7: find Nth node from the end of the linkerList");
        printf("\n====================================\n");
        gets(temp_text);
        if(atoi(temp_text) == 5)
        {
            printf("Enter the index\n");
            scanf("%d",&index);
        }
        if(atoi(temp_text) == 7)
        {
            printf("Enter the nth node from the end\n");
            scanf("%d",&index);
        }
        switch (atoi(temp_text))
        {
        case 1:
            AddStudent();
            break;
        case 2:
            Delete_Student();
            break;
        case 3:
            print_students();
            break;
        case 4:
            deleteAll();
            break;
        case 5:
            GetNth(index);
            break;
        case 6:
            x = findLength(gpFirstStudent);
            printf("The length of the lined list is : %d",x);
            break;
        case 7:
            findNthNodeFromEnd(gpFirstStudent,index);
            break;
        default:
            printf("Wrong option\n");
            break;
        }

    }


    return 0;
}