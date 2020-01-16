#include <stdio.h>
#include "display.h"
#include "food.h"
#include <string.h>
#define MAX_CUTLERY_NAME 20

void foodOrderDsiplay(foodType *b, int nrOfFoodTypes){
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0; i<nrOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s\n", b[i].name);
    }
    printf("%c) Go back.\n",'a'+nrOfFoodTypes);
}
void foodModelDisplay(int nrSpecType, char * foodType, char ** specTypes, double * prices){
    printf("Please choose the type of %s:\n",foodType);
    for(int i=0; i<nrSpecType; i++){
        putchar('a'+i);
        printf(") %s: %.2lf\n",specTypes[i],prices[i]);
    }
    printf("%c) Go back.\n",'a'+nrSpecType);
}

void displayDrinks(char *foodType,int nrDrinks,char ** drinks,
                   double * pricesDrinks){
    printf("Please choose a drink to go with your %s:\n",foodType);
    for(int i=0; i<nrDrinks; i++){
        putchar('a'+i);
        printf(") %s: %.2lf\n",drinks[i],pricesDrinks[i]);
    }
    printf("%c) Go back.\n",'a'+nrDrinks);
}

void cutleryDisplay(int cutlery, char cut[][MAX_CUTLERY_NAME]) {
    printf("Do you want cutlery? \n");
    for (int i = 0; i < cutlery; i++) {
        putchar('a' + i);
        printf(") %s \n", cut[i]);
    }
    printf("%c) Go Back \n", 'a' + cutlery);
}

void getAdditionalInfo(char *addinfo, int *state){
    //add info
    printf("Any additional info?\n");
    gets(addinfo);
    (*state)++;
}
void displayOrder(char * specType,double price,char * drink,double priceDrink,
                  char cutlery[],char addinfo[],char username[]){
    printf("This is your order:\n"
           "-------------------\n");
    printf("Name:%s\n",username);
    printf("Food Items:\n---%s: %.2lf\n---%s: %.2lf\n",specType,
           price,drink,priceDrink);
    printf("Cutlery: %s\n",cutlery);
    if(strcmp(addinfo,"\0") != 0){
        printf("Additional info: %s\n",addinfo);
    }
    printf("Payment amount: %.2lf\n",price+priceDrink);
    printf("-------------------\n"
           "a) Confirm order\n"
           "b) Go back\n");

}

void saveToFile(int nrOfFoodTypes, char **foodTypes,int *nrSpecType, char ***specTypes,double **prices, int nrDrinks, char **drinks, double *pricesDrinks, FILE *foodOrderFileOut)
{
    for (int i=0 ; i<nrOfFoodTypes ;i++) {
        fprintf(foodOrderFileOut, "%s %d:", foodTypes[i], nrSpecType[i] + 1);
        for (int j = 0; j < nrSpecType[i] + 1; j++)
            fprintf(foodOrderFileOut, " ( %s - %.2lf )", specTypes[i][j], prices[i][j]);
        fprintf(foodOrderFileOut, "\n");
    }
        fprintf(foodOrderFileOut,"%d:",nrDrinks);
        fprintf(foodOrderFileOut,"\n");
    for(int i=0 ; i<nrDrinks;i++)
        fprintf(foodOrderFileOut, " ( %s - %.1lf )", drinks[i],pricesDrinks[i]);



}


