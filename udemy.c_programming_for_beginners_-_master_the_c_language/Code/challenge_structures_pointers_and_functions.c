#include <stdio.h>
#include <stdlib.h>

struct item {
    char *itemName;
    int quantity; 
    float price;
    float amount;
};

void read_item(struct item *pitem); 
void print_item(struct item *pitem);

int main(void)
{
    struct item it; 
    struct item *pit = &it;
    read_item(pit);
    print_item(pit);

    // delete what you malloced
    free(pit->itemName); // the structure will be deleted in the heap
    return 0;
}

void read_item(struct item *pit){
    printf("Enter the item name: \n");
    pit->itemName = (char*)malloc(30*sizeof(char));
    scanf("%[^\n]%*c",pit->itemName); // strings don't need &
    
    if (pit->itemName == NULL) // check for memory allocated 
        exit(-1);

    printf("Enter the quantity: \n");
    scanf("%d",&pit->quantity);
    // printf("%d",pit->quantity);

    printf("Enter the price: \n");
    scanf("%f",&pit->price);
    // printf("%f",pit->price);

    pit->amount = pit->price * (float)pit->quantity;
    // printf("%f",pit->amount);
}

void print_item(struct item *pit){
    printf("\nITEM: \n");
    printf("itemName: %s\n",pit->itemName);
    printf("quantity: %d\n",pit->quantity);
    printf("price: $%.2f\n",pit->price);
    printf("amount: $%.2f\n",pit->amount);
}
/* Output: 
Enter the item name:
Milk cartons
Enter the quantity:
600
Enter the price:
14.55

ITEM:
itemName: Milk cartons
quantity: 600
price: $14.55
amount: $8730.00

*/
