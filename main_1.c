#include "monty.h"

/* definitions */
int lineNo = 1;
int currentValue = 0;
stack_t **stack = 0x00;
int increment(void) { return ++lineNo; }


/**
 * *push - pushes the element into the stack
 * @stack: pointer to the stack elements and its value is pointer to the first element
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
void push(stack_t **stack, unsigned int line_number)
{
    /* will try convert the value of the string arg before adding to stack*/
    /* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
    if (stack == 0)
    {
        stack_t *newStack = malloc(sizeof(stack_t));
        newStack->n = currentValue;
        newStack->next = 0; /*null*/
        newStack->prev = 0; /*null*/
        if (line_number == 0)
            return;
    }
}
