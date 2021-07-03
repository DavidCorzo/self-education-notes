#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int arraySum(int array[], const int n);
    int values[10] = {3,7,-9,3,6,-1,7,9,1,-5};
    printf("Sum: %i\n",arraySum(values,10));
    return 0; 
}


int arraySum(int array[], const int n){
    int sum = 0, *ptr; // declaring variables
    int *const arrayEnd = array + n; // locating the end of array
    
    for (ptr = array /*Alternatively: ptr = &array[0]*/; ptr < arrayEnd; ++ptr )
        sum += *ptr; // adding to the value of the array

    return sum;
}
/* Output: 
Sum: 21

*/
