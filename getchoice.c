//
// Created by TheRa on 11/7/2019.
//

#include <stdio.h>

int getChoice(int noOfChoices, int *t) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    if (choice == 'a' + noOfChoices) {
        (*t)--;
    }
    else {
        choiceIndex = choice - 'a';
        (*t)++;
    }
    return choiceIndex;
}

int getFinal(int *state, char username[]) {
    int ok;
    printf("a) Confirm order \n");
    printf("b) Go back \n");
    char choice = getchar();
    if (choice == 'a') {
        ok = 1;
        printf("Order confirmed! Thank you for buying from us, %s! \n", username);
    }
    else {
        (*state)-=2;
    }
    getchar();
    return ok;
}