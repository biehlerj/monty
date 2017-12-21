#include "stacks.h"

/**
 * _push - pushes an element to the stack
 * @stack: dummy pointer
 * @line_number: dummy line_number variable
 * Description: creates a new node and adds it to the stack
 * Returns: Nothing (void)
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	unsigned int i = 0, flag = 0, neg_flag = 0, error_code = 0;
	char *cmp = jay->opcode_tkn;

	(void) stack;
	(void) line_number;
	new = add_dnode();
	if (new == NULL)
	{
		error_code =  MEM_FAIL;
		error_check(error_code);
	}
	if (cmp != NULL)
	{
		if (cmp[0] != '-')
		{
			i++;
			flag = 1;
			neg_flag = 1;
		}
		while (cmp[i])
		{
			if (isdigit(cmp[i]) == 0)
			{
				flag = 1;
				break;
			}
			i++, flag = 0;
		}
		if (flag == 0)
		{
			if (neg_flag == 1)
				cmp = cmp + 1;
			new->n = atoi(cmp);
			if (neg_flag == 1)
				new->n *= -1;
			return;
		}
	}
	error_code = PUSH_FAIL;
	error_check(error_code);
}

/**
 * _pall - prints all the values on the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: Goes through the stack and prints all the values contained
 * in the stack, if the stack is empty it doesn't print
 * Return: Nothing (void)
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = jay->head;

	(void) stack;
	(void) line_number;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: Goes through the stack and prints the value at the top
 * Return: Nothing (void)
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	return;
}

/**
 * _pop - removes the top element of the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: Goes through the stack and removes the top element of the stack
 * Return: Nothing (void)
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	return;
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: goes through the stack and switches the places of
 * the top two elements
 * Return: Nothing (void)
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	return;
}
