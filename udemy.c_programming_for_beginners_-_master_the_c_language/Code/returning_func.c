#include <stdio.h>
int multiply_two_nums(int x, int y);
int main()
{
    int result = multiply_two_nums(3,4);
    printf("%d",result);
    return 0;
}

int multiply_two_nums(int x, int y){
    return x * y;
}
/* Output: 
12
*/
