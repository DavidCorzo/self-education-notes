#include <stdio.h>
int main()
{
    // One liner
    int y = 1;
    int x_with_ternary = y > 7 ? 25 : 50;
    // Traditional notation
    int x_without_ternary;
    if (y > 7) x_without_ternary = 25;
    else x_without_ternary = 50; 
    printf("%d == %d",x_with_ternary,x_without_ternary);
    return 0;
}
/* Output: 
50 == 50
*/
