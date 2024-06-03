#include "fcatering.h"
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
