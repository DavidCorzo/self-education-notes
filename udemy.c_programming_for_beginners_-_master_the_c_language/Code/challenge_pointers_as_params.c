#include <stdio.h>
#include <stdlib.h>

void square(int *const x);

int main()
{
    int x = 10; 
    printf("Before: %d\n",x);
    square(&x);
    printf("After:  %d\n",x);
    return 0;
}
void square(int *const x){ // The adress is constant.
    *x = (*x) * (*x);
}
/* Output: 
Before: 10
After:  100

*/
