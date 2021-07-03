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

void printListForward(LinkedList *);
void printListReverese(LinkedList *);
void printRecForward(Node *);
void printRecReverse(Node *);
void initList(LinkedList *);
void insertAtTail(LinkedList *, int);
bool theLLisEmpty(LinkedList *);

void printListForward(LinkedList *plist){
    printRecForward(plist->head);
}
void printListReverese(LinkedList *plist){
    printRecReverse(plist->head);
}
void printRecForward(Node *node){
    if (node == NULL){
        return; 
    }
    printf("%d ",node->data);
    printRecForward(node->next);
}
void printRecReverse(Node *node){
    if (node == NULL){
        return;
    }
    printRecReverse(node->next);
    printf("%d ",node->data);
}
void initList(LinkedList * plist){
    /* Inialize the members of the LinkedList Object */
    plist->head = plist->tail = NULL;
    plist->nodeCount = 0; 
}
void insertAtTail(LinkedList *plist, int data){
    const int error = -3;
    // in: initialized linked list, data
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
        plist->tail->next = pnewNode;
        plist->tail = pnewNode;
    }
    plist->nodeCount++;
}
bool theLLisEmpty(LinkedList *plist){
    return  (plist->head == NULL) && 
            (plist->tail == NULL) && 
            (plist->nodeCount == 0);
}

int main(){
    LinkedList list;
    initList(&list);
    for (int i = 0; i < 10; i++) insertAtTail(&list,i);
    printListForward(&list);
    printf("\n");
    printListReverese(&list);
    
}
/* Output: 
0 1 2 3 4 5 6 7 8 9
9 8 7 6 5 4 3 2 1 0
*/
