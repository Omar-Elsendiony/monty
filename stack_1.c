#include "main.h"

/**
 * push - push value to stack
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: Nothing
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

/**
 * pall - print all values of the stack
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	/*write code here*/
}

/**
 * pint - print top of the stack
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	/*write code here*/
}

/**
 * pop - remove one element of the
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
int pop(stack_t **stack, unsigned int line_number)
{
	/*write code here*/
}
