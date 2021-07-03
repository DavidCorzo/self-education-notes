#include <stdio.h>
void multiply_two_nums(int x, int y);
int main()
{
    multiply_two_nums(3,4);
    multiply_two_nums(5,6);
    multiply_two_nums(5,5);
    return 0;
}

void multiply_two_nums(int x, int y){
    int result = x * y; 
    printf("x: %d, y: %d, result: %d\n",x,y,result);
}
/* Output: 
x: 3, y: 4, result: 12
x: 5, y: 6, result: 30
x: 5, y: 5, result: 25

*/
