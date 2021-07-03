#include <stdio.h>
int main()
{
    printf("int: %zd\n",sizeof(int));
    printf("char: %zd\n",sizeof(char));
    printf("long: %zd\n",sizeof(long));
    printf("short: %zd\n",sizeof(short));
    printf("long long: %zd\n",sizeof(long long));
    printf("double: %zd\n",sizeof(double));
    printf("long double: %zd\n",sizeof(long double));
    return 0;
}
/* Output: 
int: 4
char: 1
long: 8
short: 2
long long: 8
double: 8
long double: 16

*/
