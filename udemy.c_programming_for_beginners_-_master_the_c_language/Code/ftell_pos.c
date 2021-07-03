#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp = NULL; 
    int len; 
    fp = fopen("file.txt","r");

    if (fp == NULL){
        perror("Error opening file.");
        return (-1);
    }

    fseek(fp, 0, SEEK_END);

    len = ftell(fp);

    fclose(fp);

    fp = NULL;

    printf("Total size of file.txt = %d bytes",len);

    return 0;
}
/* Output: in file
Total size of file.txt = 24 bytes
*/
