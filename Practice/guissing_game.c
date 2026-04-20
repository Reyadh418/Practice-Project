//Guessing game. completely text based by C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Variable declaration area
    int comchoice, userchoice;
    printf("\nThis is a guessing game.\n You just have to guess the number computer choose. Between 1 to 10.\n");

    srand(time(0));

    comchoice = (rand() % 10) + 1;

}

