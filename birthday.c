#include "catering.h"
void birthdayParty() {
    printf("\n===== Birthday Party Catering Service Menu =====\n");
    printf("1. Vegetable Pizza\n");
    printf("2. Veggie Burgers\n");
    printf("3. French Fries\n");
    printf("4. Veggie Hot Dogs\n");
    printf("5. Vegetable Spring Rolls\n");
    printf("6. Macaroni and Cheese\n");
    printf("7. Fruit Platter\n");
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
    printf("Enter the number of people attending the birthday party: ");
    scanf("%d", &num_people);

    calculateCost(num_people, 250, "Birthday Party", serving_style); // Assuming each person costs Rs. 250 for birthday party

    printf("Preferred service style: %s\n", serving_style);
    printf("Thank you for choosing our service!\n");
}
