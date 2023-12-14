#include "monty.h"
/**
 *free_stack - deletes the list after completion
 *@stack: head pointer
 *return: void
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
