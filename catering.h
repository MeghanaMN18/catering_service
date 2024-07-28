
#ifndef CATERING_H_INCLUDED
#define CATERING_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ITEMS 20

void clearInputBuffer();
int getValidInt();
void displayWelcome();
void displayUserMenu();
void displayServingStyles();
int getServingStyleCost(char *serving_style);
void calculateCost(int num_people, int base_cost_per_person, int serving_style_cost, const char *event_name, const char *serving_style);
void displayItems(const char items[MAX_ITEMS][30], int count);
void addItem(char items[MAX_ITEMS][30], int *count, const char new_item[30]);
void deleteItem(char items[MAX_ITEMS][30], int *count);
void modifyItems(char items[MAX_ITEMS][30], int *count);
void saveOrderToFile(const char *event_name, int num_people, int base_cost_per_person, int serving_style_cost, char items[MAX_ITEMS][30], int item_count, const char *serving_style);
void viewTransactions();
void marriage();
void namingCeremony();
void birthdayParty();
void houseWarmingCeremony();

#endif


