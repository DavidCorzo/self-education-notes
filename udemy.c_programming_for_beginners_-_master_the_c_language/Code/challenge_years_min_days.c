#include <stdio.h>
int main()
{
    long int minutes; double years, minutes_in_a_year = 525600, days;
    printf("Enter the value to compute: ");
    scanf("%d",&minutes);
    years = (double)minutes / minutes_in_a_year ;
    days = ((double)minutes / 60) / 24;
    printf("minutes: %d, minutes in a year: %lf, minutes in days: %lf",minutes,years,days);
    return 0;
}
/* Output: 
Enter the value to compute: 500000000
minutes: 500000000, minutes in a year: 951.293760, minutes in days: 347222.222222
*/
