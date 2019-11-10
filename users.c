//
// Created by TheRa on 11/7/2019.
//

#include <stdio.h>
#include <string.h>

#define MAX_SPECIFIC_FOOD_NAME 20
#define MAX_DRINK_NAME 30
#define MAX_CUTLERY_NAME 30

void userInput(char user[], char pass[]) {
    printf("\n------------------\n");
    printf("Hello world !\n");
    printf("--- Username \n");
    gets(user);
    printf("--- Password \n");
    gets(pass);
}

void orderDisplay(char food[], int prices, char drinks[], int drinksPrices, char cut[], char additionalInfo[]) {
    int drinkChoice;

    printf("Food items: \n");
    printf("--- %s: %d \n", food, prices);
    if (drinkChoice + 'a' == 'e') {
        printf("--- Drinks: %s \n", drinks);
    }
    else {
        printf("--- Drinks: %s: %d \n", drinks, drinksPrices);
    }
    printf("Cutlery: %s \n", cut);
    if (strcmp(additionalInfo, "")!=0)
        printf("Additional info: %s \n", additionalInfo);
    printf("Payment amount: %d \n", prices + drinksPrices);
    printf("\n------------------\n\n");
    printf("\n");
}

void accountDataDisplay(char username[]) {
    printf("This is your order: \n \n");
    printf("Name: %s \n", username);
}

