#include "monty.h"
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
	stack_t *check;
	unsigned int line_number = 0;
	int n, res;
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
			{
				check = push(&stack, line_number, n);
				if (check == NULL)
				{
					fprintf(stderr, "Error: malloc failed\n");
					free(full_str);
					fclose(file);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
			}
		}
		else if (strncmp(full_str, "pall", 4) == 0)
		{
			pall(&stack, line_number);
		}
		else if (strncmp(full_str, "pint", 4) == 0)
		{
			res = pint(&stack, line_number);
			if (res == 1)
			{
				fprintf(stderr, "L%d: can't pint an empty stack\n", line_number);
				free(full_str);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
		else if (strncmp(full_str, "pop", 3) == 0)
		{
			res = pop(&stack, line_number);
			if (res == 1)
			{
				fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
				free(full_str);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
		else if (strncmp(full_str, "swap", 4) == 0)
		{
			res = swap(&stack, line_number);
			if (res == 1)
			{
				fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
				free(full_str);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
		else if (strncmp(full_str, "add", 3) == 0)
		{
			res = add(&stack, line_number);
			if (res == 1)
			{
				fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
				free(full_str);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, full_str);
			free(full_str);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		free(full_str);
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
