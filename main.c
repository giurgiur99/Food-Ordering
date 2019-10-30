#include <stdio.h>
#include <string.h>

int main() {

    struct b{
        char tip[20];
        float pret;
    };

    struct a{
        int nr;
        char name[20];
        struct b model[20];
    }food[20];

    struct beverage{
        float pret;
        char name[25];
    }drink[20];
    int nrDrinks=4;
    float sum=0;
    int selectedDrinks[20],nrSelectedDrinks;
    char s[100],na[20],pass[20];

    strcpy(drink[0].name,"Coca-Cola");drink[0].pret=5;
    strcpy(drink[1].name,"Fanta");drink[1].pret=5;
    strcpy(drink[2].name,"Lipton");drink[2].pret=5;
    strcpy(drink[3].name,"Water");drink[3].pret=4;

    printf("--- Please enter your username\n");
    gets(na);
    printf("--- Please enter your password\n");
    gets(pass);


    food[0].nr=3;
    food[1].nr=2;
    food[2].nr=4;
    strcpy(food[0].name,"Pizza");
    strcpy(food[1].name,"Pasta");
    strcpy(food[2].name,"Salata");

    strcpy(food[0].model[0].tip,"Carbonara");food[0].model[0].pret=21;
    strcpy(food[0].model[1].tip,"Diavola");food[0].model[1].pret=23;
    strcpy(food[0].model[2].tip,"Margherita");food[0].model[2].pret=19;

    strcpy(food[1].model[0].tip,"Chicken alfredo");food[1].model[0].pret=21;
    strcpy(food[1].model[1].tip,"Mac&cheese");food[1].model[1].pret=21;

    strcpy(food[2].model[0].tip,"Tuna Salad");food[2].model[0].pret=23;
    strcpy(food[2].model[1].tip,"Chicken Salad");food[2].model[1].pret=22;
    strcpy(food[2].model[2].tip,"Greek Salad");food[2].model[2].pret=19;
    strcpy(food[2].model[3].tip,"Cobb");food[2].model[3].pret=21;

    /*printf("\n \n");
    for(int i=0;i<3;i++,printf("-- %s \n",food[i].name))
        for(int j=0;j<4;j++)
            printf("%s %d \n",food[i].model[j].tip,food[i].model[j].pret);*/

    int t=0,choice=0,foodChoice=0,modelChoice=0,end=1,cutlery=0;
    while(end!=0)
    {
        switch(t) {
            case 0: {
                printf("Please choose what you would like to order. \n");
                for (int i = 0; i < 3; i++) {
                    putchar('a' + i);
                    printf(")%s\n", food[i].name);
                }
                printf("%c)Go back\n", 'a' + 3);
                choice = getchar();
                getchar();
                if (choice == 'a' + 3) {
                    printf("There is no menu to go back to. \n");
                    break;
                }
                foodChoice = choice - 'a';
                t++;
                break;
            }

            case 1: {
                printf("What kind of %s would you like to have. \n", food[foodChoice].name);
                for (int i = 0; i < food[foodChoice].nr; i++) {
                    putchar('a' + i);
                    printf(") %s %s (%2.f) \n", food[foodChoice].name, food[foodChoice].model[i].tip,
                           food[foodChoice].model[i].pret);
                }
                printf("%c) Go back\n", 'a' + food[foodChoice].nr);
                choice = getchar();
                getchar();
                if (choice == 'a' + food[foodChoice].nr) {
                    t--;
                    break;
                }
                modelChoice = choice - 'a';
                t++;
                break;

            }

            case 2: {
                printf("Would you like to have something to drink with your %s. \n", food[foodChoice].name);
                for (int i = 0; i < nrDrinks; i++) {
                    putchar('a' + i);
                    printf(") %s \n", drink[i].name);
                }
                printf("%c) Go back\n", 'a' + nrDrinks);
                choice = getchar();
                if (choice == 'a' + nrDrinks) {
                    t--;
                    getchar();
                    break;
                }
                nrSelectedDrinks = 0;
                while (choice != '.') {
                    selectedDrinks[choice - 'a'] = 1;
                    nrSelectedDrinks++;
                    char comma = getchar();
                    if (comma == '\n') {
                        break;
                    }
                    choice = getchar();
                }
                t++;
                break;
            }
            case 3: {
                printf("Do you want cutlery ?\n");
                printf("a) Yes\n");
                printf("b) No, thanks\n");
                printf("c) Go back\n");

                choice = getchar();
                if (choice == 'c') {
                    getchar();
                    t--;
                    break;
                }
                if (choice == 'a') cutlery = 1;
                if (choice == 'b') cutlery = 0;
                t++;
                break;
            }

            case 4: {
                printf("Any additional info ?\n");
                scanf("%s", s);
                t++;
                break;
            }
            case 5: {
                sum = 0;
                printf("\n------------------\n\n");
                printf("Name: %s \n", na);
                printf("Food items: \n");
                printf("---%s %s %2.f \n", food[foodChoice].name, food[foodChoice].model[modelChoice].tip,
                       food[foodChoice].model[modelChoice].pret);

                for (int i = 0; i < nrDrinks; i++)
                    if (selectedDrinks[i]) {
                        sum = sum + drink[i].pret;
                        printf("---%s %2.f \n", drink[i].name, drink[i].pret);
                    }
                printf("Cutlery : ");
                if (cutlery) printf("Yes \n");
                else printf("No \n");
                sum += food[foodChoice].model[modelChoice].pret;
                printf("Additional info : %s \n", s);
                printf("Payment amount : %2.f", sum);
                printf("\n------------------\n\n");
                t++;
                break;

            }
            case 6: {
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if (choice == 'a')
                    t++;
                else {
                    t--;
                    break;
                }
                break;
            }

            case 7:
            {
                printf("Order confirmed! Thank you for buying from us, Razvan G. !");
                end=0;
                t++;
                break;
                //endd
            }


        }
    }






    return 0;
}