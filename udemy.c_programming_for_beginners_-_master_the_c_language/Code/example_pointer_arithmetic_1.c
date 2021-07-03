#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char multiple[] = "a string";
    char *p = multiple; // multiple is already a pointer.

    for (int i = 0; i < strnlen(multiple, sizeof(multiple)); ++i){
        printf(
            "multiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d 0 %p\n",
            i, multiple[i],i,*(p+i),i,&multiple[i],i,p+i
        );
    }
    return 0;
}
/* Output: 
multiple[0] = a *(p+0) = a &multiple[0] = 0xffffcbd7 p+0 0 0xffffcbd7
multiple[1] =   *(p+1) =   &multiple[1] = 0xffffcbd8 p+1 0 0xffffcbd8
multiple[2] = s *(p+2) = s &multiple[2] = 0xffffcbd9 p+2 0 0xffffcbd9
multiple[3] = t *(p+3) = t &multiple[3] = 0xffffcbda p+3 0 0xffffcbda
multiple[4] = r *(p+4) = r &multiple[4] = 0xffffcbdb p+4 0 0xffffcbdb
multiple[5] = i *(p+5) = i &multiple[5] = 0xffffcbdc p+5 0 0xffffcbdc
multiple[6] = n *(p+6) = n &multiple[6] = 0xffffcbdd p+6 0 0xffffcbdd
multiple[7] = g *(p+7) = g &multiple[7] = 0xffffcbde p+7 0 0xffffcbde

*/
