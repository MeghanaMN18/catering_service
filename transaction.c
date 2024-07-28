
#include "catering.h"

void viewTransactions() {
    FILE *file = fopen("orders.txt", "r");
    if (file == NULL) {
        printf("No transactions available.\n");
        return;
    }

    char ch;
    printf("\n===== Transactions of the Day =====\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("===================================\n");

    fclose(file);
}