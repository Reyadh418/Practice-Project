#include <stdio.h>

int main(void)
{
    char str[32];
    char d = 'H';
    const char *fmt = "Hello, %s!";
    char c = 101; // ASCII 101 == 'e'

    printf("What's your name?\n");
    if (scanf("%31s", str) != 1) return 1; // prevent overflow

    printf("Welcome, %s\n", str);

    printf("%c\n", d);
    printf(fmt, str);   // prints "Hello, <name>!"
    printf("\n%c\n", c);

    return 0;
}