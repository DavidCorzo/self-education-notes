#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node {
    int data; 
    struct Node *next;
} Node; 

typedef struct {
    struct Node *tail; 
    int nodeCount;
} CircularLinkedList; 

// function prototypes
void initList(CircularLinkedList *);
void insertNode(CircularLinkedList *, int);
void printList(CircularLinkedList *);
Node *find(CircularLinkedList *, int);
int deleteNode(CircularLinkedList *); 
void menu();

// helper functions
bool isEmpty(CircularLinkedList *);
// helper definitions
bool isEmpty(CircularLinkedList *clist){
    return (
        (clist->tail == NULL) || 
        (clist->nodeCount == 0)
    );
}


// function definitions
void initList(CircularLinkedList *clist){
    clist->nodeCount = 0; 
    clist->tail = NULL; 
}
void insertNode(CircularLinkedList *clist, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Could not allocate space for node.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(clist)){
        newNode->next = newNode;
    } else {
        newNode->next = clist->tail->next; 
        clist->tail->next = newNode;
    }

    clist->tail = newNode;
    clist->nodeCount++;
}
void printList(CircularLinkedList *clist){
    if (isEmpty(clist)){
        printf("Linked list is empty.\n");
        return;
    }
    bool done = false;
    Node *current = clist->tail->next;
    printf("[");
    while (!done){
        printf("%d, ",current->data);
        if (current == clist->tail){
            done = true; 
        }
        current = current->next;
    }
    printf("\b\b]\n");
}
Node *find(CircularLinkedList *clist, int target){
    if (isEmpty(clist)){
        printf("Linked list is empty.\n");
        return NULL;
    }
    bool done = false;
    Node *current = clist->tail->next;
    while (!done){
        printf("%4d",current->data);
        if (current->data == target){
            return current;
        }
        if (current == clist->tail){
            done = true; 
        } else {
            current = current->next;
        }
    }
    return NULL;
}
int deleteNode(CircularLinkedList *clist){
    if (isEmpty(clist)){
        printf("The linked list is empty.\n");
        return -9999;
    }
    Node *first = clist->tail->next;
    int data = first->data;
    if (clist->nodeCount == 1 || clist->tail == clist->tail->next){
        clist->tail = NULL;
    } else {
        clist->tail->next = first->next;
    }
    clist->nodeCount--;
    
    free(first);
    first = NULL;

    return data;
}
void menu(){
    printf("-------------- Circular linked list --------------\n");
    printf("1. insert node\n");
    printf("2. find\n");
    printf("3. print list\n");
    printf("4. delete node\n");
    printf("5. Quit\n");
    printf("--------------------------------------------------\n");
}

int main(){
    CircularLinkedList clist; 
    initList(&clist);
    menu();
    int choice, data, deleted; 
    while (true) {
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice) {
        case 1: printf("Enter the data to insert: ");
                scanf("%d",&data);
                insertNode(&clist, data);
                break;
        case 2: printf("Enter the data to find: ");
                scanf("%d",&data);
                find(&clist,data);
                break;
        case 3: printList(&clist);
                break;
        case 4: deleted = deleteNode(&clist);
                if (deleted != -9999) printf("Deleted %d\n",deleted);
                break;
        case 5: exit(0);
                break;
        default: printf("Options are from 1-5.\n");
                break;
        }
    }
    
    return 0;
}
