#include <stdio.h>

int main ()
{
    int n, lar = 0;
    printf("How many numbers you want to input?\n");
    printf("Answer:\t");
    scanf("%d", &n);

    int num[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d:\t", (i + 1));
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (num[i] > lar)
        {
            lar = num[i];
        }
    }

    printf("The largest number is %d", lar);

    return 0;
}