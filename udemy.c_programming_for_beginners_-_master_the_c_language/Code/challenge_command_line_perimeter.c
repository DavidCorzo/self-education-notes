#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) // main parameters
{
    double height = atoi(argv[1]),width = atoi(argv[2]);
    printf("Enter the height and width: ");
    double perimeter = 2 * (height + width);
    printf("%.3f",perimeter);
    return 0;
}
/* Output: 
C:/Directory>helloworld.exe 10 10 
Enter the height and width: 40.000
*/
