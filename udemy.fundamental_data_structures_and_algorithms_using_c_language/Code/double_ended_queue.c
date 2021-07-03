#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

typedef struct {
    int item[SIZE];
    int rear; 
    int front; 
}Queue;

// function prototypes 
void insertAtRear(Queue *, int);
int deleteFromRear(Queue *);
void insertAtFront(Queue *, int);
int deleteFromFront(Queue *);
void initQueue(Queue *);

void insertAtRear(Queue *queue, int v){
    if (queue->rear == SIZE - 1){
        printf("Unable to add at rear\n");
        return; 
    }
    queue->rear++;
    queue->item[queue->rear] = v;
}
int deleteFromRear(Queue *queue){
    if (queue->front == queue->rear){
        printf("Queue underflow\n");
        return -9999; 
    }
    int v = queue->item[queue->rear];
    queue->item[queue->rear] = 0;
    queue->rear--; 
    return v; 
}
void insertAtFront(Queue *queue, int v){
    if (queue->front == 0){
        printf("Unable to insert at front\n");
        return;
    }
    queue->front++; 
    queue->item[queue->front] = v; 
}
int deleteFromFront(Queue *queue){
    if (queue->front > queue->rear) {
        printf("Queue underflow\n");
        return -9999; 
    }
    int v = queue->item[queue->front];
    queue->item[queue->front] = 0;
    queue->front++;
    return v; 
}
void menu(){
    printf("----Queue operations----\n");
    printf("1. Insert at rear\n");
    printf("2. Insert at front\n");
    printf("3. Delete from rear\n");
    printf("4. Delete from front\n");
    printf("--------------------------\n");
}
void print_queue(Queue *queue){
    for (int i = 0; i < SIZE; i++){
        printf("%d: %d\n",i,queue->item[i]);
    }
    printf("front: %d, rear: %d\n",queue->front,queue->rear);
}
void initQueue(Queue *queue){
    queue->front = 0; 
    queue->rear = -1; 
}

int main() {
    menu();
    Queue q = {}; 
    initQueue(&q);
    bool quit = false;
    int value; 

    while (!quit){
        int choice; 
        printf("Input your option: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1: printf("Input the value for rear insertion: ");
                    scanf("%d", &value);
                    insertAtRear(&q,value);
                    print_queue(&q);
                    break; 
            case 2: printf("Input the value for front insertion: ");
                    scanf("%d", &value);
                    insertAtFront(&q,value);
                    print_queue(&q);
                    break; 
            case 3: printf("Deleted item from rear: %d\n",deleteFromRear(&q));
                    print_queue(&q);
                    break; 
            case 4: printf("Deleted item from front: %d\n",deleteFromFront(&q));
                    print_queue(&q);
                    break; 
            default: printf("Invalid choice, valid options are 1-4\n");
                     break;
        }
    }
    return 0;
}
/* Output: 
----Queue operations----
1. Insert at rear
2. Insert at front
3. Delete from rear
4. Delete from front
--------------------------
Input your option: 1
Input the value for rear insertion: 10
0: 10
1: 0
2: 0
3: 0
4: 0
front: 0, rear: 0
Input your option: 1
Input the value for rear insertion: 15
0: 10
1: 15
2: 0
3: 0
4: 0
front: 0, rear: 1
Input your option: 1
Input the value for rear insertion: 20
0: 10
1: 15
2: 20
3: 0
4: 0
front: 0, rear: 2
Input your option: 2
Input the value for front insertion: 7
Unable to insert at front
0: 10
1: 15
2: 20
3: 0
4: 0
front: 0, rear: 2
Input your option: 4
Deleted item from front: 10
0: 0
1: 15
2: 20
3: 0
4: 0
front: 1, rear: 2
*/
