#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "upper.txt"
#define TEMPORARY "temp.txt"

int main()
{
    FILE *fp = NULL, *fptemp = NULL;
    char ch;

    // Reading in information from file
    fp = fopen(FILENAME,"r");
    if (fp == NULL){
        perror("Error on reading file: ");
        printf("%s",FILENAME);
        exit(-1);
    }

    // Creation of temporary file.
    fptemp = fopen(TEMPORARY,"w+");

    while ((ch=fgetc(fp)) != EOF){
        if (islower(ch))
            ch = toupper(ch);
        fputc(ch,fptemp);
    }

    fclose(fp);
    fclose(fptemp);

    // Remove the FILENAME
    remove(FILENAME);

    // Rename temp file to FILENAME
    rename(TEMPORARY,FILENAME);
    
    // Remove the temp file.
    remove(TEMPORARY);

    fp = fopen(FILENAME,"r");

    while ((ch=fgetc(fp)) != EOF){
        printf("%c",ch);
    }
    
    return 0;
}
/* Input: in file
this is lowecase
THIS IS UPPERCASE?
is everything uppercase?

*/
/* Output:
THIS IS LOWECASE
THIS IS UPPERCASE?
IS EVERYTHING UPPERCASE?

*/
