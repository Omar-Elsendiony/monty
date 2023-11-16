#include "monty.h"

/*Definition*/

char *currentValue = "123";

int increment(int *lineNo)
{
	return (++(*lineNo));
}

void rmNewLine(char *str)
{
	int i = 0;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
}

void freeAllStack(stack_t *s)
{
	stack_t *tmp = s;

	if (!s)
		return;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(s);
		s = tmp;
	}
	free(tmp);
}

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
	int intVal;

	if (currentValue == 0x00)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	intVal = atoi(currentValue);
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

void pint(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void pall(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void pop(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void swap(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
	if (*stack != 0x00 && (*stack)->next != 0x00)
	{
		stack_t *seqStack = (*stack)->next->next; /* will be used to hold the value of the sequence strting from third element*/
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

void add(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void sub(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void div_op(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void mod(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void mul(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void pchar(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void pstr(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void rotl(stack_t **stack, unsigned int line_number)
{
	/* will try convert the value of the string arg before adding to stack*/
	/* if the stack is empty so the first element points to NULL and the newly created element is the HEAD*/
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

void nop(stack_t **stack, unsigned int line_number)
{
	if (line_number || stack)
		return;
}
