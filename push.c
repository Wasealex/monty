#include "monty.h"
/**
 *push - adds a value on stack
 *@stack: head pointer
 *@n: value to be added
 *return: void
 */
void push(stack_t **stack, int n)
{
    /* Create a new node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    /* Set the value of the new node */
    new_node->n = n;
    /* Set the links of the new node */
    new_node->prev = NULL;
    new_node->next = *stack;
    /* Set the previous link of the previous top node */
    if (*stack != NULL)
        (*stack)->prev = new_node;
    /* Update the stack to point to the new node */
    *stack = new_node;
}
