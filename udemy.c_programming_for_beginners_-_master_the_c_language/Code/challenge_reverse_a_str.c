#include <stdio.h>
#include <string.h>
char reverse(char reversed[], const char str[]);

int main()
{   
    char str[] = "Hello world";
    char reversed[strlen(str)];
    reverse(reversed,str);
    printf("%s",reversed);
    return 0;
}

char reverse(char reversed[], const char str[]){
    int i,j;
    for (i = 0, j = strlen(str) - 1; i < strlen(str);){
        reversed[i] = str[j];
        i++;
        j--;
    }
    reversed[i] = '\0';
}

/* Output: 
dlrow olleH
*/
