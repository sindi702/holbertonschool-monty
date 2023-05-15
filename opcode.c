#include "monty.h"
/**
 *
 */
function_ptr get_op(char *token, unsigned int line)
{
	int i;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	while (isspace((unsigned char) *token))
		token++;

	char *end = token + strlen(token) - 1;
	while (end > token && isspace((unsigned char) *end))
		end--;
	end[1] = '\0';


	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcasecmp(token, op[i].opcode) == 0)
			return op[i].f;
	}

	fprintf(stderr, "L %u : unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}
