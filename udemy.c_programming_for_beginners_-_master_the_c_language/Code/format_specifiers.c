#include <stdio.h>
#include <stdbool.h>
int main()
{
    int integervar = 100;
    float floatingpoint = 331.994523934;
    double doublevar = 8.44e+11;
    char charvar = 'W';
    bool boolvar = 0;

    printf("integervar = %i\n",integervar);
    printf("floatingpoint = %f\n",floatingpoint);
    /*For precision use: %.2f*/
    printf("doublevar = %.2f\n",floatingpoint);
    printf("doublevar = %e\n",doublevar);
    printf("doublevar = %g\n",doublevar);
    printf("charvar = %c\n",charvar);
    printf("boolvar = %i\n",boolvar);
    return 0;
}
/* Output: 
integervar = 100
floatingpoint = 331.994537
doublevar = 331.99
doublevar = 8.440000e+11
doublevar = 8.44e+11
charvar = W
boolvar = 0

*/

