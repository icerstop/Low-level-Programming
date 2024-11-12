#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 50

struct Product{
    char name[20];
    double price;
    int quantity;
};

void add_product(struct Product products[], int *num_products);
void print_products(struct Product products[], int num_products);
void calculate_total_value(struct Product products[], int num_products);

void add_product(struct Product products[], int *num_products){
    if(*num_products >= MAX_PRODUCTS){
        printf("No space for new products!");
        return;
    }

    struct Product new_product;
    
    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &new_product.quantity);

    printf("Enter the price of the product: ");
    scanf("%lf", &new_product.price);

    products[*num_products] = new_product;
    (*num_products)++;

    printf("New product has been added!");
}

void print_products(struct Product products[], int num_products){
    printf("List of products:\n");

    for (int i=0; i < num_products; i++){
        printf("%d. %s - price: %.2f, quantity: %d\n", i+1, products[i].name, products[i].price, products[i].quantity);
    }
}

void calculate_total_value(struct Product products[], int num_products){
    double total_value = 0;

    for (int i = 0; i < num_products; i++){
        total_value += products[i].price * products[i].quantity; 
    }
    printf("Total value of the products: %.2f\n", total_value);
}


int main(){
    struct Product products[MAX_PRODUCTS];
    int num_products = 0;
    char command;

    printf("Simple product register\n\n");

    do{
        printf("Wybierz polecenie:\n");
        printf("N - new product\n");
        printf("W - show products\n");
        printf("R - calculate value of the products\n");
        printf("Q - exit program\n");

        scanf(" %c", &command);

        switch (command) {
            case 'N':
            case 'n':
                add_product(products, &num_products);
                break;
            case 'W':
            case 'w':
                print_products(products, num_products);
                break;
            case 'R':
            case 'r':
                calculate_total_value(products, num_products);
                break;
            case 'Q':
            case 'q':
                printf("End of the program\n");
                break;
            default:
                printf("Unknown command\n");
        }

        printf("\n");
    }
    while (command != 'Q' && command != 'q');

    return 0;
}