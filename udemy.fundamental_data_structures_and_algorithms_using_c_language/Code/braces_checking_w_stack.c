#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char item[SIZE];
    int top; 
} Stack; 

// function prototypes 
void push(Stack *, char);
char pop(Stack *);
int isEmpty(Stack *);
char stacktop(Stack *);

// utility function prototypes
int isOpenMatch(char, char);

// the bracket checking program function protoype
bool checkExpr(char[]);
void print_s(Stack *);

void push(Stack *sp, char c){
    if (sp->top == SIZE - 1){
        printf("Stack overflow.\n");
        exit(1);
    }
    sp->top += 1;
    sp->item[sp->top] = c; 
}


char pop(Stack *sp){
    if (sp->top == -1){
        printf("Stack underflow");
        exit(1);
    }
    return sp->item[sp->top--];
}


int isEmpty(Stack *sp){
    return sp->top == -1;
}


char stacktop(Stack *sp){
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

void print_s(Stack *sp){
    for (int i = 0; i < sp->top; i++){
        printf("stack: %c\n",sp->item[i]);
    }
}

bool checkExpr(char str[]){
    bool error = false; 
    Stack s = {.top=-1};

    int i = 0;
    while (str[i] != '\0'){
        if ( (str[i] == '(') || (str[i] == '{') || (str[i] == '[')){
            push(&s,str[i]);
        } else if ( (str[i] == ')') || (str[i] == '}') || (str[i] == ']')){
            if (isEmpty(&s)) {
                error = true;
                break;
            } else if (isOpenMatch(stacktop(&s),str[i])) {
                pop(&s);
            } else {
                error = true; 
                break; 
            }
        }
        i++;
    }

    if (!error && !isEmpty(&s)) {
        error = true; 
    }

    return error; 
}


int main() {
    char expr[SIZE]; 
    printf("Input expression: ");
    scanf("%[^\n]%*c",expr);

    printf("\n%s\n",expr);

    checkExpr(expr)? printf("Not well formed.\n") : printf("Well formed.\n");

    return 0;
}

/* Output: 
Input expression: {()[]}

{()[]}
Well formed.

*/
