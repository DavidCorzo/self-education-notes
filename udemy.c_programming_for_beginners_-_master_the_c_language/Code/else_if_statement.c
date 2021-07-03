#include <stdio.h>
int main()
{
    int number, sign;
    printf("Type in a number: ");scanf("%i",&number);
    if (number < 0) sign = -1;
    else if (number == 0) sign = 0;
    else sign = 1;
    printf("Sign %i\n",sign);
    return 0;
}
/* Output: 
Type in a number: 45
Sign 1

*/
