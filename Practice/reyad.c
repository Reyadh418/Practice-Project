//Cricket game. Fully text based.

#include <stdio.h>
#include <math.h>

//variable declaration area
int overs, wickets, difficulty, userrunchoice, comrunchoice, totaluserrun, totaluserwicket, totalcomrun, totalcomwicket, balls, tosschoiceuser, tossresults;
int useractionchoice, comactionchoice;

//function declaration area
int batting();


int main()
{
    //main code
    printf("Welcome to the game. \n");

    balls = (overs * 6);

    retry1:
    {
        printf("How many overs do you want to play?(1 - 50)\n");
        scanf("%d", &overs);
    }
    if (overs < 1 || overs > 50)
    {
        printf("Invalid input!! Please try again later...\n");
        goto retry1;
    }

    retry2:
    {
        printf("How many wickets match you wanna play?(1 - 10)\n");
        scanf("%d", &wickets);
    }
    if (wickets < 1 || wickets > 10)
    {
        printf("Invalid input!! Please try again later...\n");
        goto retry2;
    }

    retry3:
    {
        printf("Choose difficulty:\n\t 1. Easy\n\t 2. Medium\n\t 3. Hard\n");
        scanf("%d", &difficulty);
    }
    if (difficulty < 1 || difficulty > 3)
    {
        printf("Invalid input!! Please try again later...\n");
        goto retry3;
    }

    srand(time(0));

    printf("Toss time!!\n");
    retry7:
    {
        printf("Choose your toss side!!\n\t 1. Heads\n\t 2. Tails\n");
        scanf("%d", &tosschoiceuser);
    }
    if (tosschoiceuser < 1 || tosschoiceuser > 2)
    {
        printf("Invalid input!! Please try again later...\n");
        goto retry7;
    }

    tossresults = (rand() % 2) + 1;

    if (tossresults == tosschoiceuser)
    {
        printf("Congratulations!! You won the toss.\n");
        retry8:
        {
            printf("Will you,\n\t 1. Bat first or\n\t 2. Ball first\n");
            scanf("%d", &useractionchoice);
        }
        if (useractionchoice < 1 || useractionchoice > 2);
        {
            printf("Invalid input!! Please try again later...\n");
            goto retry8;
        }

        //Toss choice

        if (useractionchoice == 1)
        {
            printf("You won the toss and decided to bat first\n");
            batting();
            userscore();
            balling();
            comscore();
        }
        else if (useractionchoice == 2)
        {
            printf("You won the toss and decided to ball fisrt\n");
            balling();
            comscore();
            batting();
            userscore();
        }

    }
    else if (tossresults != tosschoiceuser)
    {
        comactionchoice = (rand() % 2) + 1;

        if (comactionchoice == 1)
        {
            printf("Computer won the toss and decided to bat first\n");
            balling();
            comscore();
            batting();
            userscore();
        }
        else if (comactionchoice == 2)
        {
            printf("Computer won the toss and decided to ball first\n");
            batting();
            userscore();
            balling();
            comscore();
        }
    }

    results();
    
}

int batting()
{
    if (difficulty == 1)
    {        
        retry4:
        {
            printf("Choose a number betweeen 0 to 6?\n");
            scanf("%d", &userrunchoice);
        }
        if (userrunchoice < 0 || userrunchoice > 6)
        {
            printf("Invalid input!! Please try again later...\n");
            goto retry4;
        }

        comrunchoice = (rand() % 6) + 1;

        if (userrunchoice == comrunchoice)
        {
            totaluserwicket += 1;
        }
        else
        {
            totaluserrun += userrunchoice;
        }
    }

    else if (difficulty == 2)
    {        
        retry5:
        {
            printf("Choose a number betweeen 0 to 6?\n");
            scanf("%d", &userrunchoice);
        }
        if (userrunchoice < 0 || userrunchoice > 6)
        {
            printf("Invalid input!! Please try again later...\n");
            goto retry5;
        }

        comrunchoice = (rand() % 6) + 1;

        if (userrunchoice == comrunchoice || (userrunchoice - 1) == comrunchoice || (userrunchoice + 1) == comrunchoice)
        {
            totaluserwicket += 1;
        }
        else
        {
            totaluserrun += userrunchoice;
        }
    }

    else if (difficulty == 3)
    {        
        retry6:
        {
            printf("Choose a number betweeen 0 to 6?\n");
            scanf("%d", &userrunchoice);
        }
        if (userrunchoice < 0 || userrunchoice > 6)
        {
            printf("Invalid input!! Please try again later...\n");
            goto retry6;
        }

        comrunchoice = (rand() % 6) + 1;

        if (userrunchoice == comrunchoice)
        {
            totaluserwicket += 1;
        }
        else if ((userrunchoice - 1) == comrunchoice || (userrunchoice + 1) == comrunchoice)
        {
            totaluserwicket += 1;
        }
        else if ((userrunchoice - 2) == comrunchoice || (userrunchoice + 2) == comrunchoice)
        {
            totaluserwicket += 1;
        }
        else
        {
            totaluserrun += userrunchoice;
        }
    }
}

int balling()
{
    printf("Defend computers run score\n");

    retry9:
    { 
        printf("Choose between 1 to 6\n");
        scanf("%d", &userrunchoice);
    }
    if (userrunchoice < 1 || userrunchoice > 6)
    {
        printf("Invalid input!! Please try again later...\n");
        goto retry9;
    }

    comrunchoice = (rand() % 6) + 1;

    if (userrunchoice == comrunchoice)
    {
        totalcomwicket += 1;
    }
    else
    {
        totalcomrun += comrunchoice;
    }

}