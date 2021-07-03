#include <stdio.h>
#include <string.h>
int main(){
    char src[50], dest[50];
    strcpy(src,"This is souce\n");
    strcpy(dest,"This is destination\n");
    printf("strcpy(): %s\nstrcpy(): %s",src,dest); 
    return 0; 
}
/* Output: 
strcpy(): This is souce

strcpy(): This is destination

*/
