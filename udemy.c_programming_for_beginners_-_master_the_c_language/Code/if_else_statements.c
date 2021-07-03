#include <stdio.h>
int main()
{
    int number_to_test, remainder;
    printf("Enter your number to be tested: "); scanf("%i",&number_to_test);
    remainder = number_to_test % 2;
    if (remainder == 0) printf("Even");
    else printf("odd");
    return 0;
}
/* Output: 
Enter your number to be tested: 45
odd
*/
