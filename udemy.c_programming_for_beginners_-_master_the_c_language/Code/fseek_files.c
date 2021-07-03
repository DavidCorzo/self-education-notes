#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp = NULL; 

    fp = fopen("data.txt","r+");

    fseek(fp,7,SEEK_SET);
    fputs("@",fp);
    

    fclose(fp);
    return 0;
}
/* Input: in file
012345678910 <- insert on 7 a @
*/
/* Output: 
0123456@8910 <- insert on 7 a @
*/

 