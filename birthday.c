<<<<<<< HEAD

=======
>>>>>>> f0e3f666cdefc242d9d83f4f40a2a4290ff9638d
#include "catering.h"
void birthdayParty() {
    char items[MAX_ITEMS][30] = {
        "Pizza", "Burger", "French Fries", "Ice Cream", "Cake",
        "Chocolate", "Pasta", "Soft Drinks", "Cookies"
    };
    int item_count = 9;

    printf("\n===== Birthday Party Catering Service Menu =====\n");
    displayItems(items, item_count);
    printf("===========================================\n");

    modifyItems(items, &item_count);

    char serving_style[30];
    int serving_style_cost = getServingStyleCost(serving_style);

    int num_people;
    do {
        printf("Enter the number of people attending the birthday party (min 20 people): ");
        num_people = getValidInt();
        if (num_people < 20) {
            printf("Please enter a valid number of people.\n");
        }
    } while (num_people < 20);

    calculateCost(num_people, 200, serving_style_cost, "Birthday Party", serving_style);

    displayItems(items, item_count);
    printf("Thank you for choosing our service!\n");

    saveOrderToFile("Birthday Party", num_people, 200, serving_style_cost, items, item_count, serving_style);
}
