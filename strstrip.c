#include "monty.h"
/**
 *strstrip - a function that clears white spaces
 *@str: the string to be processed
 *Return: trimmed string
 */
char *strstrip(const char *str)
{
	int start = 0, end = strlen(str) - 1, trimmed_length = 0;
	char *trimmed_str;

	if (str == NULL)
		return (NULL);
	while (str[start] == ' ')
		start++;
	while (str[end] == ' ')
		end--;
	trimmed_length = (end - start) + 1;
	trimmed_str = malloc(sizeof(char) * (trimmed_length + 1));
	if (trimmed_str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (trimmed_length == 1)
	{
		trimmed_str[0] = '\0';
	}
	else
	{
		strncpy(trimmed_str, str + start, trimmed_length);
		trimmed_str[trimmed_length] = '\0';
	}
	return (trimmed_str);
}
