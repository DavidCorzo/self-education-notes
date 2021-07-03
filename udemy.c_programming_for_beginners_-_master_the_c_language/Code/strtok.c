#include <stdio.h>
#include <string.h>
int main()
{   
    char str[80] = "Hello-how-are-you";
    const char s[2] = "-";
    char *token;
    token = strtok(str,s);

    while (token != NULL){
        printf(" %s\n",token);
        token = strtok(NULL, s);
    }
    return 0;
}
/* Output: 
 Hello
 how
 are
 you

*/
