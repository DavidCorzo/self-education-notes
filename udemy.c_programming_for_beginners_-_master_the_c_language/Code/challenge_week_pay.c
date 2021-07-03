#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40
/*Overtime: exces of 40 hours = time and a half. */
#include <stdio.h>
int main()
{
    double hours = 0, grossPay = 0, taxes = 0, netPay = 0, overTimePay = 0;
    printf("Please enter the number of hours worked this week: ");
    scanf("%lf",&hours);
    if (hours <= 40) {
        grossPay = hours * PAYRATE;
    } else {
        grossPay = 40 * PAYRATE;
        overTimePay = (hours - 40) * (PAYRATE * 1.5);
        grossPay += overTimePay;
    }

    if (grossPay <= 300) {
        taxes = grossPay * TAXRATE_300;
    } else if (grossPay > 300 && grossPay <= 450) {
        taxes = 300 * TAXRATE_300;
        taxes += (grossPay - 300) * TAXRATE_150; 
    } else if (grossPay > 450) {
        taxes = 300 * TAXRATE_300;
        taxes += 150 * TAXRATE_150;
        taxes += (grossPay - 300 - 150) * TAXRATE_REST;
    }

    netPay = grossPay - taxes;
    printf("Gross pay: %.2f\n",grossPay);
    printf("Taxes: %.2f\n",taxes);
    printf("Net pay: %.2f\n",netPay);
    printf("Overtime: %.2f\n",overTimePay);   
    return 0;
}
/* Output: 
Please enter the number of hours worked this week: 30
Gross pay: 360.00
Taxes: 57.00
Net pay: 303.00
Overtime: 0.00

*/
