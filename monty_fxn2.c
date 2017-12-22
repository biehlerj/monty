#include "monty.h"

/**
 * _add - adds the data in the top two elements of the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: goes through the stack and adds the top two
 * elements of the stack if it can
 * Return: Nothing (void)
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	(void) stack;
	(void) line_number;

	if (!jay->head || !jay->head->next)
		error_check(ADD_FAIL);
	sum = jay->head->n + jay->head->next->n;
	jay->head->next->n = sum;
	_pop(NULL, 0);
}

/**
 * _sub - subtracts the data in the top two elements of the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: subtracts the data in the top two elements of the stack and
 * makes the result the head node
 * Return: Nothing (void)
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	(void) stack;
	(void) line_number;

	if (!jay->head || !jay->head->next)
		error_check(SUB_FAIL);
	diff = jay->head->next->n - jay->head->n;
	jay->head->next->n = diff;
	_pop(NULL, 0);
}
