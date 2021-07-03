#include <stdio.h>
#include <stdlib.h>

void decToBin(unsigned n){
    if (n == 0) {
        printf("0");
        return;
    } else if (n == 1){
        printf("1");
        return;
    }
    int r = (int)(n % 2);
    n = n / 2;
    decToBin(n);
    printf("%d",r);
}
int main() {
    decToBin(67);
    printf("\n");
    decToBin(90);
    printf("\n");
    decToBin(1);
    printf("\n");
    decToBin(0);
    printf("\n");
    decToBin(5);
    printf("\n");
    return 0;
}
/* Output: 
1000011
1011010
1
0
101

*/
