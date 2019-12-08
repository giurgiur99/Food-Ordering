#include <stdio.h>

int getChoice(int nrOfChoices, int *state){
    int choiceIndex;
    char choice = getchar();
    getchar();
    if(choice == 'a'+nrOfChoices){
        choiceIndex = choice - 'a';
        (*state)--;
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}
void confirmOrder(int confirmChoice,int *order,int *state){
    if(confirmChoice == 0){
        (*order) = 1;
    } else {
        (*state)--;
    }
}
