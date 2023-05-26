#include "monty.h"
/**
 *
 *
 */
int data;
void _push(stack_t **head, __attribute__((unused)) unsigned int linenumber)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

void _pall(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *head;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void _pint(stack_t **top, unsigned int line)
{
	if (*top != NULL)
		printf("%d\n", (*top)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
}

void _pop(stack_t **head, unsigned int num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *head;
	*head = (*head)->next;
	free(temp);
}

void _swap(stack_t **head, unsigned int num)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	stack_t *top = *head;
	stack_t *second = (*head)->next;
	stack_t *third = second->next;

	second->next = top;
	top->next = third;

	*head = second;
}

void _add(stack_t **head, unsigned int num)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}

	int sum = (*head)->n + ((*head)->next)->n;
	(*head)->n = sum;
	stack_t *tmp = (*head)->next;
	(*head)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *head;
	free(tmp);
}

void _nop(__attribute__((unused)) stack_t **head, __attribute__((unused)) unsigned int num)
{
}

