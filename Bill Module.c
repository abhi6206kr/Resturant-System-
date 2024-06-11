#include <stdio.h>
#include <string.h>

// Define a structure for the item and customer
struct Item {
    int productno;
    char productname[50];
    int quantity;
    int price;
} item;

struct Customer {
    int productno;
    char productname[50];
    int quantity;
    int price;
} cst[100];

int ti = 0; // Counter for customer purchases

void bill() {
    int na = 0; // used for product number in scanf function
    int a = 0; // quantity requested by customer
    int cont = 0; // counter for non-matching products
    int k = 0; // user's choice for shopping more
    int l = 0; // counter for total products
    int bi = 0; // counter for out of stock
    int ln = 0; // counter for product match occurrences

    printf("\t");
l3:
    printf("Enter the Product Number: ");
    scanf("%d", &na);
    printf("\n");

    FILE *fp = fopen("Records.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }

    FILE *fptr = fopen("temp.txt", "w");
    if (fptr == NULL) {
        printf("Error: Unable to open the temporary file.\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%d %s %d %d", &item.productno, item.productname, &item.quantity, &item.price) != EOF) {
        l++;
        if (item.productno == na) {
            ln++;
            if (ln == 2) break; // Ensure only one product is processed at a time

            printf("Enter the Quantity: ");
            scanf("%d", &a);
            if (a <= item.quantity) {
                cst[ti].productno = item.productno;
                strcpy(cst[ti].productname, item.productname);
                cst[ti].quantity = a;
                cst[ti].price = item.price;
                item.quantity -= a;
                ti++;
            } else {
                printf("Sorry, Out of Stock\n");
                bi++;
            }
        }

        // Write current item details to the temporary file
        fprintf(fptr, "%d\t%s\t%d\t%d\n", item.productno, item.productname, item.quantity, item.price);
    }

    if (l == cont) {
        printf("Error: Choose Properly\n");
    }

    fclose(fptr);
    fclose(fp);

    remove("Records.txt");
    rename("temp.txt", "Records.txt");

    ln = 0;
    printf("Do you Want to Shop More:\nPress 1 for More\nPress 2 to Exit: ");
    scanf("%d", &k);
    if (k == 1) {
        goto l3;
    }
}

int main() {
    bill();
    return 0;
}
