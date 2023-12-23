#include "monty.h"
/**
 *pint - prints all the elements of in reverse a 'stack_t' list
 *@stack: head pointer pointing to the first node
 *Return: 1 if stack is empty
 */
void pint(stack_t **stack)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		return;
	}
	else
	{
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->prev;
		}
	}
}
