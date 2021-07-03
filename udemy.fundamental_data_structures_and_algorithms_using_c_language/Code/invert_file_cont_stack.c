#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *item;
    int top; 
    int size; 
} Stack; 

// Prototype declarations
void push(Stack *, char );
char pop(Stack *);
void init(Stack *, int);
void print_s(Stack *);
void deallocate(Stack *);
bool isUnderFlow(Stack *);
bool isOverFlow(Stack *);
int reverse(char[], char[]);


int main()
{
    reverse("data.txt","data_inverse.txt");
    return 0;
}

int reverse(char src[], char dest[]){
    FILE *fp = NULL; 
    Stack sp;

    fp = fopen(src,"r");
    if (fp == NULL){
        printf("Error opening file %s.",src);
        return 0;
    } 

    // figuring out the number of chars in the file.
    fseek(fp,0,SEEK_END);
    const int filesize = ftell(fp); 
    rewind(fp); // setting fp to the beggining.

    // initializing sp
    init(&sp,filesize+1);

    char c = fgetc(fp);
    while (!feof(fp)){
        push(&sp,c);
        c = fgetc(fp);
    }

    fclose(fp);

    // opening new file to paste the inverted data to the next file.
    fp = fopen(dest,"w+");
    if (fp == NULL){
        printf("Error opening file %s.",dest);
        return 0;
    }

    while (!isUnderFlow(&sp)){
        fputc(pop(&sp),fp);
    }
    
    fclose(fp);
    deallocate(&sp);
    fp = NULL;
    return 1;
}

bool isUnderFlow(Stack *sp){
    return sp->top == -1;
}

bool isOverFlow(Stack *sp){
    return sp->top == sp->size - 1;
}

void push(Stack *sp, char value ){
    if (sp->top == sp->size -1){
        printf("Stack overflow.\n");
        sp->item = (char*)realloc(sp->item,sizeof(sp->size)*2);
        if (sp->item == NULL)
            printf("Error in realloc.\n");
        sp->size *= 2;
    }
    ++sp->top;
    sp->item[sp->top] = value;
}

char pop(Stack *sp){
    if (sp->top == -1){
        printf("Stack underflow.\n");
        return '\0';
    }
    --sp->top; 
    return sp->item[sp->top + 1];
}

void init(Stack *sp, int size){
    sp->top = -1;
    sp->item = (char*) malloc(size * sizeof(char));
    if (sp->item == NULL){
        printf("Error.\n");
        exit(1);
    }
    sp->size = size;
}

void print_s(Stack *sp){
    for (int i = 0; i < sp->top; i++) {
        printf("%c",sp->item[i]);
    }
}

void deallocate(Stack *sp){
    if (sp->item != NULL)
        free(sp->item);
    sp->top = -1; 
    sp->size = 0;
}
/* Input: in file
Hello World!

*/
/* Output: 

!dlroW olleH
*/
