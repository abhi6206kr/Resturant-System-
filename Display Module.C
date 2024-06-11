#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

typedef struct {
    int productno;
    char productname[50];
    int quantity;
    int price;
} Product;

Product item;
int n = 0;  // Number of products

void create() {
    int i = 0;
    FILE *fp;
    fp = fopen("Records.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    printf("\tEnter the Number of Records: ");
    scanf("%d", &n);
    printf("\n");

    FILE *fpq;
    fpq = fopen("Quantity.txt", "w");
    if (fpq == NULL) {
        printf("Error opening quantity file\n");
        fclose(fp);
        return;
    }
    fprintf(fp, "productno\tProductName\tQuantity\tPrice\n");
    fprintf(fpq, "%d", n);
    fclose(fpq);

    while (i < n) {
        printf("\tEnter Product Code: ");
        scanf("%d", &item.productno);
        printf("\tEnter Product Name: ");
        scanf("%s", item.productname);
        printf("\tEnter Quantity: ");
        scanf("%d", &item.quantity);
        printf("\tEnter Price: ");
        scanf("%d", &item.price);
        printf("\n");
        i++;
        fprintf(fp, "%d\t%s\t%d\t%d\n", item.productno, item.productname, item.quantity, item.price);
    }
    fclose(fp);
    printf("\tRecords are Created\n\n");
}

void display() {
    int nk = 0;
    FILE *fp;
    fp = fopen("Records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    printf("\t==============================================================\n");
    printf("\t|Product Number\t|Product Name\t|Quantity\t|Price\t\n");
    printf("\t==============================================================\n");

    char header[200]; // To skip the header line in the file
    fgets(header, sizeof(header), fp);

    while (fscanf(fp, "%d\t%s\t%d\t%d\n", &item.productno, item.productname, &item.quantity, &item.price) != EOF) {
        printf("\t  %14d|\t%12s|\t%8d|\t%d|\n", item.productno, item.productname, item.quantity, item.price);
        nk++;
    }
    if (nk == 0) {
        printf("\tThere are no items in Cart\n");
    }

    printf("\t==============================================================\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Create Records\n");
        printf("2. Display Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
