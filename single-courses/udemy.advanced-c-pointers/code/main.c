#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    struct node *next, *prev;
    int data;
} node;
typedef struct list  {
    node *head, *tail;
} list;
unsigned int calculate_length(list *l) {
    unsigned int length = 0;
    node *current = l->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}
void push(list *l, int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    if ((l->head == NULL) && (l->tail == NULL)) {
        l->head = l->tail = new_node;
    } else {
        l->tail->next = new_node;
        new_node->prev = l->tail;
        l->tail = new_node;
    }
}
int pop(list *l) {
    if ((l->head == NULL) && (l->tail == NULL)) {
        return -999;
    } else if (l->head == l->tail) {
        int last = l->head->data;
        free(l->head);
        l->head = l->tail = NULL;
        return last;
    } else {
        int last = l->tail->data;
        l->tail = l->tail->prev;
        free(l->tail->next);
        l->tail->next = NULL;
        return last;
    }
}
int main(void) {
    list l;
    l.head = l.tail = NULL;
    for (int i = 0; i < 10; i++) {
        push(&l, i*2);
        printf("pushed: %d\n", i*2);
    }
    printf("\n\nlength: %u\n\n", calculate_length(&l));
    for (int i = 0; i < 11; i++) {
        printf("popped: %d\n", pop(&l));
    }
    return 0;
}
/* output:
pushed: 0
pushed: 2
pushed: 4
pushed: 6
pushed: 8
pushed: 10
pushed: 12
pushed: 14
pushed: 16
pushed: 18


length: 10

popped: 18
popped: 16
popped: 14
popped: 12
popped: 10
popped: 8
popped: 6
popped: 4
popped: 2
popped: 0
popped: -999
*/