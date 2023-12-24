#include "monty.h"
/**
 *swap - swaps to memebers
 *@stack: pointer to first node
 *Return: 1 if element less than 2
 */
void swap(stack_t **stack)
{
	stack_t *temp;

	if (!stack || !*stack || !((*stack)->next))
	{
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if ((*stack)->next)
		((*stack)->next)->prev = temp;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
}
