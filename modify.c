
#include "catering.h"

void modifyItems(char items[MAX_ITEMS][30], int *count) {
    int choice;
    char additionalItems[5][30] = {
        "Raita",
        "Butter Naan",
        "Mango Lassi",
        "Rasgulla",
        "Ice Cream"
    };

    do {
        printf("\n===== Modify Menu Options =====\n");
        printf("1. Add an item\n");
        printf("2. Delete an item\n");
        printf("3. Done\n");
        printf("Enter your choice: ");
        choice = getValidInt();

        switch (choice) {
            case 1:
                printf("Additional Items:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\n", i + 1, additionalItems[i]);
                }
                printf("Enter the number of the item to add: ");
                int addChoice = getValidInt();
                if (addChoice < 1 || addChoice > 5) {
                    printf("Invalid choice!\n");
                } else {
                    addItem(items, count, additionalItems[addChoice - 1]);
                }
                break;
            case 2:
                deleteItem(items, count);
                break;
            case 3:
                printf("Exiting modify menu options.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}
