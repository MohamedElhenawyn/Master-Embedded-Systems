//Tricks
//an optimization tricks:

1-
int i = 5,j=10,k=15;
printf("d ",sizeof(k/= i +j));
printf("%d",k);

result:
4 15  /* because the sizeof will optimize what inside it and will see that the final result will give us ; sizeof(int) */
////////////////////////////////////////////////

2-
write hello world without semicolon

if( printf("Hello World\n"))

3- 
_type __var_ = _Value;      //Declaration

_type __var_;               //Definition & declaration

// the definition of x is in another folder (not define in the memory here)
extern int x;            

4- 
int x = 3;
float y = 3.0;
if (x==y)
   printf("True");

result : true because of the implicit casting

5-
 int i = 1;
if(i++ && ( i==1) )* //is the condition is true or false ?

result:false because the priority of the ++ is higher than && and the brackets

6- 
char ch ='a'; // a = 97 in ascii
switch(ch)
{
case 97:
	printf("97");
	break;
case 'a':
	printf("a");
	break;
}
result: compilaton error duplicate case value

7-
int i=2,j=5,k=10;
a = i > 1 ? j < 1 || k < 1 ? 100:200:300;
	  -------------------------- -> will be the result of the true 	
printf("a");
result :200 
explanation -> 
i > 1 yes so the whole expression (j < 1 || k < 1 ? 100:200) is true 
so is j < 1 or k < 10 this is false so the result will be false so 200 is the answer.

8-
 how to swap two numbers without using a temp variable 
x = 5;
y = 6;
x = x + y ; //x  =11 
y = x - y; y = 11 - 6 = 5
x = x - y; x = 11 - 5 = 6

9-
data conversion and type casting 
int z = 0x878925; /* 25 will be stored in the first byte 89 will be stored in the second byte and 87 will be stored in the third byte and 00 will be stored in the forth byte */
char b ;
 b = z ; /* char is one byte so it will store one the first byte of z which is 25 it will generate warning so to solve this warning you can make it as explicit data conversion b = (char)z; */  

10-
Find ceil of a/b without using ceil() function

ceilVal = (a / b) + ((a % b) != 0) 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>

int main(void)
{
	clock_t t;
	t = clock();
	int num1,num2,sum;
	printf("Enter the first number: \n");

	num1 = 1;
	printf("Enter the second number: \n");
	num2 = 2;
	sum = num1+num2;
	printf("sum of two values = %d\n",sum);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("fun() took %lf seconds to execute.\n",time_taken);

	return 0;
}