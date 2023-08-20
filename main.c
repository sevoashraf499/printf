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
    int len, len2;
    char str2 = 'E';
    char *str = "Edemialem";

   len = _printf("The first letter of my name is: %c %%  and my full name is: %s\n", str2, str);
   len2 = printf("The first letter 0f my name is: %c %%  and my full name is: %s\n", str2, str);
    printf("length of local pintf is %d and the std print is %d \n", len, len2);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    return (0);
}
