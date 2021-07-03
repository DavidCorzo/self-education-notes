#include <stdio.h>
int main()
{
    int grades[10], count = 10; long sum = 0; float average;
    printf("\nEnter the 10 grades: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%2u> ",i + 1);
        scanf("%d",&grades[i]);
        sum += grades[i];
    }
    printf("Average: %f",(float)(sum/count));
    return 0;
}
/* Output: 

Enter the 10 grades:
 1> 4
 2> 45
 3> 13
 4> 46
 5> 46
 6> 46
 7> 165
 8> 2
 9> 18
10> 13
Average: 39.000000
*/
