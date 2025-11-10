#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int operation, result;
    printf("It's a text based calculator, There is no graphics.\n");

    main_menu:
    {
        printf("\n\n\nMain Menu\n\n\n");

        do
        {
            printf("What operation you want to do?\n");

            //Arithmatic Options
            printf("\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n");
            //Trigonometry options
            printf("\t5. Sine\n\t6. Cosine\n\t7. Tangent\n\t8. Cotangent\n\t9. Secent\n\t10. Cosecent\n");
            //Logarithmic options
            printf("\t11. Log(10 base)\n\t12. Ln(e base Log)\n");

            printf("Choice:\t");
            scanf("%d", &operation);
        } while (operation < 1 || operation > 12);
        

        if (operation == 1)
        {
            int choice;
            result = 0;
            do
            {
                printf("\nHow many numbers you want to add?(01 - 05)\n");
                printf("Choose:\t");
                scanf("%d", &choice);

            } while (choice < 1 || choice > 5);
            
            int values[choice];

            printf("\nEnter your values\n");

            for(int i = 0; i < choice; i++)
            {
                printf("\nValues:\t");
                scanf("%d", &values[i]);

                result += values[i];
            }

            printf("\nThe result is: %d", result);

            goto main_menu;
        }

        else if (operation == 2)
        {
            printf("\nYou can only subtract two numbers at a time.\n");
            int a, b;
            printf("\nEnter your first value:\t");
            scanf("%d", &a);

            printf("\nEnter your second value:\t");
            scanf("%d", &b);
            
            if (a < b)
            {
                result = b - a;
            }
            else
            {
                result = a - b;
            }
            
            printf("\nYour result is: %d", result);

            goto main_menu;
        }
    }
}