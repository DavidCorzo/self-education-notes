#include <stdio.h>
int main()
{
    enum Weekday {Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
    enum Weekday today = Monday;
    switch (today)
    {
    case Sunday:
        printf("Sunday");break;
    case Monday:
        printf("Monday");break;
    case Tuesday:
        printf("Tuesday");break;
    
    default:
        printf("Whatever");break;
    }
    return 0;
}
/* Output: 
Monday
*/
