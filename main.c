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
	char line[1024];
	char *full_str;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int n;

	if (ag != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		full_str = strstrip(line);
		if (strncmp(full_str, "push", 4) == 0)
		{
			n = atoi(full_str + 4);
			if (n == 0)
			{
				fprintf(stderr,	"L%d: usage: push integer",
					line_number);
				exit(EXIT_FAILURE);
			}
			else
				push(&stack, line_number, n);
		}
		else if (strncmp(full_str, "pall", 4) == 0)
		{
			pall(&stack, line_number);
		}
		else
			printf("%s", full_str);
		free(full_str);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
