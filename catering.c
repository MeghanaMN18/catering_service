#include <stdio.h>
#include <string.h>

void displayMenu() {
    printf("\n===== Catering Service Menu =====\n");
    printf("1. Marriage Function\n");
    printf("2. Naming Ceremony\n");
    printf("3. Birthday Party\n");
    printf("4. House Warming Ceremony\n");
    printf("5. Exit\n");
    printf("=================================\n");
}

void calculateCost(int num_people, int cost_per_person, const char *event_name, const char *serving_style) {
    float discount_rate = 0.0;

    if (num_people >= 200) {
        discount_rate = 0.30; // 30% discount for 200 or more people
    } else if (num_people >= 100) {
        discount_rate = 0.15; // 15% discount for 100 or more people
    }

    float total_cost = num_people * cost_per_person;
    float discount_amount = total_cost * discount_rate;
    float grand_total= total_cost - discount_amount;

    printf("\nTotal cost before discount for %d people at %s with %s: Rs. %.2f\n", num_people, event_name, serving_style, total_cost);

    if (discount_rate > 0.0) {
        printf("Discount rate: %.0f%%\n", discount_rate * 100);
        printf("Discount amount: Rs. %.2f\n", discount_amount);
        printf("Total cost after discount: Rs. %.2f\n", grand_total);
    } else {
        printf("No discount applied.\n");
    }
}

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

    calculateCost(num_people, 300, "House Warming Ceremony", serving_style); // Assuming each person costs Rs. 300 for house warming

    printf("Preferred service style: %s\n", serving_style);
    printf("Thank you for choosing our service!\n");
}

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

