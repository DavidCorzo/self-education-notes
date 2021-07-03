#include <stdio.h>
#include <stdbool.h>
int main()
{
    float num = 23.333;
    double num2 = 55.555555555555;
    bool boolVar = true;
    printf("%lf,%lf,%d",num,num2,boolVar);
    long int numberOfPoints = 131071100L;
    return 0;
}
/* Output: 
23.333000,55.555556,1   
*/
