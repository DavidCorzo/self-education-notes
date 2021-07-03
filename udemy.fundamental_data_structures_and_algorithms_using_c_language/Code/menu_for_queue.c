#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100

typedef struct {
    int item[SIZE];
    int rear; 
    int front; 
}Queue;

// function prototypes 
int dequeue(Queue *);
void enqueue(Queue *, int);
// functionality functions
void initQueue(Queue *);
void menu();

void enqueue(Queue *queue, int v){
    if (queue->rear == SIZE){
        printf("Queue overflow\n");
        exit(1);
    }
    queue->item[queue->rear] = v;
    queue->rear++;
}
int dequeue(Queue *queue){
    if (queue->rear == queue->front){
        printf("Queue underflow\n");
        return -9999;
    }
    int v = queue->item[queue->front++];
    return v;
}
void initQueue(Queue *queue){
    queue->front = queue->rear = 0;
}
void menu(){
    printf("----Queue operations----\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Quit\n");
    printf("--------------------------\n");
}

int main() {
    menu();
    Queue q; 
    initQueue(&q);
    bool quit = false;
    int value; 

    while (!quit){
        int choice; 
        printf("Input your option: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1: printf("Input the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    break; 
            case 2: value = dequeue(&q);
                    if (value != -9999){
                        printf("Deleted value: %d\n",value);
                    } 
                    break; 
            case 3: quit = true;
                    break; 
            default: printf("Invalid choice, valid options are 1-3");
        }
        
    }
    return 0;
}
/* Output: 
----Queue operations----
1. Enqueue
2. Dequeue
3. Quit
--------------------------
Input your option: 1
Input the value to enqueue: 5
Input your option: 1
Input the value to enqueue: 6
Input your option: 1
Input the value to enqueue: 7
Input your option: 2
Deleted value: 5
Input your option: 2
Deleted value: 6
Input your option: 2
Deleted value: 7
Input your option: 2
Queue underflow
Input your option: 3

*/
