#include "main.h"

/**
 * increment - increment of line number
 * Return: new line number
 */
int increment(void)
{
	return (++lineNo);
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
