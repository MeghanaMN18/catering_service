#include "catering.h"
#include "add.c"
#include "clearinput.c"
#include "delete.c"
#include "displayItems.c"
#include "displayMenu.c"
#include "displaywelcome.c"
#include "getvalid.c"
#include "modify.c"
#include "saveOrder.c"
#include "serving.c"
#include "servingCost.c"
#include "transaction.c"
#include "calculation.c"
#include "marriage.c"
#include "naming.c"
#include "birthday.c"
#include "housewarming.c"
#include <string.h>

int main() {
    displayWelcome();

    while (1) {
        int user_type;
        printf("\nEnter 1 if you are a user, Enter 2 if you are the owner: ");
        user_type = getValidInt();

        if (user_type == 1) {
            displayUserMenu();
            int choice;
            printf("Enter your choice: ");
            choice = getValidInt();

            switch (choice) {
                case 1:
                    marriage();
                    break;
                case 2:
                    namingCeremony();
                    break;
                case 3:
                    birthdayParty();
                    break;
                case 4:
                    houseWarmingCeremony();
                    break;
                case 5:
                    printf("Exiting. Thank you!\n");
                    exit(0);
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
            }
        } else if (user_type == 2) {
            char owner_password[] = "owner123"; // Define your password here
            char input_password[50];

            printf("Enter the owner password: ");
            scanf("%s", input_password);
            clearInputBuffer();

            if (strcmp(owner_password, input_password) == 0) {
                viewTransactions();
            } else {
                printf("Incorrect password! Access denied.\n");
            }
        } else {
            printf("Invalid input. Please enter 1 for user or 2 for owner.\n");
        }
    }

    return 0;
}
