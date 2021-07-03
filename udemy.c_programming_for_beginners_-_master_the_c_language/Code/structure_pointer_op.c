#include <stdio.h>
#include <stdlib.h>

struct date { // you can create it as a global, no memory is allocated for this, its just a definition.
    int month; 
    int day; 
    int year;
};

int main()
{
    
    struct date today, *datePtr; 
    datePtr = &today;

    datePtr->month = 9; 
    datePtr->day = 25;
    datePtr->year = 2015;

    printf("Today's date is %i %i %.2i.\n",datePtr->month,datePtr->day,datePtr->year);
    
    return 0;
}
/* Output: 
Today's date is 9 25 2015.

*/
