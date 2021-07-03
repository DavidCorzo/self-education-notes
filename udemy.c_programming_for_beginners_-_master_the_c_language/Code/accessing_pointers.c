#include <stdio.h>
int main()
{
    int number = 0; // var of type int
    int *pnumber = NULL; // a pointer that can point to type int
    number = 10; 
    printf("number's address: %p\n",&number); // output the address
    printf("number's   value: %d\n\n",number); // output the value

    pnumber = &number; // store address of number in pnumber.

    printf("pnumber's address: %p\n",(void*)&pnumber); // output the address
    printf("pnumbe's     size: %zd bytes\n",sizeof(pnumber)); // output the size 
    printf("pnumber's   value: %p\n",pnumber); // output the value (an address)
    printf("value pointed to: %d\n",*pnumber); // value at the address, dereferencion with *
    return 0;
}
/* Output: 
number's address: 0xffffcbfc
number's   value: 10

pnumber's address: 0xffffcbf0
pnumbe's     size: 8 bytes
pnumber's   value: 0xffffcbfc
value pointed to: 10

*/
