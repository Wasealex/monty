#include "monty.h"
/**
 *pop - remove at end
 *@stack: head pointer
 *Return: 1 if the stack is empty
 */
void pop(stack_t **stack)
{
	stack_t *to_the_end;

	if (stack == NULL)
	{
		return;
	}
	else if (*stack == NULL)
	{
		return;
	}
	else
	{
		to_the_end = *stack;
		*stack = (*stack)->next;
		free(to_the_end);
	}
}
