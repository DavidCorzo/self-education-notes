#include <stdio.h>
#include <stdlib.h>

int str_lenght(const char *str);

int main()
{
    printf("str_lenght: %d\n",str_lenght("hello"));
    printf("str_lenght: %d\n",str_lenght("01234"));
    printf("str_lenght: %d\n",str_lenght("this is a string"));
    printf("str_lenght: %d\n",str_lenght("what is the lenght?"));
    printf("str_lenght: %d\n",str_lenght(""));
    return 0;
}
int str_lenght(const char *str){
    char const *begining = str;
    while (*str){
        ++str;
    }
    return (str - begining);
}
/* Output: 
str_lenght: 5
str_lenght: 5
str_lenght: 16
str_lenght: 19
str_lenght: 0

*/
