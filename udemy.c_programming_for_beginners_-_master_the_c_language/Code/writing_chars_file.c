#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp; 
    int ch; 

    fp = fopen("file.txt","w+");

    for (ch = 33; ch <= 100; ch ++){
        fputc(ch,fp); // writes a single ascii char
    } // you can use the atoi function to write other data types as well.

    fclose(fp);
    
    fp = NULL;
    
    return 0;
}
/* Output: in file
!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcd
*/
