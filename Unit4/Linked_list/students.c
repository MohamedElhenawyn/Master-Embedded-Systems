#include "students.h"
struct sStudent * createNode()
{
    struct sStudent * ptr = NULL;
    char temp_text[40];
    ptr = (struct sStudent *)malloc(sizeof(struct sStudent ));
    printf("Enter the ID of the student\n");
    gets(temp_text);
    ptr->Student.ID = atoi(temp_text);
    printf("Enter student full name\n");
    gets(ptr->Student.name);
    printf("Enter student height\n");
    gets(temp_text);
    ptr->Student.height = atof(temp_text);
    ptr->pNextStudent = NULL;
    return ptr;
}
struct sStudent * append(struct sStudent *last,struct sStudent *next)
{

}
void print_students(struct sStudent *database)
{

}