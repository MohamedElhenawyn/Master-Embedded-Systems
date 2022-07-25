#include <stdio.h>

struct employee{
  char name[20];
  int id;
};
struct employee emp1 = {"Sharock",1001};
struct employee emp2 = {"Alex",1002};
struct employee emp3 = {"Remi",1002};
struct employee * arr[3] = {&emp1,&emp2,&emp3};
struct employee (*(*ptr)[3]) = &arr;

int main(void)
{
    printf("Employee Name: %s\n",(**(*ptr + 1)).name);
    printf("Employee ID: %d\n",(*(*ptr + 1))->id);
    return 0;
}