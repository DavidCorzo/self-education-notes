#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp = NULL; 
    fpos_t position; 

    fp = fopen("file.txt","w+");
    fgetpos(fp, &position);
    fputs("Hello, World!",fp);

    fclose(fp);

    return 0;
}
/* Output: in file
Hello, World!
*/
