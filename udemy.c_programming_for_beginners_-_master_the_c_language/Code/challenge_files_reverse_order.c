#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "lines.txt"

int main()
{
    FILE *fp = NULL;
    char ch;
    int i = 0, end = 0;

    fp = fopen(FILENAME,"r");

    if (fp == NULL){
        perror("Error opening: ");
        printf("%s",FILENAME);
    }

    // move the file pointer to the end
    fseek(fp,0,SEEK_END);

    // figure out the complete byte size
    end = ftell(fp);

    // print the reverse
    while (i < end){
        i++;
        fseek(fp,-i,SEEK_END);
        printf("%c",fgetc(fp));
    }

    // Close The file
    fclose(fp);
    fp = NULL;    
    
    return 0;
}
/* Input: 
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
/* Output: 

.subicuaf
surup eativ rotrot ca mallun itnetop essidnepsus
arreviV .des cnun sittam ranivlup sarC .sarc sullet
tema tis tege teuqila arreviv mes tU .mauqila
tu tile gnicsipida rutetcesnoC .ibrom ereusop
sillavnoc arterahp saneceam satsege siprut ca semaF
.tu etatupluv maid mine cenoD .siuq satsege te
euqitsirt tu mudnebiB .ta rotrot mine teuqila allun
euqitsirt seicirtlU .tnudicnit assam teidrepmi
siuq odommoc siruam temA .oido des sisilicaf ue
mutnemele tA .eranro ni subicuaf iud mutnemref
euqsirelecs sitrobol mine siuQ .siuq domsiue
susruc ucra ni maid satsege euqsiuq eugnoc satsegE
.odommoc siuq ibrom oido des sisilicaf
ue mutnemele ta eitseloM .auqila angam erolod
te erobal tu tnudidicni ropmet domsuie od des ,tile
gnicsipida rutetcesnoc ,tema tis rolod muspi meroL
*/
