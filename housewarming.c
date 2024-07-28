
#include "catering.h"
void houseWarmingCeremony() {
    char items[MAX_ITEMS][30] = {
        "Dosa", "Sambar", "Idli", "Vada", "Chutney",
        "Upma", "Pongal", "Filter Coffee", "Payasam"
    };
    int item_count = 9;

    printf("\n===== House Warming Ceremony Catering Service Menu =====\n");
    displayItems(items, item_count);
    printf("===========================================\n");

    modifyItems(items, &item_count);

    char serving_style[30];
    int serving_style_cost = getServingStyleCost(serving_style);

    int num_people;
    do {
        printf("Enter the number of people attending the house warming ceremony (min 25 people): ");
        num_people = getValidInt();
        if (num_people < 25) {
            printf("Please enter a valid number of people.\n");
        }
    } while (num_people < 25);

    calculateCost(num_people, 250, serving_style_cost, "House Warming Ceremony", serving_style);

    displayItems(items, item_count);
    printf("Thank you for choosing our service!\n");

    saveOrderToFile("House Warming Ceremony", num_people, 250, serving_style_cost, items, item_count, serving_style);
}
