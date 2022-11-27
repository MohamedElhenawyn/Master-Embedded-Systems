#include "students.h"

int main(void)
{
    char temp_text[40];
    while(1)
    {
        printf("\n====================================");
        printf("\n choose on the following options:");
        printf("\n 1: AddStudent");
        printf("\n 2: Delete_Student");
        printf("\n 3: view_students");
        printf("\n 4: DeleteAll students");
        printf("\n====================================\n");
        gets(temp_text);
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
        default:
            printf("Wrong option\n");
            break;
        }

    }


    return 0;
}