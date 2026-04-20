#include <stdio.h>

int main()
{
    int num, d, sum = 0, i = 0;
    printf("Printing sum of digits.\n");
    retry:
    {
        printf("Enter the number:\t");
        scanf("%d", &num);
        if (num == 0)
        {
            printf("Invalid input!!\n");
            goto retry;
        }
    }
    int n = num;
    
    while (n != 0)
    {
        d = n % 10;
        sum += d;
        n /= 10;
        i++;
    }

    if (i == 1)
    {
        printf("%d have %d digit\n", num, i);
    }
    else
    {
        printf("%d have %d digits\n", num, i);
    }
    printf("Sum of the digits of %d is %d", num, sum);
    return 0;
}