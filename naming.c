#include "catering.h"
void namingCeremony() {
    printf("\n===== Naming Ceremony Catering Service Menu =====\n");
    printf("1. Pulao\n");
    printf("2. Paneer Tikka\n");
    printf("3. Aloo Gobi\n");
    printf("4. Chapati\n");
    printf("5. Fruit Salad\n");
    printf("6. Ladoo\n");
    printf("7. Halwa\n");
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
    printf("Enter the number of people attending the naming ceremony: ");
    scanf("%d", &num_people);

    calculateCost(num_people, 350, "Naming Ceremony", serving_style); // Assuming each person costs Rs. 350 for naming ceremony

    printf("Preferred service style: %s\n", serving_style);
    printf("Thank you for choosing our service!\n");
}
