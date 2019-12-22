#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H

#include "food.h"
#define MAX_CUTLERY_NAME 20

void foodOrderDsiplay(foodType *b, int nrOfFoodTypes);
void foodModelDisplay(int nrSpecType, char * foodType, char ** specTypes, double * prices);
void displayDrinks(char * foodType,int nrDrinks,char ** drinks,
                   double * pricesDrinks);
void cutleryDisplay(int cutlery,char cut[][MAX_CUTLERY_NAME]);
void getAdditionalInfo(char *addinfo, int *state);
void displayOrder(char * specType,double price,char * drink,double priceDrink,
                  char cutlery[],char addinfo[],char username[]);
void saveToFile(int nrOfFoodTypes, char **foodTypes, int *nrSpecType, char ***specTypes,double **prices, int nrDrinks, char **drinks, double *pricesDrinks, FILE *foodOrderFileOut);

#endif //FOOD_ORDERING_DISPLAY_H
