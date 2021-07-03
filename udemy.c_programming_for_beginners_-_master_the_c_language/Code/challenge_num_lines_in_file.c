#include <stdio.h>
#include <stdlib.h>

#define FILENAME "lines.txt"

int main()
{
    FILE *fp = NULL;
    char ch;
    int lines = 0;

    fp = fopen(FILENAME,"r");

    if (fp == NULL){
        perror("Error opening file.");
        exit(-1);
    }

    while ((ch=fgetc(fp)) != EOF){
        if (ch == '\n')
            lines++;
    }

    fclose(fp);

    fp = NULL;

    printf("Total number of lines are: %d",lines);

    return 0;
}
/* Input: in file
Lorem ipsum dolor sit amet, consectetur adipiscing
elit, sed do eiusmod tempor incididunt ut labore et 
dolore magna aliqua. Molestie at elementum eu 
facilisis sed odio morbi quis commodo. 
Egestas congue quisque egestas diam in arcu cursus 
euismod quis. Quis enim lobortis scelerisque 
fermentum dui faucibus in ornare. At elementum 
eu facilisis sed odio. Amet mauris commodo quis 
imperdiet massa tincidunt. Ultricies tristique 
nulla aliquet enim tortor at. Bibendum ut tristique 
et egestas quis. Donec enim diam vulputate ut. 
Fames ac turpis egestas maecenas pharetra convallis 
posuere morbi. Consectetur adipiscing elit ut 
aliquam. Ut sem viverra aliquet eget sit amet 
tellus cras. Cras pulvinar mattis nunc sed. Viverra 
suspendisse potenti nullam ac tortor vitae purus 
faucibus.
*/
/* Output: in file
Total number of lines are: 17
*/
