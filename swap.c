#include "monty.h"
/**
 *swap - swaps to memebers
 *@stack: pointer to first node
 *@line_number: instructopn line number
 *Return: 1 if element less than 2
 */
int swap(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		return (1);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if ((*stack)->next)
		((*stack)->next)->prev = temp;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
	return (0);
}
