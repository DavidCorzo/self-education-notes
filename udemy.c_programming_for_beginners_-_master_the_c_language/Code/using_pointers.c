#include <stdio.h>
int main()
{
    long num1 = 0L;
    long num2 = 0L;
    long *pnum = NULL; 
    pnum = &num1;
    *pnum = 2L;    
    ++num2; 
    num2 += *pnum; 
    pnum = &num2; 
    ++*pnum;
    printf("num1 = %ld\n",num1);
    printf("num2 = %ld\n",num2);
    printf("*pnum = %ld\n",*pnum);
    printf("pnum = %p\n",pnum);
    printf("*pnum + num2 = %ld\n",*pnum+num2);
    return 0;
}
/* Output: 
num1 = 2
num2 = 4
*pnum = 4
pnum = 0xffffcbe8
*pnum + num2 = 8

*/
