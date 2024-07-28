
#include "catering.h"

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