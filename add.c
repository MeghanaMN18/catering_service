
#include "catering.h"

void addItem(char items[MAX_ITEMS][30], int *count, const char new_item[30]) {
    if (*count >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }

    strcpy(items[*count], new_item);
    (*count)++;
    printf("Item added successfully!\n");
}