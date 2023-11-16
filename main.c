#include "main.h"

int lineNo = 1;
int currentValue = 0;
stack_t *stack = NULL;

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
									  {NULL, NULL}};
	char errorMsgCon[4096] = "Error: Can't open file ";
	size_t n = 0;
	char *line = NULL;
	FILE *fd;
	char *d = " ";
	char *por;
	int i = 0;

	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		puts(strcat(errorMsgCon, argv[1]));
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	while (getline(&line, &n, fd) != -1)
	{
		rmNewLine(line);
		por = strtok(line, d);
		if (por)
		{
			i = 0;
			while (instructionArr[i].opcode)
			{
				if (strcmp(instructionArr[i].opcode, por) == 0)
				{
					instructionArr[i].f(&stack, lineNo);
					break;
				}
				++i;
			}
		}

		if (instructionArr[i].opcode == NULL)
		{
			printf("L %d: unknown instruction %s", lineNo, por);
			exit(EXIT_FAILURE);
		}
	}
}