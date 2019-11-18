#include <stdio.h>
#include "getchoice.h"
#include "users.h"
#include "display.h"

#define MAX_FOOD_NAME 30
#define MAX_MODEL_NAME 20
#define MAX_DRINK_NAME 30
#define MAX_CUTLERY_NAME 30

void getAdditionalInfo(char add[], int *state);

int main() {
    printf(""Hello");"
    }
    return 0;


void getAdditionalInfo(char add[], int *state) {
    printf("Any additional info? \n");
    gets(add);
    (*state)++;
}