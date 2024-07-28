#include "catering.h"

int getServingStyleCost(char *serving_style) {
    int cost_per_person = 0;
    int serving_style_choice;
    displayServingStyles();
    printf("Enter your choice of serving style: ");
    serving_style_choice = getValidInt();

    switch (serving_style_choice) {
        case 1:
            cost_per_person = 50;
            strcpy(serving_style, "Buffet");
            break;
        case 2:
            cost_per_person = 100;
            strcpy(serving_style, "Plated");
            break;
        case 3:
            cost_per_person = 75;
            strcpy(serving_style, "Family-Style");
            break;
        default:
            printf("Invalid choice! Defaulting to Buffet.\n");
            cost_per_person = 50;
            strcpy(serving_style, "Buffet"); // Default to Buffet
            break;
    }

    return cost_per_person;
}
