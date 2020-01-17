//
// Created by TheRa on 12/16/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getchoice.h"
#include "spec.h"


#define MAX_SPECIFFIC_NAME 10


void readSpecAndPrice(char *point, char ***food, int i,int *k,double **prices){

        while (point) {
            point = strtok(NULL, "-");
            food[i][*k] = (char*)malloc(MAX_MODEL_SPEC_NAME * sizeof(char));
            strcpy(food[i][*k], point);
            food[i][*k][strlen(point) - 1]='\0';
            point = strtok(NULL, ")");
            sscanf(point, "%lf",&prices[i][*k]);
            point = strtok(NULL, "(");
            (*k)++;
        }
};


