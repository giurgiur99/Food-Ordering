//
// Created by TheRa on 12/16/2019.
//

#ifndef HM_SPEC_H
#define HM_SPEC_H


#define MAX_MODEL_NAME 50
#define  MAX_MODEL_SPEC_NAME 50
#define MAX_PRICE_LEN 20

typedef struct _specifficFood
{
    char *name;
    double price;
}specifficFood;


void readSpecAndPrice(char *point, char ***food, int i,int *k,double **prices);

#endif //HM_SPEC_H
