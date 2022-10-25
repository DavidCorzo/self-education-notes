#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int a; // 4 bytes
    int c; // 4 bytes
    double b; // 8 bytes
    long long int d; // 8 bytes
} MYSTRUCT;

#define COUNT 4

int main() {
    MYSTRUCT *p, *q;
    void *v;
    printf("size of MYSTRUCT = %d\n", sizeof(MYSTRUCT));
    p = (MYSTRUCT*)calloc(COUNT, sizeof(MYSTRUCT));
    
    for (int i = 0; i < COUNT; i++) {
        p[i].a = i;
        p[i].b = 1000000000000.0 + i;
        p[i].c = i * 20;
        p[i].d = 4294967296 + i;
    }
    q = p;

    printf("[0] values:\na is %d\nb is %f\ncis %d\nd is%lld\n", q->a, q->b, q->c, q->d);
    printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n", &q->a, &q->b, &q->c, &q->d);

    q = p + 1;

    printf("[1] values:\na is %d\nb is %f\ncis %d\nd is%lld\n", q->a, q->b, q->c, q->d);
    printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n", &q->a, &q->b, &q->c, &q->d);

    v = p + 1;
    printf("struct at index 1\n");
    for (int i = 0; i < sizeof(MYSTRUCT) / sizeof(int); i++) {
        printf("v[%d]=%d\n", i, ((int*)v)[i]);
    }
    
    return (0);
}
/*
Output:
size of MYSTRUCT = 24
[0] values:
a is 0
b is 1000000000000.000000
cis 0
d is4294967296
addresses:
a is 0000025f4dda69a0
b is 0000025f4dda69a8
c is 0000025f4dda69a4
d is 0000025f4dda69b0
[1] values:
a is 1
b is 1000000000001.000000
cis 20
d is4294967297
addresses:
a is 0000025f4dda69b8
b is 0000025f4dda69c0
c is 0000025f4dda69bc
d is 0000025f4dda69c8
struct at index 1
v[0]=1
v[1]=20
v[2]=-1577050112
v[3]=1114446484
v[4]=1
v[5]=1
*/