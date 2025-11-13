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
        } while (operation < 1 || operation > 21);
        

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

        else if (operation == 4) //Division
        {
            printf("\nYou can only divide two numbers at a time.\n");
            float a, b, div_result;
            printf("\nEnter your first value:\t");
            scanf("%f", &a);

            printf("\nEnter your second value:\t");
            scanf("%f", &b);
            
            if (b == 0)
            {
                printf("\nError: Division by zero is undefined.\n");
            }
            else
            {
                div_result = a / b;
                printf("\nYour result is: %.3f", div_result);
            }

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }//Division End

        else if(operation == 5) //root
        {
            double num, root_result;
            printf("\nEnter the number to find the square root:\t");
            scanf("%lf", &num);

            if (num < 0)
            {
                printf("\nError: Cannot compute square root of a negative number.\n");
            }
            else
            {
                root_result = sqrt(num);
                printf("\nThe square root of %.2lf is: %.2lf", num, root_result);
            }

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }// root End

        else if(operation == 6) //square
        {
            double num, square_result;
            printf("\nEnter the number to find the square:\t");
            scanf("%lf", &num);

            square_result = pow(num, 2);
            printf("\nThe square of %.2lf is: %.2lf", num, square_result);

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }// square End

        else if(operation == 7) //Remainder
        {
            int a, b, remainder_result;
            printf("\nEnter the dividend:\t");
            scanf("%d", &a);

            printf("\nEnter the divisor:\t");
            scanf("%d", &b);

            if (b == 0)
            {
                printf("\nError: Division by zero is undefined.\n");
            }
            else
            {
                remainder_result = a % b;
                printf("\nThe remainder of %d divided by %d is: %d", a, b, remainder_result);
            }

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }// Remainder End

        else if (operation >= 8 && operation <= 13) //Trigonometric Functions
        {
            double angle, trig_result;
            printf("\nYour angle mode is? (1 for Degrees / 2 for Radians):\t");
            int angle_mode;
            scanf("%d", &angle_mode);
            printf("\nEnter the angle value:\t");
            scanf("%lf", &angle);

            if (angle_mode == 1) //Degrees to Radians conversion
            {
                angle = angle * (M_PI / 180.0);
            }

            switch (operation)
            {
                case 8://Sine value
                    trig_result = sin(angle);
                    printf("\nThe Sine of the angle is: %.6lf", trig_result);
                    break;
                case 9://Cosine value
                    trig_result = cos(angle);
                    printf("\nThe Cosine of the angle is: %.6lf", trig_result);
                    break;
                case 10://Tangent value
                    trig_result = tan(angle);
                    printf("\nThe Tangent of the angle is: %.6lf", trig_result);
                    break;
                case 11://Cotangent value
                    trig_result = 1 / tan(angle);
                    printf("\nThe Cotangent of the angle is: %.6lf", trig_result);
                    break;
                case 12://Secant value
                    trig_result = 1 / cos(angle);
                    printf("\nThe Secant of the angle is: %.6lf", trig_result);
                    break;
                case 13://Cosecant value
                    trig_result = 1 / sin(angle);
                    printf("\nThe Cosecant of the angle is: %.6lf", trig_result);
                    break;
            }
            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }//Entire trigonometry end

        else if (operation >= 14 && operation <= 19) //Inverse Trigonometric Functions
        {
            double value, inv_trig_result;
            printf("\nEnter the value:\t");
            scanf("%lf", &value);

            switch (operation)
            {
                case 14://Inverse Sine value
                    inv_trig_result = asin(value);
                    break;
                case 15://Inverse Cosine value
                    inv_trig_result = acos(value);
                    break;
                case 16://Inverse Tangent value
                    inv_trig_result = atan(value);
                    break;
                case 17://Inverse Cotangent value
                    inv_trig_result = atan(1 / value);
                    break;
                case 18://Inverse Secant value
                    inv_trig_result = acos(1 / value);
                    break;
                case 19://Inverse Cosecant value
                    inv_trig_result = asin(1 / value);
                    break;
            }
            printf("\nThe angle in Radians is: %.6lf", inv_trig_result);
            printf("\nThe angle in Degrees is: %.6lf", inv_trig_result * (180.0 / M_PI));

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }//Entire Inverse trigonometry end

        else if (operation >= 20 && operation <= 21) //Logarithmic Functions
        {
            double value, log_result;
            printf("\nEnter the value:\t");
            scanf("%lf", &value);

            switch (operation)
            {
                case 20://Log base 10
                    log_result = log10(value);
                    printf("\nThe Log base 10 of %.6lf is: %.6lf", value, log_result);
                    break;
                case 21://Natural Log (base e)
                    log_result = log(value);
                    printf("\nThe Natural Log (base e) of %.6lf is: %.6lf", value, log_result);
                    break;
            }

            printf("\n\nDo you want to go back to main menu? (1 for Yes / 2 for No):\t");
            scanf("%d", &back_to_menu);
            if (back_to_menu == 1)
            {
                goto main_menu;
            }
        }//Entire Logarithmic end
    }// main_menu loop
} //main