#include "monty.h"

char *currentValue = "0";
/**
 * main - Entry point
 * @argc: number of argu passed
 * @argv: array of strings passed
 * Return: zero on success
 */
int main(int argc, char *argv[])
{
	instruction_t instructionArr[] = {{"push", push},
									  {"pall", pall},
									  {"pint", pint},
									  {"pop", pop},
									  {"swap", swap},
									  {"add", add},
									  {"nop", nop},
									  {"sub", sub},
									  {"div_op", div_op},
									  {"mul", mul},
									  {"mod", mod},
									  {"pstr", pstr},
									  {"pchar", pchar},
									  {NULL, NULL}};
	int lineNo = 1;
	stack_t *stackHead = NULL;
	size_t n = 0;
	char *line = NULL;
	FILE *fd;
	char *por;
	int i = 0;

	checks(argc, argv[1]);
	fd = fopen(argv[1], "r");
	while (getline(&line, &n, fd) != -1)
	{
		rmNewLine(line);
		por = strtok(line, " ");
		currentValue = strtok(NULL, " ");
		instru(por, instructionArr, lineNo, &stackHead);
		increment(&lineNo);
	}
	free(line);
	freeAllStack(stackHead);
	fclose(fd);
	return (0);
}
