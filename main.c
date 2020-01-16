#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getchoice.h"
#include "users.h"
#include "display.h"
#include "spec.h"
#include "food.h"

#define LOAD_DATA "Please load the data :"
#define MAX_FOOD_NAME 100
#define MAX_MODEL_SPEC_NAME 300
#define MAX_MODEL_NAME 100
#define MAX_DRINK_NAME 50
#define MAX_CUTLERY_NAME 50
#define MAX_LINE 100
#define FILE_PATH "E:/bag/in.txt"
#define FILE_PATH_OUT "E:/bag/data.txt"

int main() {

    FILE *foodOrderFile,*foodOrderFileOut;
    foodOrderFile = fopen(FILE_PATH,"r");
    foodOrderFileOut = fopen(FILE_PATH_OUT,"w");
    if  (foodOrderFile==NULL)
    {
        perror("File could not be open");
        exit(-1);
    }

    buyer b = createBuyer();

    char string[500],firstLine[20],add[50],*point;
    int nrOfFoodTypes,nrDrinks,noOfModels[MAX_MODEL_NAME],k,nrOfSpecFoodTypes[20],u=0;
    printf("%s \n",LOAD_DATA);
    fgets(firstLine,MAX_LINE,foodOrderFile);
    firstLine[strlen(firstLine)-1]='\0';
    sscanf(firstLine, "%d", &nrOfFoodTypes);

    char ** foodName = (char**)malloc(nrOfFoodTypes * sizeof(char*));
    char *** food = (char***)malloc(nrOfFoodTypes * sizeof(char**));
    double ** prices = (double**)malloc(nrOfFoodTypes * sizeof(double*));
    foodType *foodMain = (foodType *)malloc(nrOfFoodTypes * sizeof(foodType));
    for(int i=0;i<nrOfFoodTypes;i++) {
        foodName[i] = (char*)malloc(MAX_FOOD_NAME * sizeof(char));
        food[i] = (char**)malloc(MAX_MODEL_NAME * sizeof(char*));
        prices[i] = (double*)malloc(MAX_MODEL_NAME * sizeof(double));
        foodMain[i]=createFood();

        fgets(string,MAX_LINE,foodOrderFile);
        u=0;
        for(int k=0 ; k<strlen(string);k++) if(string[k]=='(') nrOfSpecFoodTypes[i]=u++;

        string[strlen(string)-1]='\0';
        point = strtok(string, ":");
        strcpy(foodMain[i].name, point);
        foodMain[i].name[strlen(foodMain[i].name)-2]='\0';
        point = strtok(NULL, "(");
        k = 0;
        readSpecAndPrice(point,food,i,&k,prices);
        noOfModels[i]=k;
        foodMain[i].noOfModels=k;

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

    char cut[20][MAX_CUTLERY_NAME] = {"Yes!", "No thanks!","No"};
    char username[50];
    char password[50];
    int foodChoice, modelChoice, drinkChoice, cutleryChoice, confirmChoice;
    int state=0, stop=0,okcut=0,cutlery=2;
    enum state {INPUT_BUYER_DATA, CHOOSE_FOOD, CHOOSE_SPECIFFIC_FOOD, CHOOSE_DRINKS,CUTLERY_CHOICE,ADDITIONAL_INFO, SIGN};
    while(!stop) {
        switch(state) {
            case INPUT_BUYER_DATA: {
                printf("Welcome to Food Thingies!\n");
                userInput(&b,foodOrderFile);
                state++;
                break;
            }
            case CHOOSE_FOOD: {
                foodOrderDsiplay(foodMain,nrOfFoodTypes);
                foodChoice = getChoice(nrOfFoodTypes, &state,foodOrderFile);
                break;
            }
            case CHOOSE_SPECIFFIC_FOOD: {
                foodModelDisplay(foodMain[foodChoice].noOfModels, foodMain[foodChoice].name, food[foodChoice],
                                 prices[foodChoice]);
                modelChoice = getChoice(foodMain[foodChoice].noOfModels, &state,foodOrderFile);
                break;
            }
            case CHOOSE_DRINKS: {
                displayDrinks(food[modelChoice][modelChoice], nrDrinks, drinks, drinkPrices);
                drinkChoice = getChoice(nrDrinks, &state,foodOrderFile);
                break;
            }
            case CUTLERY_CHOICE: {
                cutleryDisplay(cutlery, cut);
                cutleryChoice = getChoice(cutlery, &state,foodOrderFile);
                break;
            }
            case ADDITIONAL_INFO: {
                getAdditionalInfo(add, &state);
                break;
            }
            case SIGN: {
                displayOrder(food[foodChoice][modelChoice], prices[foodChoice][modelChoice],
                             drinks[drinkChoice], drinkPrices[drinkChoice], cut[cutleryChoice], add, &b.name);
                confirmChoice = getChoice(1, &state,foodOrderFile);
                confirmOrder(confirmChoice, &stop, &state);
                saveToFile(nrOfFoodTypes,foodName,nrOfSpecFoodTypes,food,prices,nrDrinks,drinks,drinkPrices,foodOrderFileOut);
                fclose(foodOrderFileOut);
                fclose(foodOrderFile);
                break;
            }
        }
    }
    //
    printf("Order confirmed! Thank you for buying from us, %s!\n", &b.name);
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
    free(foodMain);
    free(b.name);
    free(b.password);
    for(int i=0;i<nrDrinks;i++)
        free(drinks[i]);

    free(drinkPrices);
    free(drinks);

    return 0;
}
