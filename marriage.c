#include "catering.h"
void marriage() {
    char items[MAX_ITEMS][30] = {
        "Vegetable Biryani", "Paneer Butter Masala", "Mixed Veg Curry", "Naan", "Palak Paneer",
        "Gulab Jamun", "Rasmalai", "Kaju Katli", "Jalebi"
    };
    int item_count = 9;

    printf("\n===== Marriage Catering Service Menu =====\n");
    displayItems(items, item_count);
    printf("===========================================\n");

    modifyItems(items, &item_count);

    char serving_style[30];
    int serving_style_cost = getServingStyleCost(serving_style);

    int num_people;
    do {
        printf("Enter the number of people attending the marriage (min 50 people): ");
        num_people = getValidInt();
        if (num_people < 50) {
            printf("Please enter a valid number of people.\n");
        }
    } while (num_people < 50);

    calculateCost(num_people, 450, serving_style_cost, "Marriage", serving_style);

    displayItems(items, item_count);
    printf("Thank you for choosing our service!\n");

    saveOrderToFile("Marriage", num_people, 450, serving_style_cost, items, item_count, serving_style);
}
