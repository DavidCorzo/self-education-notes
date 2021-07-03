#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 100
int main()
{
    char text[size], substring[40];
    printf("Enter the string to be searched (less than %d characters): \n",strlen(substring));
    scanf("%s",text);
    getchar();
    printf("Enter the string sought (less than %d characters): \n",strlen(substring));
    scanf("%s",substring);
    getchar();
    printf("\nFirst string entered: \n%s\n",text);
    printf("Second string entered\n%s\n",substring);

    for (int i = 0; (text[i] = (char)toupper(text[i])) != '\0'; ++i);
    for (int i = 0; (substring[i] = (char)toupper(substring[i])) != '\0'; ++i);
    
    printf("The second string %s found in the first.\n",((strstr(text,substring) == NULL) ? "was not" : "was"));

    return 0;
}
/* Output: 
First string entered:
hello
Second string entered
llo
The second string was found in the first.

*/
