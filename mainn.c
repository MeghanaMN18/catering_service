#include "catering.h"
#include "display.c"
#include "calculation.c"
#include "marriage.c"
#include "naming.c"
#include "birthday.c"
#include "housewarming.c"

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                houseWarming();
                break;
            case 5:
                printf("Thank you for using our service. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
