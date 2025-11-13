#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int operation, result, back_to_menu;
    printf("\n\nIt's a text based calculator, There is no graphics.\n");

    main_menu:
    {
        printf("\n\n\nMain Menu\n\n\n");

        do
        {
            printf("What operation you want to do?\n");

            //Arithmatic Options
            printf("\nArithmatic Operations:\n");
            printf("\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n\t5. Root\n\t6. Square\n\t7. Remainder\n");
            //Trigonometry options
            printf("\nTrigonometric Operations:\n");
            printf("\t8. Sine(sin)\n\t9. Cosine(cos)\n\t10. Tangent(tan)\n\t11. Cotangent(cot)\n\t12. Secent(sec)\n\t13. Cosecent(cosec)\n");
            //Inverse Trigonometric options
            printf("\nInverse Trigonometric Operations:\n");
            printf("\t14. Inverse Sine(sin⁻¹)\n\t15. Inverse Cosine(cos⁻¹)\n\t16. Inverse Tangent(tan⁻¹)\n\t17. Inverse Cotangent(cot⁻¹)\n\t18. Inverse Secent(sec⁻¹)\n\t19. Inverse Cosecent(cosec⁻¹)\n");
            //Logarithmic options
            printf("\nLogarithmic Operations:\n");
            printf("\t20. Log(10 base)\n\t21. Ln(e base Log)\n");

            printf("Choice:\t");
            scanf("%d", &operation);
        } while (operation < 1 || operation > 12);
        

        if (operation == 1) //Addition
        {
            int choice;
            result = 0;
            do
            {
                printf("\nHow many numbers you want to add?(01 - 10)\n");
                printf("Choose:\t");
                scanf("%d", &choice);

            } while (choice < 1 || choice > 10);
            
            int values[choice];

            printf("\nEnter your values\n");

            for(int i = 0; i < choice; i++)
            {
                printf("\nValues:\t");
                scanf("%d", &values[i]);

                result += values[i];
            }

            printf("\nThe result is: %d", result);

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }// Addition End

        else if (operation == 2) //Subtraction
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

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }//Subtraction End

        else if (operation == 3) //Multiplication
        {
            int choice;
            result = 1;
            do
            {
                printf("\nHow many numbers you want to multiply?(01 - 05)\n");
                printf("Choose:\t");
                scanf("%d", &choice);

            } while (choice < 1 || choice > 5);
            
            int values[choice];

            printf("\nEnter your values\n");

            for(int i = 0; i < choice; i++)
            {
                printf("\nValues:\t");
                scanf("%d", &values[i]);

                result *= values[i];
            }

            printf("\nThe result is: %d", result);

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }// Multiplication End
    }// main_menu loop
} //main