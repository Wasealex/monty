#include "monty.h"
/**
 *isNumeric - checks if it contains non-intiger
 *@str: string to be checked
 *Return: 0 if is not digit 1 if it is
 */
int isNumeric(char *str)
{
	char *endptr;

	if (str == NULL || *str == '\0')
		return (0);

	strtol(str, &endptr, 10);

	return (*endptr == '\0');
}
