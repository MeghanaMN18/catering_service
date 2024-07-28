

#include "catering.h"

void deleteItem(char items[MAX_ITEMS][30], int *count) {
    if (*count == 0) {
        printf("No items to delete.\n");
        return;
    }

    displayItems(items, *count);

    int choice;
    printf("Enter the number of the item to delete: ");
    choice = getValidInt();

    if (choice < 1 || choice > *count) {
        printf("Invalid choice.\n");
        return;
    }

    for (int i = choice - 1; i < *count - 1; i++) {
        strcpy(items[i], items[i + 1]);
    }

    (*count)--;
    printf("Item deleted successfully!\n");
}