#include <stdio.h>
int main()
{
    float value1, value2;
    char operator;
    printf("Type in your expression.\n");
    scanf("%f %c %f",&value1,&operator,&value2);
    switch (operator) {
        case '+': printf("%.2f\n",value1 + value2); break; 
        case '-': printf("%.2f\n",value1 - value2); break; 
        case '*': printf("%.2f\n",value1 * value2); break; 
        case '/': value2 == 0 ? printf("division by zero error"): printf("%.2f\n",value1 / value2); break; 
        default: printf("unknown operator\n"); break;
    }
    return 0;
}
/* Output: 
Type in your expression.
45+5
50.00

*/
