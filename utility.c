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

/**
 * checks - run some checks
 * @argc: number of argu
 * @fileName: the name of file
 * Return: nothing
 */
void checks(int argc, char *fileName)
{
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(fileName, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
}

/**
 * instru - search for instruction and do it
 * @por: the instruction name
 * @instruArr: array of instruction and names
 * @lineNo: the line number
 * @stack: the stack
 * Return: nothing
 */
void instru(char *por, instruction_t *instruArr, int lineNo, stack_t **stack)
{
	int i;

	if (por)
	{
		i = 0;
		while (instruArr[i].opcode)
		{
			if (strcmp(instruArr[i].opcode, por) == 0)
			{
				instruArr[i].f(stack, lineNo);
				break;
			}
			++i;
		}
	}
	if (instruArr[i].opcode == NULL)
	{
		fprintf(stderr, "L %d: unknown instruction %s\n", lineNo, por);
		exit(EXIT_FAILURE);
	}
}
