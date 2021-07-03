#include <stdio.h>
#include <stdbool.h>
int main(int argc, char *argv[]) // main parameters
{
    int numberOfArguments = argc;
    char *argument1 = argv[0];
    char *argument2 = argv[1];
    printf("Number of arguments: %d\n",numberOfArguments);
    printf("Argument 1 is the program name: %s\n", argument1);
    printf("Argument 2 is the program name: %s\n", argument2);

    return 0;
}
/* Output: 
DirectoryToExecutable> command_line_args.exe David 
Number of arguments: 2
Argument 1 is the program name: command_line_args
Argument 2 is the program name: David

*/
