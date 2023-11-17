#include "monty.h"

/**
 * increment - increase the line number
 * @lineNo: the line number of excution
 * Return: the new line number
 */
int increment(unsigned int *lineNo)
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
 * instrNotFnd - error when no command found
 * @por: the instruction name
 * @lineNo: the line number
 * Return: alaways error
 */

int instrNotFnd(char *por, unsigned int lineNo)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNo, por);
	exit(EXIT_FAILURE);
}
