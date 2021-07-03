#include <stdio.h>
int main()
{
    int grades[10], count = 10; long sum = 0; float average;
    printf("\nEnter the 10 grades: \n");
    for (int i = 0; i <= count; i++)
    {
        printf("%2u> ",i + 1);
        scanf("%d",&grades[i]);
        sum += grades[i];
    }
    printf("Average: %f",(float)(sum/count));
    return 0;
}
/* Output: 
// index out of bounds visualized

Enter the 10 grades:
 1> 46
 2> 48
 3> 49
 4> 41
 5> 50
 6> 46
 7> 48
 8> 46
 9> 19
10> 79
11> 46
Average: 51.000000
*/
