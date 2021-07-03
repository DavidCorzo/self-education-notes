#include <stdio.h>
#include <string.h>
int main()
{   
    char s[] = "My name is David";
    printf("The length is: %d\n",strlen(s));
    char temp[strlen(s)+1];
    strncpy(temp,s,sizeof(temp)+1);
    printf("temp is: %s\n",temp);
    
    return 0;
}
/* Output: 
The length is: 16
temp is: My name is David

*/
