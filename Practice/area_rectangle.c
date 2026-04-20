#include <stdio.h>

int main()
{
    int a, b, area;

    printf("\nEnter the base of the rectangle:\t");
    scanf("%d", &b);

    printf("\nEnter the height of the rectangle:\t");
    scanf("%d", &a);

    area = a * b;

    printf("\nThe area of the rectangle is %d", area);

    return 0;
}