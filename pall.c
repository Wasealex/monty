#include "monty.h"
/**
 *pall - prints all the elements of a 'stack_t' list
 *@stack: head pointer pointing to the first node
 *Return: if failed to print
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
		printf("\n");
	else
	{
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
