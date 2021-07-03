#include <stdio.h>
#include <string.h>
int main()
{
    printf("strcmp(\"A\",\"A\")\n");
    printf(" %d\n",strcmp("A","A"));
    printf("strcmp(\"B\",\"b\")\n");
    printf(" %d\n",strcmp("B","b"));
    printf("strcmp(\"C\",\"c\")\n");
    printf(" %d\n",strcmp("C","C"));
    return 0;
}
/* Output: 
strcmp("A","A")
 0
strcmp("B","b")
 -1
strcmp("C","c")
 0

*/
