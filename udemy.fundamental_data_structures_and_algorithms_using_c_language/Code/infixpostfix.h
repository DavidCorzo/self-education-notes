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
void push_op(OperatorStack *, char);
char pop_op(OperatorStack *);
int isEmpty_op(OperatorStack *);
char stacktop_op(OperatorStack *);

// utility function prototypes
int isOpenMatch_op(char, char);
double operate_op(double, double, char);
bool isOperator_op(char c);
void print_s_op(OperatorStack *);
void infix_to_postfix_op(char [], char []);
bool precedence_op(char, char);
bool isOperand_op(char);

void push_op(OperatorStack *sp, char c){
    if (sp->top == SIZE - 1){
        printf("Stack overflow.\n");
        exit(1);
    }
    sp->top += 1;
    sp->item[sp->top] = c; 
}


char pop_op(OperatorStack *sp){
    if (sp->top == -1){
        printf("Stack underflow");
        exit(1);
    }
    return sp->item[sp->top--];
}


int isEmpty_op(OperatorStack *sp){
    return sp->top == -1;
}


char stacktop_op(OperatorStack *sp){
    if (isEmpty_op(sp)){
        printf("Stack underflow, terminating program.\n");
        exit(1);
    }
    return sp->item[sp->top];
}

bool isOperator_op(char c){
    return  (c == '+') ||
            (c == '-') || 
            (c == '*') || 
            (c == '/') || 
            (c == '$') ||
            (c == '(') ||
            (c == ')');
}

void print_s_op(OperatorStack *sp){
    for (int i = 0; i < sp->top; i++){
        printf("stack: %c\n",sp->item[i]);
    }
}

bool precedence_op(char stack_top, char token){
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

bool isOperand_op(char token){
    return (token >= '0' && token <= '9');
}


void infix_to_postfix_op(char infix[], char postfix[]){
    int j = 0, i = 0;
    OperatorStack stack = {.top=-1}; 
    while (infix[i] != '\0'){
        char token = infix[i];
        // if the token is an operand.
        if (isOperand_op(token)){
            postfix[j++] = token;
        // if the token is an operator.
        } else if (isOperator_op(token)){
            while ((!isEmpty_op(&stack)) && (precedence_op(stacktop_op(&stack),token))){
                char top_operator = pop_op(&stack);
                postfix[j++] = top_operator;
            }
            if (token == ')'){
                pop_op(&stack); // discard the )
            } else {
                push_op(&stack,token);
            }
        } else {
            printf("Invalid symbol encountered \"%c\".\n",token);
            exit(1);
        }
        i++;
    }

    while (!isEmpty_op(&stack)){
        char top_operator = pop_op(&stack);
        postfix[j++] = top_operator;
    }

    postfix[j] = '\0';
}

