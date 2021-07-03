#include <stdio.h>
#include <string.h>
int main()
{
    char src[50], dest[50];
    strcpy(src,"This is source");
    strcpy(dest,"This is destination");
    strncat(dest,src,(sizeof(src)/sizeof(char))+1);
    printf("Concatenated str: %s",dest);
    return 0;
}
/* Output: 
Concatenated str: This is destinationThis is source
*/
