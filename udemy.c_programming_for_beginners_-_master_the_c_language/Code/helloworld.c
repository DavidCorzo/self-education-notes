#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str[100];
    float tempC = 67.0;
    float tempF = 99.0;
    sprintf(str,"Temp C:%.2f F:%.2f",tempC,tempF);
    printf("%s",str); // lcd.print(str) ?
    return 0;
}
