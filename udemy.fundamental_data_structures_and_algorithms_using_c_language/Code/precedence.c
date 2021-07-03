#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool precedence(char stack_top, char token){
    /* ( is less precedente than (, 
    there are anidated parenthesis */
    if (stack_top == '(' || token == '('){
        return false;
    } 
    /* if token is ) says that it is closing the expression
     within a higher precedence parenthesis */
    if (token == ')'){
        return true; 
    }   

    /* the *,/ has the higher precedence than all the
     other operands except $ */
    if (stack_top == '*' || stack_top == '/'){
        /* In this case the stack top operator has a higher precedence */
        if (token == '*' || token == '/' || token == '+' || token == '-'){
            return true;
        /* In this case it does not */
        } else {
            return false; 
        }
    }

    /* the stack_top can be +,- which have the same precedence */
    if (stack_top == '+' || stack_top == '-'){
        if (token == '+' || token == '-'){
            return true; 
        } else {
            return false; 
        }
    }

    /* the $ has the highest precedence of them all */
    if (stack_top == '$'){
        return true;
    } else {
        return false; 
    }
}
// ()+*/$-
int main(){
    // + in comparison with all other operators
    printf("precedence('+','+') = %s\n",precedence('+','+')?"true":"false"); // + +
    printf("precedence('+','-') = %s\n",precedence('+','-')?"true":"false"); // + -
    printf("precedence('+','*') = %s\n",precedence('+','*')?"true":"false"); // + * 
    printf("precedence('+','/') = %s\n",precedence('+','/')?"true":"false"); // + /
    printf("precedence('+','$') = %s\n",precedence('+','$')?"true":"false"); // + $
    printf("precedence('+','(') = %s\n",precedence('+','(')?"true":"false"); // + (
    printf("precedence('+',')') = %s\n",precedence('+',')')?"true":"false"); // + )

    // - in comparison with all other operators
    printf("precedence('-','+') = %s\n",precedence('-','+')?"true":"false");
    printf("precedence('-','-') = %s\n",precedence('-','-')?"true":"false");
    printf("precedence('-','*') = %s\n",precedence('-','*')?"true":"false");
    printf("precedence('-','/') = %s\n",precedence('-','/')?"true":"false");
    printf("precedence('-','$') = %s\n",precedence('-','$')?"true":"false");
    printf("precedence('-','(') = %s\n",precedence('-','(')?"true":"false");
    printf("precedence('-',')') = %s\n",precedence('-',')')?"true":"false");
    
    // * in comparison with all other operators
    printf("precedence('*','+') = %s\n",precedence('*','+')?"true":"false");
    printf("precedence('*','-') = %s\n",precedence('*','-')?"true":"false");
    printf("precedence('*','*') = %s\n",precedence('*','*')?"true":"false");
    printf("precedence('*','/') = %s\n",precedence('*','/')?"true":"false");
    printf("precedence('*','$') = %s\n",precedence('*','$')?"true":"false");
    printf("precedence('*','(') = %s\n",precedence('*','(')?"true":"false");
    printf("precedence('*',')') = %s\n",precedence('*',')')?"true":"false");

    // / in comparison with all operators
    printf("precedence('/','+') = %s\n",precedence('*','+')?"true":"false");
    printf("precedence('/','-') = %s\n",precedence('*','-')?"true":"false");
    printf("precedence('/','*') = %s\n",precedence('*','*')?"true":"false");
    printf("precedence('/','/') = %s\n",precedence('*','/')?"true":"false");
    printf("precedence('/','$') = %s\n",precedence('*','$')?"true":"false");
    printf("precedence('/','(') = %s\n",precedence('*','(')?"true":"false");
    printf("precedence('/',')') = %s\n",precedence('*',')')?"true":"false");

    // $ in comparison with all other operators
    printf("precedence('$','+') = %s\n",precedence('$','+')?"true":"false");
    printf("precedence('$','-') = %s\n",precedence('$','-')?"true":"false");
    printf("precedence('$','*') = %s\n",precedence('$','*')?"true":"false");
    printf("precedence('$','/') = %s\n",precedence('$','/')?"true":"false");
    printf("precedence('$','$') = %s\n",precedence('$','$')?"true":"false");
    printf("precedence('$','(') = %s\n",precedence('$','(')?"true":"false");
    printf("precedence('$',')') = %s\n",precedence('$',')')?"true":"false");

    // ( in comparison with all other operators
    printf("precedence('(','+') = %s\n",precedence('(','+')?"true":"false");
    printf("precedence('(','-') = %s\n",precedence('(','-')?"true":"false");
    printf("precedence('(','*') = %s\n",precedence('(','*')?"true":"false");
    printf("precedence('(','/') = %s\n",precedence('(','/')?"true":"false");
    printf("precedence('(','$') = %s\n",precedence('(','$')?"true":"false");
    printf("precedence('(','(') = %s\n",precedence('(','(')?"true":"false");
    printf("precedence('(',')') = %s\n",precedence('(',')')?"true":"false");

    // ) in comparison with all other operators
    printf("precedence(')','+') = %s\n",precedence(')','+')?"true":"false");
    printf("precedence(')','-') = %s\n",precedence(')','-')?"true":"false");
    printf("precedence(')','*') = %s\n",precedence(')','*')?"true":"false");
    printf("precedence(')','/') = %s\n",precedence(')','/')?"true":"false");
    printf("precedence(')','$') = %s\n",precedence(')','$')?"true":"false");
    printf("precedence(')','(') = %s\n",precedence(')','(')?"true":"false");
    printf("precedence(')',')') = %s\n",precedence(')',')')?"true":"false");

    return 0;
}

/* Output: 
false:
precedence('+','*') = false
precedence('+','/') = false
precedence('+','$') = false
precedence('+','(') = false
precedence('-','*') = false
precedence('-','/') = false
precedence('-','$') = false
precedence('-','(') = false
precedence('*','$') = false
precedence('*','(') = false
precedence('/','$') = false
precedence('/','(') = false
precedence('$','(') = false
precedence('(','+') = false
precedence('(','-') = false
precedence('(','*') = false
precedence('(','/') = false
precedence('(','$') = false
precedence('(','(') = false
precedence('(',')') = false
precedence(')','+') = false
precedence(')','-') = false
precedence(')','*') = false
precedence(')','/') = false
precedence(')','$') = false
precedence(')','(') = false


precedence('+','+') = true
precedence('+','-') = true
precedence('+',')') = true
precedence('-','+') = true
precedence('-','-') = true
precedence('-',')') = true
precedence('*','+') = true
precedence('*','-') = true
precedence('*','*') = true
precedence('*','/') = true
precedence('*',')') = true
precedence('/','+') = true
precedence('/','-') = true
precedence('/','*') = true
precedence('/','/') = true
precedence('/',')') = true
precedence('$','+') = true
precedence('$','-') = true
precedence('$','*') = true
precedence('$','/') = true
precedence('$','$') = true
precedence('$',')') = true
precedence(')',')') = true
*/
