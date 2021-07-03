#include <stdio.h>
int main()
{
    unsigned int a = 60; // 00111100
    unsigned int b = 13; // 00001101
    printf("a: %d, b: %d\n",a,b);
    int c = 0;
    c = a & b;
    printf("c and: %d\n",c);
    c = a | b;
    printf("c or: %d\n",c);
    c = a ^ b;
    printf("c xor: %d\n",c);
    c = ~a;
    printf("~a: %d\n",c);
    c = a << 2;
    printf("a << 2: %d\n",c);
    c = a >> 2;
    printf("a >> 2: %d\n",c);
    return 0;
}
