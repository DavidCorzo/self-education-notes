#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for the strlen()

void copyString(char *to, char *from);

int main()
{
    char str1[] = "string to be copied";
    char str2[strlen(str1)];
    copyString(str2,str1);
    printf("copyString: %s\n",str2);
    return 0;
}
void copyString(char *to, char *from){
    while (*from) // the null character is evaluated as a falsy value.
        *to++ = *from++; // assign and increment in the same line, this is a post incrementation operator. 
    *to = '\0'; // null character.
}
/* Output: 
copyString: string to be copied

*/
