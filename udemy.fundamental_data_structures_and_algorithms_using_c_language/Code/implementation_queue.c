#include <stdio.h>
#include <stdlib.h>
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

int main() {
    Queue q; 
    initQueue(&q);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);

    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));

    return 0;
}
/* Output: 
5
10
15
20
Queue underflow
-9999

*/
