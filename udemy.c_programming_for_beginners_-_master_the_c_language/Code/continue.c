#include <stdio.h>
int main()
{
    enum Day {Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
    for (enum Day day = Monday; day <= Sunday; ++day){
        if (day == Wednesday){
            continue;
        }
        printf("It's not wednesday %d\n",day);
    }
    return 0;
}
/* Output: 
It's not wednesday 0
It's not wednesday 1
It's not wednesday 3
It's not wednesday 4
It's not wednesday 5
It's not wednesday 6

*/
