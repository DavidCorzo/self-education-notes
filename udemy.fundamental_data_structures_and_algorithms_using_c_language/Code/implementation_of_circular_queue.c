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
int dequeue(Queue *);
void enqueue(Queue *, int);
// functionality functions
void initQueue(Queue *);
void menu();

void enqueue(Queue *queue, int v){
    if ((queue->rear + 1) % SIZE == queue->front){
        printf("Queue overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    queue->item[queue->rear] = v;
}
int dequeue(Queue *queue){
    if (queue->rear == queue->front){
        printf("Queue underflow\n");
        return -9999;
    }
    queue->front = (queue->front + 1) % SIZE;
    queue->item[queue->front] = 0; // to observe the effect lets place deleted places to 0
    int v = queue->item[queue->front];
    return v;
}
void initQueue(Queue *queue){
    queue->front = queue->rear = SIZE - 1;
}
void menu(){
    printf("----Queue operations----\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Quit\n");
    printf("--------------------------\n");
}
void print_queue(Queue *queue){
    for (int i = 0; i < SIZE; i++){
        printf("%d: %d\n",i,queue->item[i]);
    }
    printf("front: %d, rear: %d\n",queue->front,queue->rear);
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
            case 1: printf("Input the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    print_queue(&q);
                    break; 
            case 2: value = dequeue(&q);
                    if (value != -9999){
                        printf("Deleted value: %d\n",value);
                    } 
                    print_queue(&q);
                    break; 
            case 3: quit = true;
                    print_queue(&q);
                    break; 
            default: printf("Invalid choice, valid options are 1-3\n");
                     break;  
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
Input the value to enqueue: 10
0: 10
1: 0
2: 0
3: 0
4: 0
front: 4, rear: 0
Input your option: 1
Input the value to enqueue: 20
0: 10
1: 20
2: 0
3: 0
4: 0
front: 4, rear: 1
Input your option: 1
Input the value to enqueue: 30
0: 10
1: 20
2: 30
3: 0
4: 0
front: 4, rear: 2
Input your option: 1
Input the value to enqueue: 40
0: 10
1: 20
2: 30
3: 40
4: 0
front: 4, rear: 3
Input your option: 1
Input the value to enqueue: 50
Queue overflow
0: 10
1: 20
2: 30
3: 40
4: 0
front: 4, rear: 3
Input your option: 2
Deleted value: 0
0: 0
1: 20
2: 30
3: 40
4: 0
front: 0, rear: 3
Input your option: 2
Deleted value: 0
0: 0
1: 0
2: 30
3: 40
4: 0
front: 1, rear: 3
Input your option: 2
Deleted value: 0
0: 0
1: 0
2: 0
3: 40
4: 0
front: 2, rear: 3
Input your option: 1
Input the value to enqueue: 50
0: 0
1: 0
2: 0
3: 40
4: 50
front: 2, rear: 4
Input your option: 1
Input the value to enqueue: 60
0: 60
1: 0
2: 0
3: 40
4: 50
front: 2, rear: 0
Input your option: 1
Input the value to enqueue: 70
0: 60
1: 70
2: 0
3: 40
4: 50
front: 2, rear: 1
Input your option: 1
Input the value to enqueue: 80
Queue overflow
0: 60
1: 70
2: 0
3: 40
4: 50
front: 2, rear: 1
Input your option: 3
0: 60
1: 70
2: 0
3: 40
4: 50
front: 2, rear: 1

*/
