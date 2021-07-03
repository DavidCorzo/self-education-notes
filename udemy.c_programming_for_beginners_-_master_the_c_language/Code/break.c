#include <stdio.h>
int main()
{
    int p = 0, q = 0;
    while (p > 0) {
        printf("%d\n",p);
        scanf("%d",&q);
        while (q > 0) {
            printf("%d\n",p*q);
            if (q > 100) break;
            scanf("%d",&q);
        }
        if (q > 100) break;
        scanf("%d",&p);
    }
    return 0;
}
