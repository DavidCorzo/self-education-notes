#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Family {
    char name[20]; 
    int age;
    char father[20]; 
    char mother[20];
};

bool siblings(struct Family *const pmember1, struct Family *const pmember2);
int main()
{
    struct Family var1 = {"David",20,"dad1","Mom1"}; 
    struct Family var2 = {"David",20,"dad1","Mom1"}; 
    struct Family *pvar1 = &var1; 
    struct Family *pvar2 = &var2; 
    printf("%s",siblings(pvar1,pvar2)? "true": "false");

    return 0;
}
bool siblings(struct Family *const pmember1, struct Family *const pmember2){
    if (strcmp(pmember1->mother,pmember2->mother) == 0){ // you can use the -> since they are pointers.
        return true;
    } else {
        return false;
    }
}
/* Output: 
true
*/
