#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);

int main()
{
    /* local variable definition */
    int a = 100; 
    int b = 200;

    printf("Before swap, value of a: %d\n",a);
    printf("Before swap, value of b: %d\n",b);
    /* calling a function to swap the values */
    swap(&a,&b); // needs to take addresses.
    printf("After swap, value of a: %d\n",a);
    printf("After swap, value of b: %d\n",b);

    return 0;
}
/* function definition to swap the values */
void swap(int *x, int *y){
    int temp;
    temp = *x; /* save the value of x */
    *x = *y; /* put temp into y */
    *y = temp; /* put temp into y */
    return; 
}
/* Output: 
Before swap, value of a: 100
Before swap, value of b: 200
After swap, value of a: 200
After swap, value of b: 100

*/
