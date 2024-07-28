#include "catering.h"
void calculateCost(int num_people, int base_cost_per_person, int serving_style_cost, const char *event_name, const char *serving_style) {
    float total_cost = num_people * (base_cost_per_person + serving_style_cost);

    printf("\nTotal cost for %d people at %s:\n", num_people, event_name);
    printf("Base Cost per Person: Rs. %d\n", base_cost_per_person);
    printf("Serving Style Cost per Person: Rs. %d\n", serving_style_cost);
    printf("Total Cost: Rs. %.2f\n", total_cost);
    printf("Serving Style: %s\n", serving_style);
}
