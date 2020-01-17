//
// Created by TheRa on 12/20/2019.
//
#include <stdlib.h>
#include "food.h"
#define MAX_FOOD_NAME 10


foodType createFood() {
    foodType b;
    b.name = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
    b.speccificFoods = NULL;
    return b;
}




