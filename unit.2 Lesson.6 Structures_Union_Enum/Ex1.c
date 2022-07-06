#include <stdio.h>
struct Sstudent{
  char name[50];
  int rollNum;
  float marks;
};

int main(void)
{
    struct Sstudent stud1;
    printf("Enter information of students: \n");
    printf("Enter name: ");
    scanf("%s",stud1.name);
    printf("Enter roll number: ");
    scanf("%d",&stud1.rollNum);
    printf("Enter marks: ");
    scanf("%f",&stud1.marks);
    
    printf("Displaying information\n");
    printf("name : %s\n",stud1.name);
    printf("Roll: %d\n",stud1.rollNum);
    printf("Marks: %.2f\n",stud1.marks);
    return 0;
}