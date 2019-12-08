#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H
#define MAX_CUTLERY_NAME 20
void foodOrderDsiplay(int nrOfFoodTypes, char ** foodTypes);
void foodModelDisplay(int nrSpecType, char * foodType, char ** specTypes, double * prices);
void displayDrinks(char * foodType,int nrDrinks,char ** drinks,
                   double * pricesDrinks);
void cutleryDisplay(int cutlery,char cut[][MAX_CUTLERY_NAME]);
void getAdditionalInfo(char *addinfo, int *state);
void displayOrder(char * specType,double price,char * drink,double priceDrink,
                  char cutlery[],char addinfo[],char username[]);

#endif //FOOD_ORDERING_DISPLAY_H
