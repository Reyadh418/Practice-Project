#include <stdio.h>

int main()
{
    printf("Let's go.\n");
    int n = 1;
    for (int i = 0; i < 5; i++)
    {
        printf("\n");

        for (int j = 0; j < n; j++)
        {
            printf("*");
        }
        n++;
    }
    return 0;
}