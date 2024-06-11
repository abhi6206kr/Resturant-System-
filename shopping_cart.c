#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int productno;
    char productname[50];
    int price;
    int quantity;
    int amount;
} Product;

Product cst[MAX_PRODUCTS];
int ti = 0;  // total items in the cart

void invoice() {
    int j;
    int o;
    float gt = 0;
    if (ti == 0) {
        printf("There are No Products in your Cart");
        printf("\n");
        return;
    }
    printf("\n\n");
    printf("****************************INVOICE**************************");
    printf("\n\n");
    printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
    printf("*************************************************************\n");
    for (o = 0; o < ti; o++) {
        cst[o].amount = 0;
        cst[o].amount = (cst[o].price * cst[o].quantity);
        gt = gt + cst[o].amount;
    }
    for (j = 0; j < ti; j++) {
        printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",
               cst[j].productno, cst[j].productname, cst[j].price,
               cst[j].quantity, cst[j].amount);
    }
    printf("\nAmount Payable: $%.2f", gt);
    printf("\n");
    printf("Thank you for Shopping");
    printf("\n");
    printf("Visit Again");
    printf("\n");
}

void addProductToCart(int productno, const char *productname, int price, int quantity) {
    if (ti >= MAX_PRODUCTS) {
        printf("Cart is full!\n");
        return;
    }
    cst[ti].productno = productno;
    strcpy(cst[ti].productname, productname);
    cst[ti].price = price;
    cst[ti].quantity = quantity;
    ti++;
}

int main() {
    addProductToCart(101, "Burger", 5, 2);
    addProductToCart(102, "Fries", 3, 3);
    addProductToCart(103, "Soda", 2, 5);

    invoice();
    return 0;
}
