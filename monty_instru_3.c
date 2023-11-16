#include "monty.h"

/**
 * pchar - print character value equavilant to value
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			printf("%c\n", (*stack)->n);
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - print string equavailent to all stack
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00)
	{
		stack_t *currentStack = *stack;

		while (currentStack != 0x00)
		{
			if ((*stack)->n >= 0 && (*stack)->n <= 127)
			{
				printf("%c\n", (*stack)->n);
			}
			else
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * rotl - rotate the string
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	if (*stack != 0x00)
	{
		stack_t *currentStack = *stack;

		while (currentStack != 0x00)
		{
			if ((*stack)->n >= 0 && (*stack)->n <= 127)
			{
				printf("%c\n", (*stack)->n);
			}
			else
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - do nothing
 * @stack: the stack used
 * @line_number: the line number of excution
 * Return: the value on top
 */
void nop(stack_t **stack, unsigned int line_number)
{
	if (line_number || stack)
		return;
}
