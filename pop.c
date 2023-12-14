#include "monty.h"
/**
 *pop - remove at end
 *stack: head pointer
 *line_number: the line where the instruction is found
 *Return: 1 if the stack is empty
 */
int pop(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *to_the_end;

	if (stack == NULL)
	{
		return (1);
	}
	else if (*stack == NULL)
	{
		return (1);
	}
	else
	{
		to_the_end = *stack;
		*stack = (*stack)->next;
		free(to_the_end);
	}
	return (0);
}
