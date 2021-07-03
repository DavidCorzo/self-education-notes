#include <stdio.h>
int my_global = 0; 
int my_func(void);
int main()
{
    // my_global is accesible from here. 
    printf("main: %d\n",my_global);
    printf("my_func: %d\n",my_func());
    return 0;
}
int my_func(void) {
    return my_global;
}
/* Output: 
main: 0
my_func: 0

*/
