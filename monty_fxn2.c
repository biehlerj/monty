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

/**
 * _div - divides the top two elements of the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: divides the second element of the stack by the top element
 * of the stack and makes the result the top of the stack
 * Return: Nothing (void)
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int remainder = 0;
	(void) stack;
	(void) line_number;

	if (!jay->head || !jay->head->next)
		error_check(DIV_FAIL);
	if (jay->head->n == 0)
		error_check(DIV_BY_ZERO);
	remainder = jay->head->next->n / jay->head->n;
	jay->head->next->n = remainder;
	_pop(NULL, 0);
}

/**
 * _mul - multiplies the top two elements of the stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: multiplies the second element of the stack by the top element
 * of the stack and makes the product the top of the stack
 * Return: Nothing void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int product = 0;
	(void) stack;
	(void) line_number;

	if (!jay->head || !jay->head->next)
		error_check(MUL_FAIL);
	product = jay->head->next->n * jay->head->n;
	jay->head->next->n = product;
	_pop(NULL, 0);
}

/**
 * _mod - computes remainder of the division of the top two elements of stack
 * @stack: dummy variable
 * @line_number: dummy variable
 * Description: computes the remainder of the division of the second element
 * of the stack by the first element of the stack and makes the result the
 * top of the stack
 * Return: Nothing (void)
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	(void) stack;
	(void) line_number;

	if (!jay->head || !jay->head->next)
		error_check(MOD_FAIL);
	if (jay->head->n == 0)
		error_check(MOD_BY_ZERO);
	mod = jay->head->next->n % jay->head->n;
	jay->head->next->n = mod;
	_pop(NULL, 0);
}
