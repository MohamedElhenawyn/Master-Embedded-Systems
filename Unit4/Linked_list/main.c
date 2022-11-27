#include "students.h"

int main(void)
{
    char temp_text[40];
    int index = 0;
    while(1)
    {
        printf("\n====================================");
        printf("\n choose on the following options:");
        printf("\n 1: AddStudent");
        printf("\n 2: Delete_Student");
        printf("\n 3: view_students");
        printf("\n 4: DeleteAll students");
        printf("\n 5: getValue with index");
        printf("\n====================================\n");
        gets(temp_text);
        if(atoi(temp_text) == 5)
        {
            printf("Enter the index\n");
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
        default:
            printf("Wrong option\n");
            break;
        }

    }


    return 0;
}