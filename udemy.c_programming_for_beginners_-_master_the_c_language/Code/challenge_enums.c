#include <stdio.h>
int main(int argc, char const *argv[])
{
    enum company { GOOGLE,FACEBOOK,XEROX,YAHOO,EBAY,MICROSOFT };
    enum company x = XEROX;
    enum company g = GOOGLE;
    enum company e = EBAY;
    printf("%d %d %d",x,g,e);
    return 0;
}
/* Output: 
2 0 4
*/
