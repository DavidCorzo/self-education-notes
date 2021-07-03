#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[10], str2[10], str3[10];
    int year;
    FILE *fp;

    fp = fopen("ffile.txt","w+");
    if (fp != NULL){
        fputs("Hello how are 2020",fp);
    }

    rewind(fp);

    fscanf(fp,"%s %s %s %d", str1, str2, str3, &year);

    printf("Read string 1: |%s|\n",str1);
    printf("Read string 1: |%s|\n",str2);
    printf("Read string 1: |%s|\n",str3);
    printf("Read integer 1: |%d|\n",year);
    
    fclose(fp);

    return 0;
}
/* Output: 
Read string 1: |Hello|
Read string 1: |how|
Read string 1: |are|
Read integer 1: |2020|

*/
