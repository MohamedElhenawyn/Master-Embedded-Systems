#include <stdio.h>
struct ScomplexNum{
    float real;
    float imag;
};
int main(void)
{
    struct ScomplexNum cNum1,cNum2;
    printf("For first complex number: \n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f",&cNum1.real,&cNum1.imag);
    printf("For second complex number: \n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f",&cNum2.real,&cNum2.imag);
    printf("sum = %.1f + %.1fi",cNum1.real + cNum2.real,cNum1.imag + cNum2.imag);
    return 0;
}