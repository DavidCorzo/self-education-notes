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
int loadFromFile(DoublyLinkedList *, char *);
void createListFromRandomNumbers(DoublyLinkedList *, int);
void printListDetail(DoublyLinkedList *);
// void printForward(DoublyLinkedList *);
void printForward(DoublyLinkedList *);
void printReverse(DoublyLinkedList *);
Node *find(DoublyLinkedList *, int);
bool insertAfter(DoublyLinkedList *, int, int);
int insertBefore(DoublyLinkedList *, int, int);
bool deleteFirst(DoublyLinkedList *);
bool deleteLast(DoublyLinkedList *);
bool deleteTarget(DoublyLinkedList *, int);
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
int loadFromFile(DoublyLinkedList *pdlist, char *filename){
    /*  
    * Creates the doubly linked list reading data from a file supplied as parameter.
    * The linked list is created by adding the nodes at the end of the list.
    */
    FILE *fp = fopen(filename,"r");
    if (fp == NULL){
       return false;
    }
    int data; 
    fscanf(fp,"%d",&data);
    while (!feof(fp)){
        addLast(pdlist,data);
        fscanf(fp,"%d",&data);
    }
    fclose(fp);
    return true;
}
void createListFromRandomNumbers(DoublyLinkedList *pdlist, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        int k = rand() % 1000;
        addLast(pdlist,k);
    }
}
void printListDetail(DoublyLinkedList *pdlist){
    // current is the head
    Node *current = pdlist->head;
    int i = 0;  
    while (current != NULL){
        printf("i:%d, data:%d, prev:%p, next:%p\n",i++,current->data,current->prev,current->next);
        current = current->next;
    }
    printf("\n");
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
void printReverse(DoublyLinkedList *pdlist){ 
    Node *current = pdlist->tail;
    printf("[");
    while (current != NULL){
        printf("%d, ",current->data);
        current = current->prev;
    }
    printf("\b\b]\n");
}
Node *find(DoublyLinkedList *pdlist, int target){
    Node *current; 
    for (current = pdlist->head; current != NULL; current = current->next){
        if (current->data == target){
            return current;
        }
    }
    return NULL;
}
bool insertAfter(DoublyLinkedList *pdlist, int target, int data){
    /*
    * Inserts a new node after the target node with data supplied as parameter.
    * Returns 1 if the node that contains is successful, 0 otherwise.
    */
   const int error = -8;
   Node *found = find(pdlist,target);
   if (found == NULL){
       printf("The node was not found.\n");
       return false; 
    }

   if (found == pdlist->tail){
       addLast(pdlist,data);
    } else {
       Node *newNode = (Node*)malloc(sizeof(Node));
       if (newNode == NULL){
           printf("Memory could not be allocated. %d\n",error);
           return false;
       }
        newNode->data = data; 
        newNode->next = found->next;
        newNode->prev = found;
        newNode->next->prev = newNode;
        found->next = newNode;
        pdlist->nodeCount++;
    }

    return true;
}
int insertBefore(DoublyLinkedList *pdlist, int target, int data){
    /* 
    * Inserts a new node before the target node with data supplied as parameter.
    * Returns 1 is succesful and 0 otherwise.
    */
   const int error = -8;
   Node *found = find(pdlist,target);
   if (found == NULL){
       printf("The node was not found.\n");
       return false; 
   }

   if (found == pdlist->head){
       addFirst(pdlist,data);
   } else {
       Node *newNode = (Node*)malloc(sizeof(Node));
       if (newNode == NULL){
           printf("Memory could not be allocated. %d\n",error);
           return false;
       }
        newNode->data = data; 
        newNode->prev = found->prev;
        newNode->prev->next = newNode;
        newNode->next = found;
        found->prev = newNode;
        pdlist->nodeCount++;
        
   }
    return true;
}
bool deleteFirst(DoublyLinkedList *pdlist){

    if (isEmpty(pdlist)){
        printf("The list is empty.\n");
        return false;
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
    return true;
}
bool deleteLast(DoublyLinkedList *pdlist){
    if (isEmpty(pdlist)){
        printf("The list is empty.\n");
        return false;
    }
    Node *last = pdlist->tail;
    if (pdlist->nodeCount == 1 || pdlist->head == pdlist->tail){
        pdlist->head = pdlist->tail = NULL;
    } else {
        pdlist->tail = pdlist->tail->prev;
        last->prev->next = NULL;
    }

    free(last);
    pdlist->nodeCount--;
    return true;
}
bool deleteTarget(DoublyLinkedList *pdlist, int target){
    /*
    * Deletes the node with the target. Retruns true if deletion is successful, 0 otherwise. 
    */
    Node *found = find(pdlist,target);
    if (found == NULL){
        printf("Target was not found in the linked list.\n");
        return false;
    }
    if (found == pdlist->head){
        return deleteFirst(pdlist);
    } else if (found == pdlist->tail){
        return deleteLast(pdlist);
    } else {
        found->prev->next = found->next;
        found->next->prev = found->prev;
        found->next = found->prev = NULL; 
        free(found);
        pdlist->nodeCount--;
    }
    return true;
}
void menu(){
    printf("------- Doubly Linked List -------\n");
    printf("1. Load From File\n");
    printf("2. Create List From Random Numbers\n");
    printf("3. Add First\n");
    printf("4. Add Last\n");
    printf("5. print List Detail\n");
    printf("6. print Forward\n");
    printf("7. Print Reverse\n");
    printf("8. Find\n");
    printf("9. Insert After\n");
    printf("10. Insert Before\n");
    printf("11. Delete First\n");
    printf("12. Delete Last\n");
    printf("13. Delete Target\n");
    printf("14. Quit\n");
    printf("----------------------------------\n");
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
        case 1: loadFromFile(&dlist,filename);
                break;
        case 2: printf("Enter n:");
                scanf("%d",&n);
                createListFromRandomNumbers(&dlist,n);
                break;
        case 3: printf("Enter data to add first: ");
                scanf("%d",&data);
                addFirst(&dlist,data);
                break;
        case 4: printf("Enter data to add last: ");
                scanf("%d",&data);
                addLast(&dlist,data);
                break;
        case 5: printListDetail(&dlist);
                printf("\n");
                break;
        case 6: printForward(&dlist);
                break;
        case 7: printReverse(&dlist);
                break;
        case 8: printf("Enter the data to find: ");
                scanf("%d",&target);
                find(&dlist,target);
                break;
        case 9: printf("Enter the target: ");
                scanf("%d",&target);
                printf("Enter the new data: ");
                scanf("%d",&data);
                insertAfter(&dlist,target,data);
                break;
        case 10: printf("Enter the target: ");
                scanf("%d",&target);
                printf("Enter the new data: ");
                scanf("%d",&data);
                insertBefore(&dlist,target,data);
                break;
        case 11: deleteFirst(&dlist) != -9999? 
                printf("Deleted first successfully.\n"): printf("Unable to perform the opeation delete first.\n");
                break;
        case 12: deleteLast(&dlist) != false? 
                printf("Deleted last successfully.\n"): printf("Unable to perform the opeation delete last.\n");
                break;
        case 13: printf("Enter the target: ");
                scanf("%d",&target);
                deleteTarget(&dlist, target);
                break;
        case 14: exit(0);
                break;
        default: printf("Valid options are 1-14\n");
                break;
        }
    }
    return 0; 
}
