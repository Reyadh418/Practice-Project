#include <stdio.h>
#include <math.h>

//Cross-Platform use of sleep function
#ifdef _WIN32
#include <windows.h>

#define sleep(x) Sleep(x * 1000) 
#else
#include <unistd.h>
#endif

int main()
{
    printf("Do you know what an Armstrong number is?\n");

    sleep(2);

    printf("An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.\n");
    sleep(3);
    // Variable declarations
    int num, originalNum;

    anothertry:
    {
        int digit[10] = {0};
        int sum = 0, n = 0;

        printf("Armstrong Number's are only defined for positive integers including zero.\n");
    
        //User input for the number
        entry:
        {
            printf("Enter an integer:\t");
            scanf("%d", &num);

            if (num < 0)
            {
                printf("Error: You entered a negative number.\n");
                printf("1. Will you like to convert in into positive number?\n");
                printf("2. Or you want to enter another number?\n");
                printf("Choose(1/2):\t");
                int decision;
                scanf("%d", &decision);

                if (decision == 1)
                {
                    num = -num;
                }
                else if (decision == 2)
                {
                    goto entry;
                }
            }    
        }
        originalNum = num;
        //counting digits(n)
        if (num == 0)
        {
            n = 1;
        }

        while (num != 0)
        {
            num /= 10;
            ++n;
        }

        // Extracting digits and storing in an array
        num = originalNum; // Restore the original number

        for (int i = 0; i < n; i++)
        {
            digit[i] = num % 10;
            num /= 10;
        }

        // Adding to the sum
        for (int i = 0; i < n; i++)
        {
            sum += pow(digit[i], n);
        }
        // Checking if the number is an Armstrong number
        if (sum == (originalNum < 0 ? -originalNum : originalNum))
        {
            printf("%d is an Armstrong number.\n", originalNum);
        }
        else
        {
            printf("%d is not an Armstrong number.\n", originalNum);
        }
    }

    // Asking user if they want to try again
    int choice;
    printf("Do you want to check another number? (1 for Yes / 2 for No): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        goto anothertry;
    }
    else
    {
        printf("Thank you for using the Armstrong number checker!\n");
    }

    return 0;
} // Main function end