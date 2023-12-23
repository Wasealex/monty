#include "monty.h"
/**
 *free_stack - deletes the list after completion
 *@stack: head pointer
 *return: void
 */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    while (current != NULL)
    {
        stack_t *next = current->next;
        free(current);
        current = next;
    }
}
