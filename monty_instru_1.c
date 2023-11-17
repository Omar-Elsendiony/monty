#include "monty.h"

/**
 * push - push value to stack
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	/**
	 * will try convert the value of the string arg before adding to stack
	 * if the stack is empty so the first element points to NULL
	 * the newly created element is the HEAD
	 */
	int intVal;

	intVal = atoi(currentValue);
	if ((intVal == 0 && currentValue[0] != '0' )|| currentValue == 0x00)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack == 0)
	{
		*stack = malloc(sizeof(stack_t));
		if (*stack == 0x00)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		(*stack)->n = intVal;
		(*stack)->next = 0; /*null*/
		(*stack)->prev = 0; /*null*/
	}
	else
	{
		stack_t *newStack = malloc(sizeof(stack_t));

		if (*stack == 0x00)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		(newStack)->n = intVal;
		(newStack)->next = (*stack);
		(newStack)->n = intVal;
		(*stack)->prev = newStack;
		*stack = newStack;
	}
}

/**
 * pint - print top of the stack
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
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
	stack_t *currentNode = *stack;

	while (currentNode != 0)
	{
		if (line_number)
		{
			pint(&currentNode, line_number);
			currentNode = currentNode->next;
		}
	}
}

/**
 * pop - remove one element of the
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0)
	{
		stack_t *currentStack = (*stack);
		(*stack) = (*stack)->next;
		free(currentStack);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swap two top elements of stack
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00 && (*stack)->next != 0x00)
	{
		/* will be used to hold the value of the sequence strting from third elmnt*/
		stack_t *seqStack = (*stack)->next->next;
		stack_t *secondElement = (*stack)->next;
		(*stack)->next = seqStack;
		(*stack)->prev = secondElement;
		(secondElement)->next = (*stack);
		secondElement->prev = 0x00;
		(*stack) = secondElement;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
