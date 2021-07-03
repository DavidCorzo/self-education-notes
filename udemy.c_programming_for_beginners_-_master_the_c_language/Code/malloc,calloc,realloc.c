#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *str = NULL; // no memory allocated to it
    /* intial memory allocation */ 
    str = (char*)malloc(strlen("jason")*sizeof(char)); // creates memory for 6 chars
    strcpy(str,"jason"); 
    printf("String = %s, Address = %p\n",str,str);

    /* Whoops, we didn't allocate enough memory to store
    ".com", no problem, use realloc */
    
    /* reallocating memory */
    str = (char*)realloc(str,strlen("jason.com")*sizeof(char)); // creates an aditional 4 bytes
    strcat(str,".com"); 
    printf("String = %s, Address = %p\n", str, str);

    /* free the used memory */
    free(str); // always call free when you call malloc 

    return 0;
}
/* Output: 
String = jason, Address = 0x8000284d0
String = jason.com, Address = 0x8000284d0

*/
