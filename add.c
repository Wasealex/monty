#include "monty.h"
/**
 *add - adds two members(fisrt two only)
 *@stack: pointer to head
 *@line_number: instruction line
 *Return: 1 if its short
 */
int add(stack_t **stack, __attribute((unused))unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		return (1);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp->n;
	(*stack)->prev = NULL;
	free(temp);
	return (0);
}
