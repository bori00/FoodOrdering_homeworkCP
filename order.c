//
// Created by Bori on 11/3/2019.
//

#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include "order.h"
#include "choice.h"


void displayFoodTypeOptions(struct order myOrder, menu myMenu)
{
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i <=myMenu.foodTypeNr-1; i++) {
        putchar('a' + i);
        printf(") %s\n", myMenu.foodTypes[i].name);
    }
    printf("%c) go back\n", (char)'a'+myMenu.foodTypeNr);
}

void chooseFoodType(struct order *myOrder, menu myMenu, int* step)
{
    displayFoodTypeOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.foodTypeNr+1);
    goToNextState(step, myMenu.foodTypeNr, choiceIndex, 1);
    if(choiceIndex<myMenu.foodTypeNr)
    {
        myOrder->foodType=choiceIndex;
    }
}

void chooseSpecFood(struct order *myOrder,  menu myMenu, int* step)
{
    displaySpecFoodOptions(myMenu.foodTypes[myOrder->foodType]);
    int choiceIndex = getChoiceIndex(myMenu.foodTypes[myOrder->foodType].specFoodNr+1);
    goToNextState(step, myMenu.foodTypes[myOrder->foodType].specFoodNr, choiceIndex, 1);
    if(choiceIndex<myMenu.foodTypes[myOrder->foodType].specFoodNr)
    {
        myOrder->specFood=choiceIndex;
    }
}

void displayDrinkOptions(struct order myOrder,  menu myMenu)
{
    printf("Please choose a drink to go with your %s\n",  myMenu.foodTypes[myOrder.foodType].name);
    for (int i = 0; i <=myMenu.drinkNr-1; i++) {
        putchar('a' + i);
        printf(") %s %.2lf\n", myMenu.drinks[i].name, myMenu.drinks[i].price);
    }
    printf("%c) nothing 0.00\n", 'a'+myMenu.drinkNr);
    printf("%c) go back\n", (char)'a'+myMenu.drinkNr+1);
}

void chooseDrink(struct order *myOrder,  menu myMenu, int* step)
{
    displayDrinkOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.drinkNr+2);
    goToNextState(step, myMenu.drinkNr+1, choiceIndex, 1);
    if(choiceIndex<myMenu.drinkNr) //case has chosen a foodType
    {
        myOrder->drink=choiceIndex;
    }
    else if (choiceIndex==myMenu.drinkNr)
    {
        myOrder->drink=-1;
    }
}

void displayCutleryOptions()
{
    printf("Do you want cutlery?\n");
    printf("a) yes\n");
    printf("b) no\n");
    printf("c) go back\n");
}

void decideCutlery(struct order *myOrder,  menu myMenu, int* step)
{
    displayCutleryOptions();
    int choiceIndex = getChoiceIndex(3);
    goToNextState(step, 2, choiceIndex, 1);
    switch(choiceIndex)
    {
        case 0: myOrder->cutlery=true;
                break;
        case 1: myOrder->cutlery=false;
                break;
    }
}

void getAdditionalInfo(struct order *myOrder, int* step)
{
    printf("Any additional info?\n");
    gets(myOrder->additionalInfo);
    if(strcmp(myOrder->additionalInfo, "")!=0) myOrder->existsAdditionalInfo=true;
    else myOrder->existsAdditionalInfo=false;
    (*step)++;
}
