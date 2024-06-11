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

int main() {
    create();
    return 0;
}
