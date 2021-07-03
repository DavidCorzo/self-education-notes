#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM 20
int main()
{
    int guess,num;
    time_t t; srand((unsigned) time(&t));
    num = rand() % NUM; printf("NUM:%d\n",num);
    printf("This is a guessing game.\n");
    printf("Choose a number between 0 and 20 which you must guess.\n");
    for (int i = 0, j = 5; i < 5; i++) {
        do {
            printf("\nEnter a guess: ");
            scanf("%d",&guess);
            if (guess < 0 || guess > 20) printf("\nNumbers must be between 0 and 20.");
        } while (guess < 0 || guess > 20);
        
        if (guess == num) {
            printf("\nCongrats, you guessed it.");
            break;
        } else {
            --j == 0 ? printf("No tries left. \n") : printf("Not correct. %d tries left.\n",j);
        }
    }
    
    return 0;
}
/* Output: 
NUM:5
This is a guessing game.
Choose a number between 0 and 20 which you must guess.

Enter a guess: 12
Not correct. 4 tries left.

Enter a guess: 13
Not correct. 3 tries left.

Enter a guess: 9
Not correct. 2 tries left.

Enter a guess: 6
Not correct. 1 tries left.

Enter a guess: -1000000

Numbers must be between 0 and 20.
Enter a guess: 45

Numbers must be between 0 and 20.
Enter a guess: 4
No tries left.

*/
