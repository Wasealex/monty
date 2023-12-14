#include "monty.h"
/**
 *pall - prints all the elements of a 'stack_t' list
 *@stack: head pointer pointing to the first node
 *@line_number: line number of instruction
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
/**
 *pint - prints all the elements of in reverse a 'stack_t' list
 *@stack: head pointer pointing to the first node
 *@line_number: line number of instruction
 *Return: if failed to print
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		printf("\n");
		exit(EXIT_FAILURE);
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
