#include "catering.h"
void namingCeremony() {
    char items[MAX_ITEMS][30] = {
        "Pulao", "Paneer Tikka", "Aloo Gobi", "Chapati", "Fruit Salad",
        "Ladoo", "Halwa", "Barfi", "Rasgulla"
    };
    int item_count = 9;

    printf("\n===== Naming Ceremony Catering Service Menu =====\n");
    displayItems(items, item_count);
    printf("===========================================\n");

    modifyItems(items, &item_count);

    char serving_style[30];
    int serving_style_cost = getServingStyleCost(serving_style);

    int num_people;
    do {
        printf("Enter the number of people attending the naming ceremony (min 30 people): ");
        num_people = getValidInt();
        if (num_people < 30) {
            printf("Please enter a valid number of people.\n");
        }
    } while (num_people < 30);

    calculateCost(num_people, 300, serving_style_cost, "Naming Ceremony", serving_style);

    displayItems(items, item_count);
    printf("Thank you for choosing our service!\n");

    saveOrderToFile("Naming Ceremony", num_people, 300, serving_style_cost, items, item_count, serving_style);
}
