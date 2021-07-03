#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
int binary_search(int[] , int, int);

// implementation
int binary_search(int list[] , int size, int target){
    int lower_bound = 0, upper_bound = size - 1;
    while (lower_bound <= upper_bound){
        int middle = (int)(lower_bound + upper_bound)/2;
        if (target == list[middle]){
            return middle;
        } else if (target > list[middle]){
            lower_bound = middle + 1;
        } else {
            upper_bound = middle - 1;
        }
    }
    return -1;
}
int main() {
    int list[] = {45,89,267,984,1256,1489};
    int b = binary_search(list,sizeof(list)/sizeof(int),1256);
    b != -1 ? printf("Found at %d => %d\n",b,list[b]) : printf("Not found.\n");
    return 0;
}
/* Output: 
Found at 4 => 1256
*/
