#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @currentIndex: Current index in the format string
 * Return: Flags
 */
int get_flags(const char *format, int *currentIndex)
{
	/*Flags: - + 0 # ' '*/
	/*Values: 1 2 4 8  16*/
	int j, currentIdx;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO,
		FLAG_HASH, FLAG_SPACE, 0};

	for (currentIdx = *currentIndex + 1; format[currentIdx] != '\0'; currentIdx++)
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
		{
			if (format[currentIdx] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_VALUES[j];/*Bitwse or and assignment*/
				break;
			}
		}
		if (FLAGS_CHARS[j] == 0)
			break;
	}
	*currentIndex = currentIdx - 1;
	return (flags);
}
