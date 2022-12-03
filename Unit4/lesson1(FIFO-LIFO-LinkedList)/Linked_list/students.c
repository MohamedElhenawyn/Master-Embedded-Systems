#include "students.h"

struct sStudent * gpFirstStudent= NULL;

void AddStudent()
{
    struct sStudent *pLastStudent;
    struct sStudent *pNewStudent;
    if(gpFirstStudent == NULL){
        pNewStudent = (struct sStudent *)malloc(sizeof(struct sStudent ));
        gpFirstStudent = pNewStudent;
    }
    else{
        pLastStudent = gpFirstStudent;
        while(pLastStudent->pNextStudent != NULL)
        {
            pLastStudent = pLastStudent->pNextStudent;
        }
        pNewStudent = (struct sStudent *)malloc(sizeof(struct sStudent ));
        pLastStudent->pNextStudent = pNewStudent;
    }
    fill_the_record(pNewStudent);
    pNewStudent->pNextStudent = NULL;
}
void fill_the_record(struct sStudent * ptr)
{
    char temp_text[40];
    //ptr = (struct sStudent *)malloc(sizeof(struct sStudent ));
    printf("\nEnter the ID of the student: ");
    gets(temp_text);
    ptr->Student.ID = atoi(temp_text);
    printf("\nEnter student full name: ");
    gets(ptr->Student.name);
    printf("\nEnter student height: ");
    gets(temp_text);
    ptr->Student.height = atof(temp_text);
    printf("Done adding\n");
    
}
int Delete_Student()
{
    struct sStudent * temp = gpFirstStudent;
    struct sStudent * prev = temp; 
    int i;
    if(gpFirstStudent)
    {
        printf("\nEnter student id you want to delete\n");
        scanf("%d",&i);
        while(temp != NULL)
        {
            
            if((temp->Student.ID == i) && temp == gpFirstStudent)
            {
                gpFirstStudent = gpFirstStudent->pNextStudent;
                free(temp);
                return 1;
            }else if((temp->Student.ID == i))
            {
                prev->pNextStudent = temp->pNextStudent;
                free(temp);
                return 1;
            }
            prev = temp;
            temp = temp->pNextStudent;
        }
        printf("\nCannot find student ID.\n");
        return 0;        
    }
    return 0;   
}
void print_students()
{
    struct sStudent * temp = gpFirstStudent ;
    int i = 1;
    if(gpFirstStudent == NULL)
    {
        printf("\nEmpty list\n");
    }
    while(temp != NULL)
    {
        printf("\nRecord Number %d \n",i);
        printf("\nID : %d\n",temp->Student.ID);
        printf("\nName : %s \n",temp->Student.name);
        printf("\nHeight : %.2f\n",temp->Student.height);
        i++;
        temp = temp->pNextStudent;
    }   
}

void deleteAll()
{
    struct sStudent * next,*prev;
    next = gpFirstStudent;
    if(gpFirstStudent == NULL)
    {
        printf("Empty list\n");
    }
    while(next != NULL){
        prev = next;
        next = next->pNextStudent;
        free(prev);
    }
    gpFirstStudent = NULL;
}

int GetNth(int index)
{
    struct sStudent * temp = gpFirstStudent;
    int i = 0;
    while (temp != NULL)
    {
        if(i == index)
        {
            printf("The ID at index %d is %d\n",i,temp->Student.ID);
            printf("The Name at index %d is %s\n",i,temp->Student.name);
            printf("The height at index %d is %.2f\n",i,temp->Student.height);

            return 1;//Found
        }
        i++;
        temp = temp->pNextStudent;
    }
    return 0; //not found
}

int findLength(struct sStudent * ptr)
{
    struct sStudent * temp = ptr;
    if(ptr)
    {

        return 1 + findLength(temp->pNextStudent);
    }else{
        return 0;
    }
}
int findNthNodeFromEnd(struct sStudent *ptr,int nEnd)
{
    struct sStudent *main_ptr,*ref_ptr;
    main_ptr = ptr;
    ref_ptr = ptr;
    for(int i = 1;i <= nEnd ;i++)
    {
        ref_ptr = ref_ptr->pNextStudent;
        if(ref_ptr == NULL && i <nEnd)
        {
            printf("The linked list is not that big");
            return 1;//not found
        }
    }
    while(ref_ptr != NULL)
    {
        ref_ptr = ref_ptr->pNextStudent;
        main_ptr = main_ptr->pNextStudent;
    }
    printf("The student ID is : %d\n",main_ptr->Student.ID);
    printf("The student name is : %s\n",main_ptr->Student.name);
    printf("The student height is : %.2f\n",main_ptr->Student.height);
    return 0;//found

}