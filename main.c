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
	stack_t *stackTail = NULL;
	size_t n = 0;
	char *line = NULL;
	FILE *fd;
	char *d = " ";
	char *por;
	int i = 0;

	(void)stackTail;
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	while (getline(&line, &n, fd) != -1)
	{
		rmNewLine(line);
		por = strtok(line, d);
		currentValue = strtok(NULL, d);
		if (por)
		{
			i = 0;
			while (instructionArr[i].opcode)
			{
				if (strcmp(instructionArr[i].opcode, por) == 0)
				{
					instructionArr[i].f(&stackHead, lineNo);
					break;
				}
				++i;
			}
		}

		if (instructionArr[i].opcode == NULL)
		{
			fprintf(stderr, "L %d: unknown instruction %s\n", lineNo, por);
			exit(EXIT_FAILURE);
		}
		increment(&lineNo);
	}
	free(line);
	freeAllStack(stackHead);
	fclose(fd);
	return (0);
}
