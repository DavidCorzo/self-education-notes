#include <stdio.h>
#include <stdlib.h>

int k = 1;

void print(int k){
    // static int k = 1;
    printf("Hello!!,k = %d\n",k);
    print(k+1);
}

int main() {
    print();
    return 0;
}
