#include "infixpostfix.h"
#include "evalpostfix.h"

int main()
{
    char infix[100] = "(8+9*7)$(7-4)";
    char postfix[100];

    infix_to_postfix_op(infix,postfix);

    double result = evalPostfix_opa(postfix);

    printf("%s\n",infix);
    printf("%s\n",postfix);
    printf("%lf",result);
    
    return 0;
}
/* Output: 
(8+9*7)$(7-4)
897*+74-$
357911.000000
*/
