#include "monty.h"
/**
 *push - adds a new node at the beginning of the stack
 *@stack: a head pointer pointing to the first node or NULL
 *@line_number: the number that the instruction is found
 *@n: data to be inserted
 *Return: the address of new element or NULL if it failed
 */
stack_t *push(stack_t **stack, __attribute__((unused))unsigned int line_number, int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	return (new_node);
}
