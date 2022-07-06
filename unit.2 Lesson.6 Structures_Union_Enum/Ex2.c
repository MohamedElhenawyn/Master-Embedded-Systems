#include <stdio.h>
struct Sdist{
  int feet;
  float inch;
};
int main(void)
{
    struct Sdist dist1,dist2;
    printf("Enter information for first distance\n");
    printf("Enter feet: ");
    scanf("%d",&dist1.feet);
    printf("Enter inch: ");
    scanf("%f",&dist1.inch);
    
    printf("Enter information for second distance\n");
    printf("Enter feet: ");
    scanf("%d",&dist2.feet);
    printf("Enter inch: ");
    scanf("%f",&dist2.inch);
    printf("Sum of distances = %d' %.2f\"",dist1.feet+dist2.feet,dist1.inch+dist2.inch);
    return 0;
}