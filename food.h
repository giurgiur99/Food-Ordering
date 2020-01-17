//
// Created by TheRa on 12/20/2019.
//

#ifndef HM_FOOD_H
#define HM_FOOD_H
#include "spec.h"
#include "food.h"

typedef struct _foodType {
    char * name;
    int noOfModels;
    specifficFood * speccificFoods;
} foodType;

foodType createFood();



#endif //HM_FOOD_H
