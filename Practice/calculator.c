#include<stdio.h>
#include<math.h>

int main ()
{
    int var1, var2, op;
    int add, sub, mul, div;

    printf("\nEnter the first number:\t");
    scanf("%d", &var1);
    printf("\nEnter the second number:\t");
    scanf("%d", &var2);

    retry1:
    {
        printf("\nWhat do you want to do?\n");
        printf("\n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
        scanf("%d", &op);
    }

    if (1 > op || op > 4)
    {
        goto retry1;
    }


    if (op == 1)
    {
        add = var1 + var2;
        printf("\nYour answer is:\t%d", add);
    }
    else if (op == 2)
    {
        if (var1 > var2)
        {
            sub = var1 - var2;
            printf("\nYour answer is:\t%d", sub);
        }
        else if (var1 < var2)
        {
            sub = var2 - var1;
            printf("\nYour answer is:\t%d", sub);
        }
        else
        {
            sub = var1 - var2;
            printf("\nYour answer is:\t%d", sub);
        }
    }
    else if (op == 3)
    {
        mul = var1 * var2;
        printf("\nYour answer is:\t%d", mul);
    }
    else if (op == 4)
    {
        div = var1 / var2;
        printf("\nYour answer is:\t%d", div);
        printf("\nInteger Numbers only. Fload or fractions not allowed yet.");
    }
    
    return 0;
}