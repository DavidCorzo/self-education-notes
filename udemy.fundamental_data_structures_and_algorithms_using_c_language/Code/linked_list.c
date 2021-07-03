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
void createList(LinkedList *);
int loadfromfile(LinkedList *, char *);
void createListFromNumbers(LinkedList *, int);
void insertAtHead(LinkedList *, int);
void insertAtTail(LinkedList *, int);
void printListDetail(LinkedList *);
void printList(LinkedList *);
Node * find(LinkedList *, int);
int deleteFirst(LinkedList *);
int deleteLast(LinkedList *);
int deleteTarget(LinkedList *, int);
void reverse(LinkedList *);
bool theLLisEmpty(LinkedList *);
void insertOrder(LinkedList *, int);

// helper recursive functions for inplementing traversal
void printRecForward(Node *);
void printRecReverse(Node *);

void initList(LinkedList * plist){
    /* Inialize the members of the LinkedList Object */
    plist->head = plist->tail = NULL;
    plist->nodeCount = 0; 
}
void createList(LinkedList *plist){

}
int loadfromfile(LinkedList *plist, char *filename){
    FILE *fp = fopen(filename,"r"); 
    if (fp == NULL){
        printf("Error encountered while opening the file.\n");
        return -1;
    }
    int data;
    fscanf(fp,"%d",&data);
    while (!feof(fp)){
        insertAtTail(plist,data);
        fscanf(fp,"%d",&data);
    };
    fclose(fp);
    fp = NULL; 
    return 0;
}
void createListFromNumbers(LinkedList *plist, int n){
    srand(time(NULL));
    for (int i = 0; i <= n; ++i){
        int k = rand() % 1000; 
        insertAtTail(plist,k);
    }
}
void insertAtHead(LinkedList *plist, int data){
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
    printf("[");
    while (current != NULL){
        printf("%d, ",current->data);
        current = current->next;
    }
    printf("\b\b]\n");
}
Node * find(LinkedList *plist, int target){
    /* Find the first occurrance of said targer */
    Node *current = plist->head;
    while (current != NULL){
        if (current->data == target){
            return current;
        }
        current = current->next;
    }
    return NULL;
}
int deleteFirst(LinkedList *plist){
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
int deleteLast(LinkedList *plist){
    Node *current = plist->head;
    Node *last = plist->tail;
    int data = last->data;

    if (theLLisEmpty(plist)){
        printf("The list is empty.\n");
        return -9999; 
    } 
    
    if (plist->nodeCount == 1){
        plist->head = NULL;
        plist->tail = NULL; 
    } else {
        while (current->next != plist->tail){
            current = current->next;
        }
        plist->tail = current;
        plist->tail->next = NULL;
    }
    free(last);
    plist->nodeCount--;
    return data;
}
int deleteTarget(LinkedList *plist, int target){
    Node *current = plist->head, *prev = NULL;
    while (current != NULL){
        if (current->data == target){
            break;
        }
        prev = current;
        current = current->next;
    }
    if (current == NULL){
        // didn't find anything
        return -9999; 
    }

    int data = current->data;
    if (current == plist->head){
        return deleteFirst(plist);
    } else if (current == plist->tail){
        return deleteLast(plist);
    } else {
        prev->next = current->next;
        free(current);
        plist->nodeCount--;
    }
    return data;
}
void reverse(LinkedList *plist){
    if (plist->nodeCount <= 1){
        return;
    }
    Node *previous_node, *current, *next;
    // p is current node, q is just previous to p and r is just inmediate next to p.
    previous_node = NULL; // previos node
    current = plist->head; // first node
    next = current->next; // second node
    while (true) {
        current->next = previous_node; 
        if (current == plist->tail) {
            break;
        }
        previous_node = current; 
        current = next; 
        next = next->next;
    }
    plist->tail = plist->head;
    plist->head = current; 
}
bool theLLisEmpty(LinkedList *plist){
    return  (plist->head == NULL) && 
            (plist->tail == NULL) && 
            (plist->nodeCount == 0);
}

void menu(){
    printf("Singly linked list operation \n");
    printf("1. Load from file.\n");
    printf("2. Generate random numbers (n)\n");
    printf("3. Insert at head.\n");
    printf("4. Insert at tail.\n");
    printf("5. Print list (detail)\n");
    printf("6. Print list (data only)\n");
    printf("7. Find.\n");
    printf("8. Delete first.\n");
    printf("9. Delete last.\n");
    printf("10. Delete a target node.\n");
    printf("11. Reverse\n");
    printf("12. Quit\n");
    printf("13. Print tail and head.\n");
}

int main() {
    LinkedList ll;
    initList(&ll);

    bool quit = false;
    int choice, data, n, deleted;  
    char filename[] = "testfile.txt";
    Node *current = NULL, *previous = NULL;

    menu(); 
    while (!false){
        printf("Please input your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1: loadfromfile(&ll,filename) == 0? printf("Everything ok\n"): printf("Error while creating the list.\n");
                    break;
            case 2: printf("Enter quantity of numbers to generate: ");
                    scanf("%d",&n);
                    createListFromNumbers(&ll,n-1);
                    break;
            case 3: printf("Enter value to insert at head: ");
                    scanf("%d",&data);
                    insertAtHead(&ll,data);
                    break;
            case 4: printf("Enter value to insert at tail: ");
                    scanf("%d",&data);
                    insertAtTail(&ll,data);
                    break;
            case 5: printListDetail(&ll);
                    break;
            case 6: printList(&ll);
                    break;
            case 7: printf("Enter value to find: ");
                    scanf("%d",&data);
                    printf("\n");
                    Node *found = find(&ll,data);
                    found != NULL? printf("%d found at (%p)\n",found->data,found): printf("Nothing found\n");
                    break;
            case 8: deleted = deleteFirst(&ll);
                    deleted != -9999 ? printf("Deleted %d\n",deleted): printf("The list is empty.\n");
                    break;
            case 9: deleted = deleteLast(&ll);
                    deleted != -9999 ? printf("Deleted %d\n",deleted) : printf("The linked list is empty.\n");
                    break;
            case 10: printf("Enter the target data to delete: ");
                    scanf("%d",&data);
                    deleted = deleteTarget(&ll,data);
                    deleted != -9999 ? printf("Deleted %d\n",deleted) : printf("Not found in list\n") ;
                    break;
            case 11: reverse(&ll);
                    break; 
            case 12: exit(0);  
                    break; 
            case 13: printf("head: %d, tail: %d\n",ll.head->data,ll.tail->data);
                    break; 
            default: printf("Valid options are 1-12.\n");
                     break;
        }
    }
    return 0;
}
