#ifndef FOOD_ORDERING_GETCHOICE_H
#define FOOD_ORDERING_GETCHOICE_H

#define MAX_LINE 50

int getChoice(int nrOfChoices, int *state, FILE *foodOrderFile);
void confirmOrder(int confirmChoice,int *order,int *state);

#endif //FOOD_ORDERING_GETCHOICE_H
