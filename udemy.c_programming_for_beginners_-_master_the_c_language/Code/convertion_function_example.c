#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int main()
{
    double value = 0;               
    char str[] = "3.5 2.5 1.26";    // The string to be converted
    char *pstr = str;               // pointer to the string to be converted
    char *ptr = NULL;               // pointer to char position after convertion              
    while (true){
        value = strtod(pstr,&ptr);  // Converting starting at pstr
        if (pstr == ptr) break;     // pstr stored of no convertion, so we are done.
        else {
            printf(" %f",value);    // output resultant value
            pstr = ptr;             // store start for the next convertion
        }
    }
    return 0;
}
/* Output: 
 3.500000 2.500000 1.260000
*/
