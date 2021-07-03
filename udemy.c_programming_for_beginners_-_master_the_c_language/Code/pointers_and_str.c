#include <stdio.h>
#include <stdlib.h>

void copyStringArr(char to[], char from[]);
void copyStringPtr(char to[], char from[]);

int main()
{
    char from[] = "hello";
    char to[6]; 
    copyStringArr(to,from);
    printf("copyStringArr: %s\n",to);
    copyStringPtr(to,from);
    printf("copyStringArr: %s\n",to);
    return 0;
}
void copyStringArr(char to[], char from[]){
    int i;
    for (i = 0; from[i] != '\0'; ++i ){
        to[i] = from[i];
    }
    to[i] = '\0';
}
// More eficient
void copyStringPtr(char to[], char from[]){
    for (; *from != '\0'; ++from, ++to){
        *to = *from; 
    }
    *to = '\0';
}
/* Output: 
copyStringArr: hello
copyStringArr: hello

*/
