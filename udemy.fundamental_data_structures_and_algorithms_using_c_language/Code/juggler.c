#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  asume the congecture 10^6 nums end at one. 
void juggler(int a){
    // base condition.
    if (a == 1){
        printf("%d\n",a);
        return; 
    } 
    printf("%d, ",a);
    juggler((a % 2) != 0 ? (int)pow(a,1.5) : (int)pow(a,0.5));
}
void juggler_rev(int a){
    // base condition.
    if (a == 1){
        printf("%d, ",a);
        return; 
    } 
    juggler_rev((a % 2) != 0 ? (int)pow(a,1.5) : (int)pow(a,0.5));
    printf("%d, ",a);
}
int main() {
    printf("Juggler(3): ");
    juggler(3);
    printf("Juggler(3) reverse: ");
    juggler_rev(3);
    return 0;
}
/* Output: 
Juggler(3): 3, 5, 11, 36, 6, 2, 1
Juggler(3) reverse: 1, 2, 6, 36, 11, 5, 3,
*/
