
#include "catering.h"

void displayItems(const char items[MAX_ITEMS][30], int count) {
    printf("\nCurrent Menu Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, items[i]);
    }
}