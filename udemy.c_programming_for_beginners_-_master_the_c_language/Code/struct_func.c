#include <stdio.h>
#include <stdlib.h>
#define FUNDLEN 25

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(struct funds moolah);

int main()
{
    struct funds stan = {
        "Garlig-Melon-Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n",sum(stan));
    return 0;
}
double sum(struct funds moolah){
    return (moolah.bankfund + moolah.savefund);
}
/* Output: 
Stan has a total of $12576.21.

*/
