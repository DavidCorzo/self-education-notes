#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct {
    struct Node *head;
    struct Node *tail;
    int nodeCount;
} LinkedList;


// function prototypes
void initList(LinkedList *);
void push(LinkedList *, int); 
void printListDetail(LinkedList *);
void printList(LinkedList *);
int pop(LinkedList *); 
bool theLLisEmpty(LinkedList *);
void menu();

void initList(LinkedList * plist){
    /* Inialize the members of the LinkedList Object */
    plist->head = plist->tail = NULL;
    plist->nodeCount = 0; 
}
void push(LinkedList *plist, int data){
    const int error = -2;
    Node *pnewNode = (Node*)malloc(sizeof(Node)); 
    if (pnewNode == NULL){
        printf("The space for the new node could not be allocated. Error: %d\n",error);
        return;
    }
    pnewNode->data = data;
    pnewNode->next = NULL; 

    if (theLLisEmpty(plist)){
        // linked list is empty, these are the initialization condition
        plist->head = pnewNode;
        plist->tail = pnewNode;
    } else { 
        // linked list is not empty, there is at least one node in it.
        pnewNode->next = plist->head;
        plist->head = pnewNode;
    }
    plist->nodeCount++;
}
void printListDetail(LinkedList *plist){
    if ((plist->head == NULL && plist->tail == NULL), (plist->nodeCount == 0)){
        printf("The list is empty.\n");
        return;
    }
    Node *current = plist->head;
    int i = 0;
    while (current != NULL){
        printf("i: %d, data: %d, current: %p, next: %p\n",i++,current->data,current,current->next);
        current = current->next;
    }
}
void printList(LinkedList *plist){
    if ((plist->head == NULL && plist->tail == NULL), (plist->nodeCount == 0)){
        printf("The list is empty.\n");
        return;
    }
    Node *current = plist->head;
    printf("top -> [");
    while (current != NULL){
        printf("%d, ",current->data);
        current = current->next;
    }
    printf("\b\b] <- tail\n");
}
int pop(LinkedList *plist){
    if (theLLisEmpty(plist)){
        printf("The list is empty.");
        return -9999; 
    }

    int data = plist->head->data;
    Node *head = plist->head;
    if (plist->nodeCount == 1){
        plist->head = NULL; 
        plist->tail = NULL; 
    } else {
        plist->head = head->next;
    }
    // dellocate the space used in this node.
    free(head);

    plist->nodeCount--;
    return data;
}
bool theLLisEmpty(LinkedList *plist){
    return  (plist->head == NULL) && 
            (plist->tail == NULL) && 
            (plist->nodeCount == 0);
}
void menu(){
    printf("-----------Stack------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display (data)\n");
    printf("4. Display (detail)\n");
    printf("5. Quit\n\n");
}

int main(){
    LinkedList stack; 
    initList(&stack);
    int choice,v; 
    bool quit = false; 

    while (!quit){
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch (choice){
        case 1: printf("Enter value to push: ");
                scanf("%d",&v);
                push(&stack,v);
                break;
        case 2: printf("Value poped %d\n",pop(&stack));
                break;
        case 3: printList(&stack);
                break;
        case 4: printListDetail(&stack);
                break;
        case 5: exit(0);
                break;
        default: printf("Valid options are 1-4\n");
                 break; 
        }
    }
    return 0;
}
/* Output: 
Enter choice: 1
Enter value to push: 45
Enter choice: 1
Enter value to push: 56
Enter choice: 1
Enter value to push: 23
Enter choice: 1
Enter value to push: 45
Enter choice: 1
Enter value to push: 78
Enter choice: 3
top -> [78, 45, 23, 56, 45] <- tail
Enter choice: 2
Value poped 78
Enter choice: 3
top -> [45, 23, 56, 45] <- tail
Enter choice: 2
Value poped 45
Enter choice: 3
top -> [23, 56, 45] <- tail
Enter choice: 2
Value poped 23
Enter choice: 3
top -> [56, 45] <- tail
Enter choice: 2
Value poped 56
Enter choice: 3
top -> [45] <- tail
Enter choice: 2
Value poped 45
Enter choice: 3
The list is empty.
Enter choice: 5

*/
