#include <stdio.h>
#include <stdlib.h>

int printMenu() {
    system("clear");  // use "cls" for Windows
    int response;
    fprintf(stdout, "*********************************************\n");
    fprintf(stdout, "McDowell's Restaurant\n");
    fprintf(stdout, "*********************************************\n\n");
    fprintf(stdout, "Make your selection from the menu below:\n\n");
    fprintf(stdout, "     1. Regular Hamburger             $0.99\n");
    fprintf(stdout, "     2. Regular Cheeseburger          $1.09\n");
    fprintf(stdout, "     3. Fish Sandwich                 $1.49\n");
    fprintf(stdout, "     4. Half-pounder w/Cheese         $2.79\n");
    fprintf(stdout, "     5. French fries                  $0.99\n");
    fprintf(stdout, "     6. Large soft drink              $0.99\n\n");
    fprintf(stdout, "Type q or Q when you are finished with your selections.\n\n");
    fprintf(stdout, "*********************************************\n\n");
    fprintf(stdout, "Select 1, 2, 3, 4, 5, or 6 ---> \n\n");
    fscanf(stdin, "%d", &response);
    return response;
}

int main() {
    int s;
    float p = 0.0f, x;
    int response;

    response = printMenu();
    printf("How many orders of item number %d would you like?\n", response);
    scanf("%d", &s);

    switch (response) {
        case 1:
            printf("You have ordered %d order(s) of the Regular Hamburger\n", s);
            p = s * 0.99;
            printf("Your total is $%.2f\n\n", p);
            break;
        case 2:
            printf("You have ordered %d order(s) of the Regular Cheeseburger\n", s);
            p = s * 1.09;
            printf("Your total is $%.2f\n\n", p);
            break;
        case 3:
            printf("You have ordered %d order(s) of the Fish Sandwich\n", s);
            p = s * 1.49;
            printf("Your total is $%.2f\n\n", p);
            break;
        case 4:
            printf("You have ordered %d order(s) of the Half-pounder w/Cheese\n", s);
            p = s * 2.79;
            printf("Your total is $%.2f\n\n", p);
            break;
        case 5:
            printf("You have ordered %d order(s) of French Fries\n", s);
            p = s * 0.99;
            printf("Your total is $%.2f\n\n", p);
            break;
        case 6:
            printf("You have ordered %d Large soft drink(s)\n", s);
            p = s * 0.99;
            printf("Your total is $%.2f\n\n", p);
            break;
        default:
            printf("Invalid selection.\n");
            return 1;
    }

    x = p * 1.13;  // Assuming 13% tax
    printf("Please pay $%.2f\n\n", x);
    printf("Thank you for eating at McDowell's!\n\n");

    return 0;
}
