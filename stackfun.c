#include "monty.h"
/**
 *
 *
 */
int data;
void _push(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node = NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;

	if (new_node = NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;

	if (top = NULL)
	{
		new_node->next = NULL;
		*top = new_node;
	}
	else
	{
		new_node->next = top;
		top->prev = new_node;
		top = new_node;
	}
}
void _pall(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;

	while (*tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
void _pint(stack_t **top, unsigned int line)
{
	if (*top != NULL)
		printf("%d\n", *top->n);
	else
	{
		printf(stderr, "L%u: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
}
