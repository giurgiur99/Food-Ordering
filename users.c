//
// Created by TheRa on 12/8/2019.
//
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "users.h"
#define MIN_PASSWORD_LENGTH 7

void userInput(char *user, char *pass,FILE *foodOrderFile){
    int signInOrUp=0,state=0;
    char choice;
    char    ERROR_PASSWORD_LONG[] = "The password must be at least 7 chars long";
    char    ERROR_PASSWORD_NOT_USERNAME[] = "The password must not contain the username";
    char    ERROR_PASSWORD_SPECIAL_CHAR[] = "The password must contain one of the following characters: {'.','_','!'}";
    char    ERROR_PASSWORD_DIGITS[] = "The password must contain digits";
    char    SIGN_IN_UP[] = "Do you want to sign in or sign up?";
    char    SIGN_IN[] = "Sign in";
    char    SIGN_UP[] = "Sign up";
    char    SIGNING_IN[] = "Signing in!";
    char    SIGNING_UP[] = "Signing up!";
    char    USER_NOT_FOUND[] = "Username doesn't exist";
    char    DUPLICATE_USER[] = "Please choose another username!";
    char    INCORRECT_PASSWORD[] = "Incorrect password";

    while(!signInOrUp){
        switch(state){
            case 0: {
                printf("%s\n""a)%s\n""b)%s\n",SIGN_IN_UP,SIGN_IN,SIGN_UP);
                choice=getchar();
                getchar();
                state++;
                break;
            }
            case 1: {
                if(choice == 'a')signinIn(user, pass, &signInOrUp, &state, SIGNING_IN, INCORRECT_PASSWORD, USER_NOT_FOUND);
                else state++;
                break;
            }
            case 2: {

                signinUp(user, pass, &signInOrUp, SIGNING_UP, DUPLICATE_USER, ERROR_PASSWORD_LONG,ERROR_PASSWORD_NOT_USERNAME, ERROR_PASSWORD_SPECIAL_CHAR, ERROR_PASSWORD_DIGITS);
                break;
            }
        }
    }
}

int usernameOk(char *username){
    if(strcmp(username,"admin")==0) return 1;
    else return 0;
}
int passwordOk(char *password){
    if(strcmp(password,"admin")==0) return 1;
    else return 0;
}
int usernameSignUpOk(char *username){
    if(strcmp(username,"admin")==0) return 0;
    else return 1;
}
int passwordSignUpOk(int (*conditionOk)(char[]), char *password, char *err){
    if(conditionOk(password)) return 1;
    else printf("%s\n", err);
    return 0;
}
int length(char password[]){
    if(strlen(password)<MIN_PASSWORD_LENGTH)return 0;
    return 1;
}
int pass_diff_username(char password[],char username[],char err[]){
    if(strstr(password,username)!=NULL){
        printf("%s\n", err);
        return 0;
    }
    return 1;
}
int specialChar(char *password){
    if(strchr(password,'!')!=NULL)return 1;
    if(strchr(password,'.')!=NULL)return 1;
    if(strchr(password,'_')!=NULL)return 1;
    return 0;
}
int passAndDigit(char *password){
    int ok=0;
    for(int i=0;i<strlen(password);i++){
        if(isdigit(password[i]))return 1;
    }
    return 0;
}
void signinIn(char user[], char password[], int * sign_in, int *state, char message[], char err[], char err_user[]){
    printf("---%s\n""---Username\n",message);
    gets(user);
    printf("---Password\n");
    gets(password);
    if(usernameOk(user) && passwordOk(password))(*sign_in)=1;
    if(usernameOk(user) && !passwordOk(password))printf("%s\n", err);
    if(!usernameOk(user)){
        printf("%s\n",err_user);
        (*state)--;
    }
}
void signinUp(char username[], char password[], int * sign_up, char message[], char err[], char err_length[],char err_pass_not_username[], char err_special_char[], char err_digits[]){

    printf("%s\n""---Username\n",message);
    gets(username);
    if(!usernameSignUpOk(username))printf("%s\n", err);
    else {
        printf("---Password\n");
        gets(password);
        if(passwordSignUpOk(&length, password, err_length) && pass_diff_username(password,username,err_pass_not_username) && passwordSignUpOk(
                &specialChar, password, err_special_char) && passwordSignUpOk(&passAndDigit, password, err_digits) )
            (*sign_up)=1;
    }
}



