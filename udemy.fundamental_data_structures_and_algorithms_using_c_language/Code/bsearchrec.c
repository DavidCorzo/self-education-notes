#include <stdio.h>
#include <stdlib.h>

int bin_search(int arr[], int lb, int ub, int target){
    int middle = (int)((lb + ub) / 2);
    if (lb > ub) {
        return -1;
    } 
    int m = (int)((lb + ub) / 2);
    if (arr[m] == target){
        return m;
    } else if (arr[m] > target){
        bin_search(arr,lb,m-1,target);
    } else {
        bin_search(arr,m+1,ub,target);
    }
}

int main() {
    int arr[] = {10,20,30,40,50,60,70,80,90};
    const int target = 80;
    int k = bin_search(arr,0,sizeof(arr)/sizeof(int)-1,target);
    k != -1? printf("Found at %d => %d",k,target): printf("Not found.");
    return 0;
}
/* Output: 
Found at 7 => 80
*/
