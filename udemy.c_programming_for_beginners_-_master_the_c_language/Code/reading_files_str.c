#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp; 
    int c; 
    char str[10];

    fp = fopen("file.txt","r");

    if (fp == NULL){
        perror("Error in opening file.");
        return (-1);
    }

    if (fgets(str,10,fp) != NULL){
        /* writing content to stdout */
        printf("%s",str);
    }
    return 0;
}
/* Output: 
hello

*/
