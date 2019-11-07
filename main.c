#include <stdio.h>
#include "display.h"
#include "getChoices.h"
#include "user.h"

#define MAX_FOOD_NAME 30
#define MAX_MODEL_NAME 20
#define MAX_DRINK_NAME 30
#define MAX_CUTLERY_NAME 30

int main() {
    int t = 0;
    int stop = 0;
    char user[50], pass[50];
    int noOfFoodTypes = 3,drinkChoice, noOfDrinks = 5, drinksPrices[] = {5, 5, 5, 4}, noOfModels[] = {3, 2, 4};
    int foodChoice, modelChoice, cutlery = 2, cutleryChoice;
    char foodName[][30] = {"Pizza", "Pasta", "Salad"};
    char food[3][4][MAX_MODEL_NAME] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
            {"Chicken Alfredo", "Mac & Cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    int prices[3][4] = {{21, 23, 19}, {23, 21}, {23, 22, 19, 21}};
    char cut[][MAX_CUTLERY_NAME] = {"Yes!", "No, thanks!"}, add[50], drinks[][MAX_DRINK_NAME] = {"Coca-Cola", "Fanta", "Lipton", "Water", "No, thanks!"};
    while (!stop) {
        switch (t) {
            case 0:{
                userInput(user, pass);
                t++;
                break;
            }
            case 1: {
                foodOrderDisplay(noOfFoodTypes, foodName);
                foodChoice = getChoice(noOfFoodTypes, &t);
                break;
            }
            case 2: {
                foodModelDisplay(noOfModels[foodChoice], foodName[foodChoice], food[foodChoice], prices[foodChoice]);
                modelChoice = getChoice(noOfModels[foodChoice], &t);
                break;
            }
            case 3: {
                drinkDisplay(noOfDrinks, foodName[foodChoice], drinks, drinksPrices);
                drinkChoice = getChoice(noOfDrinks, &t);
                break;
            }
            case 4: {
                cutDisplay(cutlery, cut);
                cutleryChoice = getChoice(cutlery, &t);
                break;
            }
            case 5: {
                printf("Any additional info? \n");
                gets(add);
                t++;
                break;
            }
            case 6: {
                accountDataDisplay(user);
                orderDisplay(food[foodChoice][modelChoice], prices[foodChoice][modelChoice], drinks[drinkChoice], drinksPrices[drinkChoice], cut[cutleryChoice], add);
                stop = getFinal(&t, user);
                break;
            }
        }
    }
    return 0;
}