#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring a{"Hello"}; // overloaded constructor
    a.display();
    a = Mystring{"Hola"}; // overloaded constructor 
    a.display();
    a = "Bonjour";
    a.display();
    return 0;
}

/* OUTPUT:
Hello: 5
Using move assignment
Hola: 4
Using move assignment
Bonjour: 7
*/
