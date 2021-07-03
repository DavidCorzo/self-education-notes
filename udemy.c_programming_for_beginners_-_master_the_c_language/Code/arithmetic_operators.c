#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 33, b = 15, result = 0;   
    result = a + b; 
    printf("Result +: %d\n",result);
    result = a - b; 
    printf("Result -: %d\n",result);
    result = a * b; 
    printf("Result *: %d\n",result);
    result = a / b; 
    printf("Result /: %d\n",result);
    result = a % b; 
    printf("Result %%: %d\n",result);
    result = a++ + b; 
    printf("Result ++: %d\n",result);
    result = a + b--; 
    printf("Result --: %d\n",result);
    return 0;
}
/* Output: 
Result +: 48
Result -: 18
Result *: 495
Result /: 2
Result %: 3
Result ++: 48
Result --: 49

*/
