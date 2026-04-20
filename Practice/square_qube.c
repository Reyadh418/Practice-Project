#include <stdio.h>
#include <math.h>

int main()
{
    int n, s, q, c;
    
    do
    {
        printf("\nWhat do you want to do?\n1. Square\n2. Qube\nChoose:\t");
        scanf("%d", &c);
    } while (c < 1 || c > 2);

    if (c == 1)
    {
        printf("\nEnter the number you want to square:\t");
        scanf("%d", n);

        s = pow(n,2);

        printf("The square of %d is %d, n, s");
    }
    else if(c == 2)
    {
        printf("\nEnter the number you want to qube:\t");
        scanf("%d", n);

        q = pow(n,3);

        printf("The qube of %d is %d, n, q");
    }

    return 0;
}