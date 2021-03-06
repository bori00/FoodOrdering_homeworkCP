//
// Created by Bori on 11/3/2019.
//

#include <stdbool.h>
#include <stdio.h>
#include <conio.h>
#include "choice.h"

bool correctAnswer(char choice, char min, char max)
{
    if(choice>=min && choice<=max) return true;
    return false;
}

int getChoiceIndex(int nrOfChoices)
{
    char choice;
    char c;
    do {
        printf("Please choose any of the possible options!\n");
        choice = getch();
        while ((c = getchar()) != '\n' && c != EOF);
    }while(!correctAnswer(choice, 'a', (char)('a'+nrOfChoices-1)));
    return choice-'a';
}

void goToNextState(int* step, int nrForwardOptions, int optionChosen, int goBackNr) //optionChosen is indexed from 0
{
    if(optionChosen+1<=nrForwardOptions) (*step)++;
    else (*step)-=goBackNr;
}

