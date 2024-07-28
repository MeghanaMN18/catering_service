
#include "catering.h"

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