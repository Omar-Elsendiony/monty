#include "monty.h"

/**
 * increment - increase the line number
 * @lineNo: the line number of excution
 * Return: the new line number
 */
int increment(int *lineNo)
{
	return (++(*lineNo));
}

/**
 * rmNewLine - removes new line char
 * @str: the string to be processed
 * Return: nothing
 */
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

/**
 * freeAllStack - free the stack
 * @s: the stack
 * Return: nothing
 */
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
