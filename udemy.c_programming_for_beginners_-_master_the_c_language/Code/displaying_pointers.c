#include <stdio.h>
int main()
{
    int number = 0; 
    int *pnumber = NULL; // good practice to initialize it to null.
    number = 10;
    pnumber = &number;
    printf("pnumber's   value: %p\n",pnumber);
    // print the address of number
    printf("number's  address: %p\n",&number); // the address of number
    printf("pnumber's address: %p\n",(void*)&pnumber); // address of the pointer
    // the (void*) is to get around a warning.
    return 0;
}
/* Output: 
pnumber's   value: 0xffffcbfc
number's  address: 0xffffcbfc
pnumber's address: 0xffffcbf0

*/

 