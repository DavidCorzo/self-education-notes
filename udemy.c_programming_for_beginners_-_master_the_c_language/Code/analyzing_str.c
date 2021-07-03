#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFF 100
int main()
{
    char buff[BUFF]; // input buffer 
    int nLetters = 0; // # of letters to input
    int nDigits = 0; // # of digits in input
    int nPunct = 0;  // # of punctuation characters
    printf("Enter an string of less than %d characters: ",BUFF); 
    scanf("%s",buff); // read a string to a buffer.
    getchar();
    int i = 0;
    while (buff[i]){
        if (isalpha(buff[i])){
            ++nLetters;
        } else if (isdigit(buff[i])){
            ++nDigits;
        } else if (ispunct(buff[i])){
            ++nPunct;
        }
        ++i;
    }
    printf("\nYour string contained %d letter, %d digits and %d punctuation characters.\n",nLetters, nDigits, nPunct);
    return 0;
}
/* Output: 
Enter an string of less than 100 characters: asdakdl81289asdnaskd1289njadjasdas..asd,as.d,asd.ad    

Your string contained 36 letter, 9 digits and 6 punctuation characters.

*/
