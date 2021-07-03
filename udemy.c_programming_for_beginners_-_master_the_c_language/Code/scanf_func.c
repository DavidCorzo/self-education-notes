#include <stdio.h>
int main()
{
    char str[100];
    int i; double x; 
    printf("Enter a value: ");
    // read a integer first (space) a string
    scanf("%d %s %lf", &i, str, &x);
    printf("\nYou entered: %d %s %lf\n", i, str, x);
    return 0;
}
/* Output: 
Enter a value: 25 string 45.268

You entered: 25 string 45.268000

*/
