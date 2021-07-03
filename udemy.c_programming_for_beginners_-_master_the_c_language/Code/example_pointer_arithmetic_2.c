#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    long multiple[] = {15L,25L,35L,45L};
    long *p = multiple; 

    for (int i = 0; i < (sizeof(multiple)/sizeof(multiple[0])); ++i){
        printf(
            "address p+%d (&multiple[%d]): %llu  *(p+%d)  value: %d\n",
            i,i,(unsigned long long)(p+i), i, *(p+i)
        );
    }
    printf("\nType long occupies %d bytes\n", (int)sizeof(long));
    return 0;
}
/* Output: 
address p+0 (&multiple[0]): 4294953936  *(p+0)  value: 15
address p+1 (&multiple[1]): 4294953944  *(p+1)  value: 25
address p+2 (&multiple[2]): 4294953952  *(p+2)  value: 35
address p+3 (&multiple[3]): 4294953960  *(p+3)  value: 45

Type long occupies 8 bytes

*/
