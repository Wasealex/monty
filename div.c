#include "monty.h"
/**
 *mdiv - divid the second value from the top value and store it on the first
 *@stack: head pointer
 *Return: void
 */
void mdiv(stack_t **stack)
{

	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
