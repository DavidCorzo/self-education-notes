#include <stdio.h>
#define MONTHS 12
#define YEARS 5
int main()
{
    float rainfall[YEARS][MONTHS] = {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    float averages[YEARS], current = 0;
    for (int i = 0; i < YEARS; i++){
        current = 0;
        for (int j = 0; j < MONTHS; j++){
            current += rainfall[i][j];
        }
        averages[i] = current / MONTHS;
    }
    for (int i = 0; i < 5; i++){
        printf("Year: %d> %.2f",i,averages[i]); 
        printf("\n");
    }
    return 0;
}
/* Output: 
Year: 0> 2.70
Year: 1> 3.16
Year: 2> 4.15
Year: 3> 3.67
Year: 4> 2.74

*/
