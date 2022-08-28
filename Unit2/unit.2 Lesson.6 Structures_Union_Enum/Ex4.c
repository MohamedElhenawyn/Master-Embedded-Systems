#include <stdio.h>
struct sStudent{
    char name[50];
    int roll;
    float marks;
};
int main(void)
{
    struct sStudent students[10];
    int i;
    printf("Enter information of students: \n");
    for(i = 0; i < 10; i++)
    {
        printf("For roll number %d\n",i + 1);
        students[i].roll = i + 1;
        printf("Enter name: ");
        scanf("%s",students[i].name);
        printf("Enter marks");
        scanf("%f",&students[i].marks);
    }
    printf("\nDisplaying information of students: \n");
    for(i = 0; i < 10; i++){
        printf("information of roll number %d\n",i + 1);
        printf("Name: %s\n",students[i].name);
        printf("Marks: %.2f\n",students[i].marks);
    }
    return 0;
}