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
	int n, flag = 0;
	size_t i;
	instruction_t instructions[] = {
		{"pall", pall}
	};

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
		if (full_str[0] == '\0' || full_str[0] == '#')
		{
			continue;
		}
		if (strncmp(full_str, "push", 4) == 0)
		{
			n = atoi(full_str + 5);
			if (n == 0 && full_str[5] != '0')
			{
				if (strcmp(full_str + 5, "0") != 0)
				{
					fprintf(stderr,	"L%d: usage: push integer\n",
						line_number);
					free(stack);
					free(full_str);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}
			else
				push(&stack, line_number, n);
		}
		else
		{
			for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
			{
				if (strncmp(full_str, instructions[i].opcode, 4) == 0)
				{
					instructions[i].f(&stack, line_number);
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				fprintf(stderr, "L%d: unknown instruction %s",
					line_number, full_str);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
		free(full_str);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
