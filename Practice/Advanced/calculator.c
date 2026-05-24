#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Cross-Platform use of sleep function
#ifdef _WIN32
#include <windows.h>

#define sleep(x) Sleep(x * 1000) 
#else
#include <unistd.h>
#endif

void press_enter_to_continue();

int main()
{
    int operation, result, back_to_menu;
    printf("\n\nIt's a text based calculator, There is no graphics.\n");

    press_enter_to_continue();

    main_menu:
    {
        printf("\n\n\nMain Menu\n\n\n");

        press_enter_to_continue();

        do
        {
            printf("What operation you want to do?\n");

            //Arithmatic Options
            printf("\nArithmatic Operations:\n");
            printf("\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n\t5. Root\n\t6. Square\n\t7. Remainder\n");

            sleep(1);

            //Trigonometry options
            printf("\nTrigonometric Operations:\n");
            printf("\t8. Sine(sin)\n\t9. Cosine(cos)\n\t10. Tangent(tan)\n\t11. Cotangent(cot)\n\t12. Secent(sec)\n\t13. Cosecent(cosec)\n");
            
            sleep(1);

            //Inverse Trigonometric options
            printf("\nInverse Trigonometric Operations:\n");
            printf("\t14. Inverse Sine(arcsin)\n\t15. Inverse Cosine(arccos)\n\t16. Inverse Tangent(arctan)\n\t17. Inverse Cotangent(arccot)\n\t18. Inverse Secent(arcsec)\n\t19. Inverse Cosecent(arccosec)\n");
            
            sleep(1);

            //Logarithmic options
            printf("\nLogarithmic Operations:\n");
            printf("\t20. Log(10 base)\n\t21. Ln(e base Log)\n");

            printf("Choice:\t");
            scanf("%d", &operation);
        } while (operation < 1 || operation > 21);
        

        if (operation == 1) //Addition
        {
            addition:
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

                sleep(1);

                printf("\nEnter your values\n");

                for(int i = 0; i < choice; i++)
                {
                    printf("\nValues:\t");
                    scanf("%d", &values[i]);

                    result += values[i];
                }

                printf("\nThe result is: %d", result);

                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto addition;
                }
            }//goto loop for addition end
        }// Addition End

        else if (operation == 2) //Subtraction
        {
            subtraction:
            {
                printf("\nYou can only subtract two numbers at a time.\n");
                int a, b;
                
                press_enter_to_continue();
                
                printf("\nEnter your first value:\t");
                scanf("%d", &a);

                sleep(1);

                printf("\nEnter your second value:\t");
                scanf("%d", &b);
                
                result = a - b;
                
                printf("\nYour result is: %d", result);

                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto subtraction;
                }
            }//goto loop for subtraction end
        }//Subtraction End

        else if (operation == 3) //Multiplication
        {
            multiplication:
            {
                int choice;
                result = 1;
                do
                {
                    printf("\nHow many numbers you want to multiply?(01 - 05)\n");
                    printf("Choose:\t");
                    scanf("%d", &choice);

                } while (choice < 1 || choice > 5);
                
                sleep(1);

                int values[choice];

                printf("\nEnter your values\n");

                for(int i = 0; i < choice; i++)
                {
                    printf("\nValues:\t");
                    scanf("%d", &values[i]);

                    result *= values[i];
                }

                printf("\nThe result is: %d", result);

                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto multiplication;
                }
            }//goto loop for multiplication end
        }// Multiplication End

        else if (operation == 4) //Division
        {
            division:
            {
                printf("\nYou can only divide two numbers at a time.\n");
                float a, b, div_result;

                press_enter_to_continue();

                printf("\nEnter your first value:\t");
                scanf("%f   ", &a);

                printf("\nEnter your second value:\t");
                scanf("%f", &b);
                
                if (b == 0)
                {
                    printf("\nError: Division by zero is undefined.\n");
                    press_enter_to_continue();
                }
                else
                {
                    div_result = a / b;
                    printf("\nYour result is: %.3f", div_result);
                }
                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto division;
                }
            }//goto loop for division end
        }//Division End

        else if(operation == 5) //root
        {
            root:
            {
                double num, root_result;
                printf("\nEnter the number to find the square root:\t");
                scanf("%lf", &num);

                if (num < 0)
                {
                    printf("\nError: Cannot compute square root of a negative number.\n");

                    press_enter_to_continue();
                }
                else
                {
                    root_result = sqrt(num);
                    printf("\nThe square root of %.2lf is: %.2lf", num, root_result);
                }

                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto root;
                }
            }//goto loop for root end
        }// root End

        else if(operation == 6) //square
        {
            square:
            {
                double num, square_result;
                printf("\nEnter the number to find the square:\t");
                scanf("%lf", &num);

                sleep(1);

                square_result = pow(num, 2);
                printf("\nThe square of %.2lf is: %.2lf", num, square_result);

                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto square;
                }
            }//goto loop for square end
        }// square End

        else if(operation == 7) //Remainder
        {
            remainder:
            {
                int a, b, remainder_result;
                printf("\nEnter the dividend:\t");
                scanf("%d", &a);

                printf("\nEnter the divisor:\t");
                scanf("%d", &b);

                if (b == 0)
                {
                    printf("\nError: Division by zero is undefined.\n");

                    press_enter_to_continue();
                }
                else
                {
                    remainder_result = a % b;
                    printf("\nThe remainder of %d divided by %d is: %d", a, b, remainder_result);
                }
                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto remainder;
                }
            }//goto loop for remainder end
        }// Remainder End

        else if (operation >= 8 && operation <= 13) //Trigonometric Functions
        {
            trigonometry:
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
                
                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto trigonometry;
                }
            }//goto loop for trigonometry end
        }//Entire trigonometry end

        else if (operation >= 14 && operation <= 19) //Inverse Trigonometric Functions
        {
            inverse_trigonometry:
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

                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto inverse_trigonometry;
                }
            }//goto loop for inverse trigonometry end
        }//Entire Inverse trigonometry end

        else if (operation >= 20 && operation <= 21) //Logarithmic Functions
        {
            logarithmic:
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

                press_enter_to_continue();

                printf("\n\nYou want to go to the main menu?(1)\n");
                printf("\n\nOr you want to do another calculation?(2)\n");
                printf("\n\nOr exit the program?(3)\n");
                printf("Choose:\t");
                scanf("%d", &back_to_menu);
                if (back_to_menu == 1)
                {
                    goto main_menu;
                }
                else if (back_to_menu == 2)
                {
                    goto logarithmic;
                }
            }//goto loop for logarithmic end
        }//Entire Logarithmic end
    }// main_menu loop
} //main

void press_enter_to_continue()
{
    printf("Press Enter to continue...");
    fflush(stdout); // Flush the output buffer to ensure the prompt is displayed immediately
    // Wait for the Enter key (newline character)
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}//press_enter_to_continue end