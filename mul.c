#include "monty.h"
/**
 *mmul - adds two members(fisrt two only)
 *@stack: pointer to head
 *Return: 1 if its short
 */
void mmul(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
