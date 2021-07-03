#include <stdio.h>
#include <stdlib.h>
int main()
{
    int bytes = 0;
    char *str = NULL;
    printf("Enter the number of bytes: \n");
    scanf("%d",&bytes);
    str = (char *) malloc(bytes*sizeof(char));

    if (str != NULL){
        printf("Enter some text: \n");
        scanf(" ");
        gets(str);
        printf("Inputted text is: %s\n",str);
    }

    free(str);
    str = NULL; 
    return 0;
}
/* Output: 
Enter the number of bytes:
10
Enter some text:
DavidC
Inputted text is: DavidC

*/
