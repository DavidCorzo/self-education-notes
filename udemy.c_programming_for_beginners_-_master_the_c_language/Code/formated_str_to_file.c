#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp; 

    fp = fopen("file.txt","w+");

    if (fp == NULL){
        printf("Error");
        exit(-1);
    }
        
        
    fprintf(fp, "%s %s %s %s %d", "Hello", "My", "Number", "is", 502);

    fclose(fp);

    fp = NULL; 

    return 0;
}
/* Output: in file
Hello My Number is 502
*/
