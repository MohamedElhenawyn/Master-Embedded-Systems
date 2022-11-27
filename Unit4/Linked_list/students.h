#ifndef STUDENTS_H_
#define STUDENTS_H_
#include "stdlib.h"
#include "stdio.h"

struct sData
{
    int ID;
    char name[40];
    float height;
};
struct sStudent
{
    struct sData Student;
    struct sStudent * pNextStudent;
};
void AddStudent();
void fill_the_record(struct sStudent *);
void print_students();
int Delete_Student();
void deleteAll();
int GetNth(int );
#endif