#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int  length(const char str[]);
bool compare(const char str1[], const char str2[]);
void concatenate(char result[], char str1[], char str2[]);

int main()
{
    char str1[] = "Hello World";
    char str2[] = "Hello Worl";
    char result[length(str1) + length(str2) + 1];
    printf("%d\n",length(str1));
    printf("%d\n",compare(str1,str2));
    concatenate(result,str1,str2);
    printf("%s",result);

    return 0;
}


int  length(const char str[]){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i + 1;
}
void concatenate(char result[], char str1[], char str2[]){
    int i,j;
    for (i = 0; str1[i] != '\0'; ++i) result[i] = str1[i];
    for (j = 0; str2[j] != '\0'; ++j) result[i + j] = str2[j];
    result[i + j] = '\0';
}
bool compare(const char str1[], const char str2[]){
    int i = 0;
    if (length(str1) == length(str2)){
        while (str1[i] != '\0' && str2[i] != '\0'){
            if (str1[i] != str2[i] ){
                return false;
            }
            ++i;
        } 
        return true;
    } else {
        return false;
    }
}
/* Output: 
12
0
Hello WorldHello Worl
*/
