#include "monty.h"

/**
 * pushIntErr - print error msg when failed push
 * @lineNo: the line number
 * Return: always error
*/
int pushIntErr(int lineNo)
{
	fprintf(stderr, "L%d: usage: push integer\n", lineNo);
	exit(EXIT_FAILURE);
}
