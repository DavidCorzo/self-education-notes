#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct date {
        int month; 
        int day; 
        int year; 
    } today ; 
    
    today.month = 29;
    today.day = 06;
    today.year = 2020;

    printf("Today: %d/%d/%d",today.month,today.day,today.year);
    
    return 0;
}
/* Output: 
Today: 29/6/2020
*/
