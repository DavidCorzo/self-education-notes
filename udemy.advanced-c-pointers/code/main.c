#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
    struct listitem *next;
    struct listitem *prev;
    int data;
} LISTITEM;

int main() {
    LISTITEM head, *temp;

    head.next = (LISTITEM*)&head;
    head.prev = (LISTITEM*)&head;
    head.data = -1;
    
    for (int i = 0; i < 3; i++) {
        temp = malloc(sizeof(LISTITEM));
        temp->data = i;
        temp->next = head.next;
        head.next = temp;
        temp->prev = &head;
        temp->next->prev = temp;
    }
    return 0;
}