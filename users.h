//
// Created by TheRa on 11/7/2019.
//

#ifndef HM_USERS_H
#define HM_USERS_H

#include <stdio.h>

typedef struct _buyer {
    char * name;
    char * password;
} buyer;


void userInput(buyer *b,FILE *foodOrderFile);
buyer createBuyer();

#endif //HM_USERS_H
