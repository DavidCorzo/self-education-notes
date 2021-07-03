#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *filePointer; 
    
    filePointer = fopen("file.txt","w+");

    // write two lines. 
    fputs("This is a string.",filePointer);
    fputc('\n',filePointer);
    fputs("Great",filePointer);
    fputc('\n',filePointer);

    fclose(filePointer);
    return 0;
}
/* Output: in file
This is a string.
Great

*/
