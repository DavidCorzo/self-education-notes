#include <stdio.h>
int main()
{
    char str1[] = "To be or not to be";
    char str2[] = ",that is the question";
    unsigned int count = 0;
    while (str1[count] != '\0') ++count;
    printf("The lenght is: %s -> %d\n", str1, count);
    count = 0;
    while (str2[count] != '\0') ++count;
    printf("The lenght is: %s -> %d\n", str2, count);
    return 0;
}
/* Output: 
The lenght is: To be or not to be -> 18
The lenght is: ,that is the question -> 21

*/
