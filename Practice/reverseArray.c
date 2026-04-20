#include <stdio.h>

int main()
{
    int n;

    printf("How many numbers you want to enter?\n");
    scanf("%d", &n);
    int num[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d:\t", (i + 1));
        scanf("%d", &num[i]);
    }
    printf("The reversed numbers are: \n");

    for (int i = (n - 1); i >= 0; i--)
    {
        printf("\t%d\n", num[i]);
    }
    return 0;
}