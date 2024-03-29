#include "monty.h"
/**
 *main - entry point for monty
 *@ac: argument count
 *@av: argument vector
 *Return: 0 if successfull 1 if not
 */
int main(int ac, char **av)
{
	FILE *file;
	char buffer[1024];
	char *full_str, *num_str;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	int num;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_number++;
		full_str = strstrip(buffer);
		if (full_str[0] == '\0' || buffer[0] == '\n')
		{
			free(full_str);
			continue;
		}
		if (strncmp(full_str, "push ", 5) == 0)
		{
			num_str = full_str + 5;
			if (*num_str == '\0')
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			num = atoi(num_str);
			if (num == 0 && *num_str != '0')
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				push(&stack, num);
		}
		else if (strncmp(full_str, "pall", 4) == 0)
			pall(&stack);
		else if (strncmp(full_str, "pint", 4) == 0)
		{
			if (stack == NULL)
			{
				fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				pint(&stack);
		}
		else if (strncmp(full_str, "pop", 3) == 0)
		{
			if (stack == NULL)
			{
				fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				pop(&stack);
		}
		else if (strncmp(full_str, "swap", 4) == 0)
		{
			if (stack == NULL || (stack->next) == NULL)
			{
				fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				swap(&stack);
		}
		else if (strncmp(full_str, "add", 3) == 0)
		{
			if (stack == NULL || (stack->next) == NULL)
			{
				fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				add(&stack);
		}
		else if (strncmp(full_str, "sub", 3) == 0)
		{
			if (stack == NULL || (stack->next) == NULL)
			{
				fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				sub(&stack);
		}
		else if (strncmp(full_str, "div", 3) == 0)
		{
			if (stack == NULL || (stack->next) == NULL)
			{
				fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			if (stack->n == 0)
			{
				fprintf(stderr, "L%u: division by zero\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				mdiv(&stack);
		}
		else if (strncmp(full_str, "mul", 3) == 0)
		{
			if (stack == NULL || (stack->next) == NULL)
			{
				fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				mmul(&stack);
		}
		else if (strncmp(full_str, "mod", 3) == 0)
		{
			if (stack == NULL || (stack->next) == NULL)
			{
				fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			if (stack->n == 0)
			{
				fprintf(stderr, "L%u: division by zero\n", line_number);
				free(full_str);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			else
				mmod(&stack);
		}
		else if (strncmp(full_str, "nop", 3) == 0 || (strncmp(full_str, "#", 1) == 0))
		{
			nop(&stack);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, full_str);
			free(full_str);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		free(full_str);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
