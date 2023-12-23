#include "monty.h"
/**
 *free_stack - deletes the full stack
 *@stack: head pointer
 *Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
