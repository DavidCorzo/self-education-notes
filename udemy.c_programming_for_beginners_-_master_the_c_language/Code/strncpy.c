#include <stdio.h>
#include <string.h>
int main(){
    char src[50], dest[50];
    strcpy(src,"String copy");
    strncpy(dest,src,50);
    printf("strncpy(): %s\n",dest); 
    return 0; 
}
/* Output: 
strncpy(): String copy

*/
