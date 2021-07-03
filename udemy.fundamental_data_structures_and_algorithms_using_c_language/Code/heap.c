#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void adjust(int[],int,int);
void heapSort(int[],int);
void heapify(int[],int);

void adjust(int heap_array[], int i, int n){
    int j = 2 * 1; // left child of i
    int item = heap_array[i]; // content of index i
    while (j <= n){ // while j is valid
        // compare between j and its sibling if sibling exists.
        if (j < n && heap_array[j] < heap_array[j+1]){
            j++;
        }
        // compare j with the item.
        if (item <= heap_array[j]){
            break;
        }
        // copy the content of [j] to the parent.
        heap_array[j/2] = heap_array[j];
        j = 2 * j;
    }
    // parent gets item
    heap_array[j/2] = item;
}

void heapSort(int arr[], int n){
    heapify(arr,n);
    int i, temp;
    // heap sort
    for (i = n; i >= 2; --i){
        // getting largest element from root.
        temp = arr[1];
        // copying the last element from the heap into the root.
        arr[1] = arr[i];
        // adjust the root.
        adjust(arr,1,i-1);
        arr[i] = temp;
    }
}
void heapify(int arr[], int n){
    for (int i = n/2; i >= 1; --i){
        adjust(arr, i, n);
    }
}


int main() {
    
    return 0;
}
