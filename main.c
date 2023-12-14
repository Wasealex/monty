#include "monty.h"
#include <stdio.h>
/**
 *main - entry point
 *@ag: no of arguments
 *@av: vector of argument
 *Return: 0 if success
 */
int main(int ag, char **av)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *full_str;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int n;

	if (ag != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		full_str = strstrip(line);
		if (strncmp(full_str, "push", 4) == 0)
		{
			n = atoi(full_str + 4);
			push(&stack, line_number, n);
		}
		else if (strncmp(full_str, "pall", 4) == 0)
		{
			pall(&stack, line_number);
		}
		else
			printf("%s", full_str);
        }
	printf("total line number is %d\n", line_number);
	fclose(file);
	free(line);
	return (0);
}
