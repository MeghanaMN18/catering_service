#include "catering.h"
void houseWarming() {
    printf("\n===== House Warming Catering Service Menu =====\n");
    printf("1. Samosa\n");
    printf("2. Dhokla\n");
    printf("3. Masala Chai\n");
    printf("4. Pani Puri\n");
    printf("5. Pav Bhaji\n");
    printf("6. Kachori\n");
    printf("7. Kulfi\n");
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
    printf("Enter the number of people attending the house warming ceremony: ");
    scanf("%d", &num_people);

    calculateCost(num_people, 250, serving_style_cost, "House Warming Ceremony", serving_style); // Assuming each person costs Rs. 250 for house warming
 

    printf("Preferred service style: %s\n", serving_style);
    printf("Thank you for choosing our service!\n");
}
