#include "monty.h"

/**
 * add - add two top elements
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00 && (*stack)->next != 0x00)
	{
		stack_t *secondElement = (*stack)->next;
		stack_t *firstElement = (*stack);
		(secondElement)->n += (*stack)->n;
		(secondElement)->prev = 0x00;
		firstElement->next = 0x00;
		(*stack) = secondElement;
		free(firstElement);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * sub - subtract two top elemnts
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00 && (*stack)->next != 0x00)
	{
		stack_t *secondElement = (*stack)->next;
		stack_t *firstElement = (*stack);
		(secondElement)->n -= (*stack)->n;
		(secondElement)->prev = 0x00;
		firstElement->next = 0x00;
		(*stack) = secondElement;
		free(firstElement);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_op - divide top element on a number
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00 && (*stack)->next != 0x00)
	{
		stack_t *secondElement = (*stack)->next;
		stack_t *firstElement = (*stack);

		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(secondElement)->n /= (*stack)->n;
		(secondElement)->prev = 0x00;
		firstElement->next = 0x00;
		(*stack) = secondElement;
		free(firstElement);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod - reminder operation of top elemnt for a given number
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00 && (*stack)->next != 0x00)
	{
		stack_t *secondElement = (*stack)->next;
		stack_t *firstElement = (*stack);

		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(secondElement)->n %= (*stack)->n;
		(secondElement)->prev = 0x00;
		firstElement->next = 0x00;
		(*stack) = secondElement;
		free(firstElement);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul - multiply two top elemnts
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00 && (*stack)->next != 0x00)
	{
		stack_t *secondElement = (*stack)->next;
		stack_t *firstElement = (*stack);
		(secondElement)->n *= (*stack)->n;
		(secondElement)->prev = 0x00;
		firstElement->next = 0x00;
		(*stack) = secondElement;
		free(firstElement);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
