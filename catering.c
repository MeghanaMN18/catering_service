#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ITEMS 20

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getValidInt() {
    int value;
    char buffer[100];

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);

        // Check if input is numeric
        int is_numeric = 1;
        for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++) {
            if (!isdigit(buffer[i]) && buffer[i] != '-') {
                is_numeric = 0;
                break;
            }
        }

        if (is_numeric && sscanf(buffer, "%d", &value) == 1) {
            break;
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    }

    return value;
}

void displayWelcome() {
    printf("\n========================================\n");
    printf("   Welcome to our Catering Service App  \n");
    printf("========================================\n");
    printf("We are delighted to serve you the best\n");
    printf("catering services for your special events.\n");
    printf("========================================\n");
}

void displayUserMenu() {
    printf("\n===== Catering Service Menu =====\n");
    printf("1. Marriage Function (min 50 people)\n");
    printf("2. Naming Ceremony (min 30 people)\n");
    printf("3. Birthday Party (min 20 people)\n");
    printf("4. House Warming Ceremony (min 25 people)\n");
    printf("5. Exit\n");
    printf("=================================\n");
}

void displayServingStyles() {
    printf("\n===== Serving Styles =====\n");
    printf("1. Buffet (Rs. 50 per person)\n");
    printf("2. Plated (Rs. 100 per person)\n");
    printf("3. Family-Style (Rs. 75 per person)\n");
    printf("===========================\n");
}

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

void calculateCost(int num_people, int base_cost_per_person, int serving_style_cost, const char *event_name, const char *serving_style) {
    float total_cost = num_people * (base_cost_per_person + serving_style_cost);

    printf("\nTotal cost for %d people at %s:\n", num_people, event_name);
    printf("Base Cost per Person: Rs. %d\n", base_cost_per_person);
    printf("Serving Style Cost per Person: Rs. %d\n", serving_style_cost);
    printf("Total Cost: Rs. %.2f\n", total_cost);
    printf("Serving Style: %s\n", serving_style);
}

void displayItems(const char items[MAX_ITEMS][30], int count) {
    printf("\nCurrent Menu Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, items[i]);
    }
}

void addItem(char items[MAX_ITEMS][30], int *count, const char new_item[30]) {
    if (*count >= MAX_ITEMS) {
        printf("Cannot add more items. Maximum limit reached.\n");
        return;
    }

    strcpy(items[*count], new_item);
    (*count)++;
    printf("Item added successfully!\n");
}

void deleteItem(char items[MAX_ITEMS][30], int *count) {
    if (*count == 0) {
        printf("No items to delete.\n");
        return;
    }

    displayItems(items, *count);

    int choice;
    printf("Enter the number of the item to delete: ");
    choice = getValidInt();

    if (choice < 1 || choice > *count) {
        printf("Invalid choice.\n");
        return;
    }

    for (int i = choice - 1; i < *count - 1; i++) {
        strcpy(items[i], items[i + 1]);
    }

    (*count)--;
    printf("Item deleted successfully!\n");
}

void modifyItems(char items[MAX_ITEMS][30], int *count) {
    int choice;
    char additionalItems[5][30] = {
        "Raita",
        "Butter Naan",
        "Mango Lassi",
        "Rasgulla",
        "Ice Cream"
    };

    do {
        printf("\n===== Modify Menu Options =====\n");
        printf("1. Add an item\n");
        printf("2. Delete an item\n");
        printf("3. Done\n");
        printf("Enter your choice: ");
        choice = getValidInt();

        switch (choice) {
            case 1:
                printf("Additional Items:\n");
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\n", i + 1, additionalItems[i]);
                }
                printf("Enter the number of the item to add: ");
                int addChoice = getValidInt();
                if (addChoice < 1 || addChoice > 5) {
                    printf("Invalid choice!\n");
                } else {
                    addItem(items, count, additionalItems[addChoice - 1]);
                }
                break;
            case 2:
                deleteItem(items, count);
                break;
            case 3:
                printf("Exiting modify menu options.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}

void saveOrderToFile(const char *event_name, int num_people, int base_cost_per_person, int serving_style_cost, char items[MAX_ITEMS][30], int item_count, const char *serving_style) {
    FILE *file = fopen("orders.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    float total_cost = num_people * (base_cost_per_person + serving_style_cost);
    fprintf(file, "\n===== New Order =====\n");
    fprintf(file, "Event: %s\n", event_name);
    fprintf(file, "Number of People: %d\n", num_people);
    fprintf(file, "Base Cost per Person: Rs. %d\n", base_cost_per_person);
    fprintf(file, "Serving Style Cost per Person: Rs. %d\n", serving_style_cost);
    fprintf(file, "Total Cost: Rs. %.2f\n", total_cost);
    fprintf(file, "Serving Style: %s\n", serving_style);
    fprintf(file, "Menu Items:\n");
    for (int i = 0; i < item_count; i++) {
        fprintf(file, "%d. %s\n", i + 1, items[i]);
    }
    fprintf(file, "========================\n");

    fclose(file);
}

void viewTransactions() {
    FILE *file = fopen("orders.txt", "r");
    if (file == NULL) {
        printf("No transactions available.\n");
        return;
    }

    char ch;
    printf("\n===== Transactions of the Day =====\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("===================================\n");

    fclose(file);
}

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

int main() {
    displayWelcome();

    while (1) {
        int user_type;
        printf("\nEnter 1 if you are a user, Enter 2 if you are the owner: ");
        user_type = getValidInt();

        if (user_type == 1) {
            displayUserMenu();
            int choice;
            printf("Enter your choice: ");
            choice = getValidInt();

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
                    houseWarmingCeremony();
                    break;
                case 5:
                    printf("Exiting. Thank you!\n");
                    exit(0);
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
            }
        } else if (user_type == 2) {
            char owner_password[] = "owner123"; // Define your password here
            char input_password[50];

            printf("Enter the owner password: ");
            scanf("%s", input_password);
            clearInputBuffer();

            if (strcmp(owner_password, input_password) == 0) {
                viewTransactions();
            } else {
                printf("Incorrect password! Access denied.\n");
            }
        } else {
            printf("Invalid input. Please enter 1 for user or 2 for owner.\n");
        }
    }

    return 0;
}


