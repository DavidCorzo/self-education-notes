#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 10; 
    float f = 2.34; 
    char ch = 'k';
    void *vptr; 
    vptr = &i; 
    printf("Value of i = %d\n",*(int *)vptr);
    vptr = &f; 
    printf("Value of f = %f\n",*(float *)vptr);
    vptr = &ch; 
    printf("Value of ch = %c\n",*(char *)vptr);
    return 0;
}
/* Output: 
Value of i = 10
Value of f = 2.340000
Value of ch = k

*/
