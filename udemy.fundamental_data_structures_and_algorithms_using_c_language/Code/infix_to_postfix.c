#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 100

typedef struct {
    char item[SIZE]; 
    int top; 
} OperatorStack;

// func for stack operations
void push(OperatorStack *, char);
char pop(OperatorStack *);
int isEmpty(OperatorStack *);
char stacktop(OperatorStack *);

// utility function prototypes
int isOpenMatch(char, char);
double operate(double, double, char);
bool isOperator(char c);
double evalPostfix(char[]);
void print_s(OperatorStack *);
void infix_to_postfix(char [], char []);
bool precedence(char, char);
bool isOperand(char);

void push(OperatorStack *sp, char c){
    if (sp->top == SIZE - 1){
        printf("Stack overflow.\n");
        exit(1);
    }
    sp->top += 1;
    sp->item[sp->top] = c; 
}


char pop(OperatorStack *sp){
    if (sp->top == -1){
        printf("Stack underflow");
        exit(1);
    }
    return sp->item[sp->top--];
}


int isEmpty(OperatorStack *sp){
    return sp->top == -1;
}


char stacktop(OperatorStack *sp){
    if (isEmpty(sp)){
        printf("Stack underflow, terminating program.\n");
        exit(1);
    }
    return sp->item[sp->top];
}

bool isOperator(char c){
    return  (c == '+') ||
            (c == '-') || 
            (c == '*') || 
            (c == '/') || 
            (c == '$') ||
            (c == '(') ||
            (c == ')');
}

void print_s(OperatorStack *sp){
    for (int i = 0; i < sp->top; i++){
        printf("stack: %c\n",sp->item[i]);
    }
}

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

bool isOperand(char token){
    return (token >= '0' && token <= '9');
}


void infix_to_postfix(char infix[], char postfix[]){
    int j = 0, i = 0;
    OperatorStack stack = {.top=-1}; 
    while (infix[i] != '\0'){
        char token = infix[i];
        // if the token is an operand.
        if (isOperand(token)){
            postfix[j++] = token;
        // if the token is an operator.
        } else if (isOperator(token)){
            while ((!isEmpty(&stack)) && (precedence(stacktop(&stack),token))){
                char top_operator = pop(&stack);
                postfix[j++] = top_operator;
            }
            if (token == ')'){
                pop(&stack); // discard the )
            } else {
                push(&stack,token);
            }
        } else {
            printf("Invalid symbol encountered \"%c\".\n",token);
            exit(1);
        }
        i++;
    }

    while (!isEmpty(&stack)){
        char top_operator = pop(&stack);
        postfix[j++] = top_operator;
    }

    postfix[j] = '\0';
}

int main() {
    char infix[SIZE];
    char postfix[SIZE];
    printf("Input: ");
    scanf("%s",infix);
    infix_to_postfix(infix, postfix);
    printf("\nOutput: %s",postfix);
    return 0;
}
/* Output: 
Input: (8+0*9)$(9+8+7-5)

Output: 809*+98+7+5-$
*/
