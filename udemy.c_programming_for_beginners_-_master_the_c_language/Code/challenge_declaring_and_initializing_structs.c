#include <stdio.h>
#include <stdlib.h>

struct employee {
    char name[30];
    char hireDate[20];
    float salary;
};

int main()
{
    struct employee employee1 = {
        "David Corzo",
        "2020/07/02",
        4500
    };
    printf("Name: %s\nHiredate: %s\nSalary: $%.2f"
            ,employee1.name, employee1.hireDate, employee1.salary);
    return 0;
}
/* Output: 
Name: David Corzo
Hiredate: 2020/07/02
Salary: $4500.00
*/
