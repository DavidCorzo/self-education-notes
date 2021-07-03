#include <stdio.h>
int main()
{
    _Bool a = 1, b = 1, result; 
    result = a && b;
    printf("a && b: %d\n",result);
    result = a || b;
    printf("a || b: %d\n",result);
    result = !a;
    printf("!a: %d\n",result);
    return 0;
}
/* Output: 
a && b: 1
a || b: 1
!a: 0

*/
