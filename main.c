#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int mine, tru;
    char str2 = 'E';
    char *str = "Edemialem";

   	mine = _printf("The first letter of my name is: %c %%  and my full name is: %s\n", str2, str);
      tru = printf("The first letter 0f my name is: %c %%  and my full name is: %s\n", str2, str);
    printf("length of mine is %d and the exact is %d \n", mine, tru);
    return (0);
}
