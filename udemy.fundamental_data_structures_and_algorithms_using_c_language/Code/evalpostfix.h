#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define SIZE 100

typedef struct {
    double item[SIZE]; 
    int top; 
} OperandStack;


// func prototypes

// func for stack operations
void push_opa(OperandStack *, double);
double pop_opa(OperandStack *);
int isEmpty_opa(OperandStack *);
char stacktop_opa(OperandStack *);

// utility function prototypes
int isOpenMatch_opa(char, char);
double operate_opa(double, double, char);
bool isOperator_opa(char c);
double evalPostfix_opa(char[]);
void print_s_opa(OperandStack *);


void push_opa(OperandStack *sp, double c){
    if (sp->top == SIZE - 1){
        printf("Stack overflow.\n");
        exit(1);
    }
    sp->top += 1;
    sp->item[sp->top] = c; 
}


double pop_opa(OperandStack *sp){
    if (sp->top == -1){
        printf("Stack underflow");
        exit(1);
    }
    return sp->item[sp->top--];
}


int isEmpty_opa(OperandStack *sp){
    return sp->top == -1;
}


char stacktop_opa(OperandStack *sp){
    if (isEmpty_opa(sp)){
        printf("Stack underflow, terminating program.\n");
        exit(1);
    }
    return sp->item[sp->top];
}

int isOpenMatch_opa(char opening, char closing){
    bool match = false;
    switch (opening) {
        case '(':
            if (closing == ')') {
                match = true;
            }
            break;

        case '{':
            if (closing == '}'){
                match = true;
            }
            break;
        case '[':
            if (closing == ']'){
                match = true; 
            }
            break;
        default: 
            printf("Invalid symbol, program is terminating.");
            exit(1);
    }
    return match; 
}

double operate_opa(double left, double right, char operator){
    double result = 0;
    switch (operator){
        case '+': result = left + right;
                    break; 
        case '-': result = left - right;
                    break; 
        case '*': result = left * right;
                    break; 
        case '/': result = left / right;
                    break; 
        case '$': result = pow(left, right);
                    break; 
        default: printf("%c is not a valid operator\n",operator);
                    exit(1);
    }
    return result; 
}

bool isOperator_opa(char c){
    return  (c == '+') ||
            (c == '-') || 
            (c == '*') || 
            (c == '/') || 
            (c == '$');
}

double evalPostfix_opa(char postfix[]){
    OperandStack stack = {.top=-1};
    int i = 0; 
    while (postfix[i] != '\0'){
        char token = postfix[i];
        if (token >= '0' && token <= '9'){
            int v = token - '0'; // you can also use a atoi func
            push_opa(&stack,(double)v);
        } else if (isOperator_opa(token)){
            double right = pop_opa(&stack); 
            double left = pop_opa(&stack);
            double result = operate_opa(left, right, token);
            push_opa(&stack,result);
        } else {
            printf("Invalid symbol encontered \"%c\"",token);
            exit(1);
        }
        ++i;
    }
    return pop_opa(&stack);
}

void print_s_opa(OperandStack *sp){
    for (int i = 0; i < sp->top; i++){
        printf("stack: %c\n",sp->item[i]);
    }
}
