#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getchoice.h"
#include "users.h"
#include "display.h"

#define LOAD_DATA "Please load the data :"
#define MAX_FOOD_NAME 100
#define MAX_MODEL_SPEC_NAME 300
#define MAX_MODEL_NAME 100
#define MAX_DRINK_NAME 50
#define MAX_CUTLERY_NAME 50
#define MAX_LINE 100
#define FILE_PATH "E:/bag/in.txt"

int main() {

    FILE *foodOrderFile;
    foodOrderFile = fopen(FILE_PATH,"r");
    if  (foodOrderFile==NULL)
    {
        perror("File could not be open");
        exit(-1);
    }

    char string[500],firstLine[20],add[50],*point;

    int nrOfFoodTypes,nrDrinks,noOfModels[MAX_MODEL_NAME],k;
    printf("%s \n",LOAD_DATA);
    fgets(firstLine,MAX_LINE,foodOrderFile);
    firstLine[strlen(firstLine)-1]='\0';
    sscanf(firstLine, "%d", &nrOfFoodTypes);

    char ** foodName = (char**)malloc(nrOfFoodTypes * sizeof(char*));
    char *** food = (char***)malloc(nrOfFoodTypes * sizeof(char**));
    double ** prices = (double**)malloc(nrOfFoodTypes * sizeof(double*));
    for(int i=0;i<nrOfFoodTypes;i++) {
        foodName[i] = (char*)malloc(MAX_FOOD_NAME * sizeof(char));
        food[i] = (char**)malloc(MAX_MODEL_NAME * sizeof(char*));
        prices[i] = (double*)malloc(MAX_MODEL_NAME * sizeof(double));

        fgets(string,MAX_LINE,foodOrderFile);
        string[strlen(string)-1]='\0';
        point = strtok(string, ":");
        strcpy(foodName[i], point);
        foodName[i][strlen(foodName[i])-2]='\0';
        point = strtok(NULL, "(");
        k = 0;

        while (point) {
            point = strtok(NULL, "-");
            food[i][k] = (char*)malloc(MAX_MODEL_SPEC_NAME * sizeof(char));
            strcpy(food[i][k], point);
            food[i][k][strlen(point) - 1]='\0';
            point = strtok(NULL, ")");
            sscanf(point, "%lf", &prices[i][k]);
            point = strtok(NULL, "(");
            k++;
        }
        noOfModels[i]=k;
    }

    fgets(firstLine,MAX_LINE,foodOrderFile);
    firstLine[strlen(firstLine)-1]='\0';
    sscanf(firstLine, "%d", &nrDrinks);
    char ** drinks = (char**)malloc(nrDrinks * sizeof(char*));
    double * drinkPrices = (double*)malloc(nrDrinks * sizeof(double));

    fgets(string,MAX_LINE,foodOrderFile);
    string[strlen(string)-1]='\0';
    strrev(string);
    point = strtok(string, "-");

    for(int i=0;i<nrDrinks;i++){
        if(i)
            point = strtok(NULL, "-");
        sscanf(strrev(point), "%lf", &drinkPrices[i]);
        drinks[i] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        point = strtok(NULL, "(");
        strcpy(drinks[i], point);
        strrev(drinks[i]);
    }

    char cut[][MAX_CUTLERY_NAME] = {"Yes!", "No thanks!"};
    char username[50];
    char password[50];
    int foodChoice, modelChoice, drinkChoice, cutleryChoice, confirmChoice;
    int state=0, stop=0,okcut=0,cutlery=2;

    while(!stop) {
        switch(state) {
            case 0: {
                printf("Welcome to Food Thingies!\n");
                userInput(username, password,foodOrderFile);
                state++;
                break;
            }
            case 1: {
                foodOrderDsiplay(nrOfFoodTypes, foodName);
                foodChoice = getChoice(nrOfFoodTypes, &state,foodOrderFile);
                break;
            }
            case 2: {
                foodModelDisplay(noOfModels[foodChoice], foodName[foodChoice], food[foodChoice],
                                 prices[foodChoice]);
                modelChoice = getChoice(noOfModels[foodChoice], &state,foodOrderFile);
                break;
            }
            case 3: {
                displayDrinks(foodName[foodChoice], nrDrinks, drinks, drinkPrices);
                drinkChoice = getChoice(nrDrinks, &state,foodOrderFile);
                break;
            }
            case 4: {
                cutleryDisplay(cutlery, cut);
                cutleryChoice = getChoice(cutlery, &state,foodOrderFile);
                break;
            }
            case 5: {
                getAdditionalInfo(add, &state);
                break;
            }
            case 6: {
                displayOrder(food[foodChoice][modelChoice], prices[foodChoice][modelChoice],
                             drinks[drinkChoice], drinkPrices[drinkChoice], cut[cutleryChoice], add, username);
                confirmChoice = getChoice(1, &state,foodOrderFile);
                confirmOrder(confirmChoice, &stop, &state);
                break;
            }
        }
    }
    //
    printf("Order confirmed! Thank you for buying from us, %s!\n", username);
    for(int i=0;i<nrOfFoodTypes;i++){
        for(int j=0; j <= noOfModels[i]; j++)
            free(food[i][j]);

        free(foodName[i]);
        free(prices[i]);
        free(food[i]);
    }
    free(foodName);
    free(food);
    free(prices);

    for(int i=0;i<nrDrinks;i++)
        free(drinks[i]);

    free(drinkPrices);
    free(drinks);

    return 0;
}
