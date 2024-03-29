#include "monty.h"
/**
 *pall - prints the stack
 *@stack: head pointer
 *Return: void
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
