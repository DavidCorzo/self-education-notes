#include <stdio.h>
int main()
{
    enum month {
        January,February,March,April,May,June,July,August,Spetember,October
    };
    enum month thisMonth;
    thisMonth = February;
    printf("%d ",thisMonth);
    enum direction {up,down,left=10,right};
    enum direction dir = left;
    printf("%d ",dir);

    char myChar = '\n';
    printf("%cnewline?",myChar);
    
    return 0;
}
/* Output: 
1 10
newline?
*/
