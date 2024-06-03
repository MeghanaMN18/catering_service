#include "catering.h"
void marriage() {
    printf("\n===== Marriage Catering Service Menu =====\n");
    printf("1. Vegetable Biryani\n");
    printf("2. Paneer Butter Masala\n");
    printf("3. Mixed Veg Curry\n");
    printf("4. Naan\n");
    printf("5. Palak Paneer\n");
    printf("6. Gulab Jamun\n");
    printf("7. Rasmalai\n");
    printf("===========================================\n");

    int serving_choice;
    printf("Enter the preferred serving style (1 for buffet, 2 for plated, 3 for family-style): ");
    scanf("%d", &serving_choice);

    char serving_style[20];
    if (serving_choice == 1) {
        strcpy(serving_style, "Buffet");
    } else if (serving_choice == 2) {
        strcpy(serving_style, "Plated");
    } else if (serving_choice == 3) {
        strcpy(serving_style, "Family-style");
    } else {
        printf("Invalid choice! Defaulting to Buffet.\n");
        strcpy(serving_style, "Buffet");
    }

    int num_people;
    printf("Enter the number of people attending the marriage: ");
    scanf("%d", &num_people);

    calculateCost(num_people, 450, "Marriage", serving_style); // Assuming each person costs Rs. 450 for marriage

    printf("Preferred service style: %s\n", serving_style);
    printf("Thank you for choosing our service!\n");
}
