#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    struct Node *head;
    struct Node *tail;
    int nodeCount;
} DoublyLinkedList;

// function prototypes
bool isEmpty(DoublyLinkedList *);
void initlist(DoublyLinkedList *);
void addFirst(DoublyLinkedList *, int);
void addLast(DoublyLinkedList *, int);
void printForward(DoublyLinkedList *);
int deleteFirst(DoublyLinkedList *);
int deleteLast(DoublyLinkedList *);
void menu();

// Utility functions
bool isEmpty(DoublyLinkedList *pdlist){ 
    return  (
        (pdlist->head == NULL) ||
        (pdlist->tail == NULL) ||
        (pdlist->nodeCount == 0) 
    );
}

// function definitions
void initlist(DoublyLinkedList *pdlist){
    pdlist->head = pdlist->tail = NULL; 
    pdlist->nodeCount = 0; 
}
void addFirst(DoublyLinkedList *pdlist, int data){
    const int error = -1;
    Node *newNode = NULL;
    newNode = (Node*)malloc(sizeof(Node));
    if ( newNode == NULL ){
        printf("Memory could not be allocated. %d\n",error);
        return;
    }

    newNode->data  = data;
    newNode->prev = NULL; 
    newNode->next = NULL;

    if ( isEmpty(pdlist) ){
        pdlist->head = pdlist->tail = newNode;
    } else {
        newNode->next = pdlist->head;
        pdlist->head->prev = newNode;
        pdlist->head = newNode;
    }
    pdlist->nodeCount++;
}
void addLast(DoublyLinkedList *pdlist, int data){
    /* 
    * Adds new data using parameter, inserts that data as the last node.
    */
   const int error = -3;
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory could not be allocated. %d\n",error);
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(pdlist)){
        pdlist->head = pdlist->tail = newNode;
    } else {
        pdlist->tail->next = newNode; // tail->next points no longer to null but to the new node.
        newNode->prev = pdlist->tail; // sets prev pointer of newnode to point to the tail.
        pdlist->tail = newNode; // the tail is the new node.
    }
    pdlist->nodeCount++;
}
void printForward(DoublyLinkedList *pdlist){
    Node *current = pdlist->head;
    printf("[");
    while (current != NULL){
        printf("%d, ",current->data);
        current = current->next;
    }
    printf("\b\b]\n");
}
int deleteFirst(DoublyLinkedList *pdlist){

    if (isEmpty(pdlist)){
        printf("The list is empty.\n");
        return -9999;
    } 
    int data = pdlist->head->data;
    Node *first = pdlist->head;
    if (pdlist->nodeCount == 1 || pdlist->head == pdlist->tail){
        pdlist->head = pdlist->tail = NULL;
    } else {
        pdlist->head = pdlist->head->next;
        first->next->prev = NULL;
    }
    free(first);
    pdlist->nodeCount--;
    return data;
}
int deleteLast(DoublyLinkedList *pdlist){
    if (isEmpty(pdlist)){
        printf("The list is empty.\n");
        return -9999;
    }
    Node *last = pdlist->tail;
    int data = pdlist->tail->data;
    if (pdlist->nodeCount == 1 || pdlist->head == pdlist->tail){
        pdlist->head = pdlist->tail = NULL;
    } else {
        pdlist->tail = pdlist->tail->prev;
        last->prev->next = NULL;
    }

    free(last);
    pdlist->nodeCount--;
    return data;
}
void menu(){
    printf("------- Doubly Ended Queue Using Linked List -------\n");
    printf("1. Add First\n");
    printf("2. Add Last\n");
    printf("3. Delete First\n");
    printf("4. Delete Last\n");
    printf("5. print Forward\n");
    printf("6. Quit\n");
    printf("----------------------------------------------------\n");
}

int main(){
    DoublyLinkedList dlist;
    initlist(&dlist);

    char filename[] = "testfile.txt";

    menu();
    int choice, n, data, target, deleted; 
    while (true){
        printf("Input choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1: printf("Enter the value to add first: ");
                scanf("%d",&data);
                addFirst(&dlist,data);
                break;
        case 2: printf("Enter the value to add last: ");
                scanf("%d",&data);
                addLast(&dlist,data);
                break;
        case 3: deleteFirst(&dlist) != -9999? printf("Successfull.\n"):printf("Error.\n");
                break;
        case 4: deleteLast(&dlist) != -9999? printf("Successfull.\n"):printf("Error.\n");
                break;
        case 5: printForward(&dlist);
                break;
        case 6: exit(0);
                break;
        default: printf("Valid options are 1-14\n");
                break;
        }
    }
    return 0; 
}
/* Output: 
------- Doubly Ended Queue Using Linked List -------
1. Add First
2. Add Last
3. Delete First
4. Delete Last
5. print Forward
6. Quit
----------------------------------------------------
Input choice: 2
Enter the value to add last: 56
Input choice: 2
Enter the value to add last: 78
Input choice: 1
Enter the value to add first: 56
Input choice: 5
[56, 56, 78] 
Input choice: 2
Enter the value to add last: 34
Input choice: 2
Enter the value to add last: 56
Input choice: 1
Enter the value to add first: 78
Input choice: 1
Enter the value to add first: 90
Input choice: 5
[90, 78, 56, 56, 78, 34, 56] 
Input choice: 4
Successfull.
Input choice: 5
[90, 78, 56, 56, 78, 34]
Input choice: 3
Successfull.
Input choice: 5
[78, 56, 56, 78, 34]
Input choice: 6

*/
