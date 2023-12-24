#include "monty.h"
/**
 *add - adds two members(fisrt two only)
 *@stack: pointer to head
 *@line_number: instruction line
 *Return: 1 if its short
 */
void add(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
