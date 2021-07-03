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
void push(OperandStack *, double);
double pop(OperandStack *);
int isEmpty(OperandStack *);
char stacktop(OperandStack *);

// utility function prototypes
int isOpenMatch(char, char);
double operate(double, double, char);
bool isOperator(char c);
double evalPostfix(char[]);
void print_s(OperandStack *);


void push(OperandStack *sp, double c){
    if (sp->top == SIZE - 1){
        printf("Stack overflow.\n");
        exit(1);
    }
    sp->top += 1;
    sp->item[sp->top] = c; 
}


double pop(OperandStack *sp){
    if (sp->top == -1){
        printf("Stack underflow");
        exit(1);
    }
    return sp->item[sp->top--];
}


int isEmpty(OperandStack *sp){
    return sp->top == -1;
}


char stacktop(OperandStack *sp){
    if (isEmpty(sp)){
        printf("Stack underflow, terminating program.\n");
        exit(1);
    }
    return sp->item[sp->top];
}

int isOpenMatch(char opening, char closing){
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

double operate(double left, double right, char operator){
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

bool isOperator(char c){
    return  (c == '+') ||
            (c == '-') || 
            (c == '*') || 
            (c == '/') || 
            (c == '$');
}

double evalPostfix(char postfix[]){
    OperandStack stack = {.top=-1};
    int i = 0; 
    while (postfix[i] != '\0'){
        char token = postfix[i];
        if (token >= '0' && token <= '9'){
            int v = token - '0'; // you can also use a atoi func
            push(&stack,(double)v);
        } else if (isOperator(token)){
            double right = pop(&stack); 
            double left = pop(&stack);
            double result = operate(left, right, token);
            push(&stack,result);
        } else {
            printf("Invalid symbol encontered \"%c\"",token);
            exit(1);
        }
        ++i;
    }
    return pop(&stack);
}

void print_s(OperandStack *sp){
    for (int i = 0; i < sp->top; i++){
        printf("stack: %c\n",sp->item[i]);
    }
}

int main() {
    char postfix[SIZE];
    printf("Input postfix expression: ");
    scanf("%[^\n]%*c",postfix);

    printf("Result is: %lf", evalPostfix(postfix));

    return 0;
}

/* Output: 
Input postfix expression: 45+
Result is: 9.000000
*/
/* Output: 
Input postfix expression: 45+36-*
Result is: -27.000000
*/
