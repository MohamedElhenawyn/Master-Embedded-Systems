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

struct sStudent * createNode();
struct sStudent * append(struct sStudent *last,struct sStudent *next);
void print_students(struct sStudent *database);
#endif