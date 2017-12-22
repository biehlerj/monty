#include "monty.h"

/**
 * stack_fxn - exectues the command if the command has been found to exist
 * Description: cycles through the available functions and passes it arguments
 * Return: nothing (void)
 */
void stack_fxn(void)
{
	unsigned int i;
	instruction_t cmd[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	if (!jay->opcode_tkn[0])
		return;
	for (i = 0; cmd[i].opcode; i++)
	{
		if (strcmp(jay->opcode_tkn[0], cmd[i].opcode) == 0)
		{
			cmd[i].f(NULL, 0);
			break;
		}
	}
	if (cmd[i].opcode == NULL)
		error_check(INVALID_CMD);
}

/**
 * error_check - checks the error code and prints the correct error message
 * @error_code: the error code that of the error that occured
 * Description: Receives and error code and prints out the correct error
 * Returns: Nothing, exits with EXIT_FAILURE
 */
void error_check(unsigned int error_code)
{
	if (error_code == NOT_FILE)
		printf("Error: Can't open file %s\n", jay->file_name);
	if (error_code == INCORRECT_ARGS)
		printf("USAGE: monty file\n");
	if (error_code == INVALID_CMD)
		printf("L%d: unknown instruction %s\n", jay->line_count, jay->opcode_tkn[0]);
	if (error_code == MEM_FAIL)
		printf("Error: malloc failed");
	if (error_code == PINT_FAIL)
		printf("L%d: can't pint, stack empty\n", jay->line_count);
	if (error_code == POP_FAIL)
		printf("L%d: can't pop an empty stack\n", jay->line_count);
	if (error_code == SWAP_FAIL)
		printf("L%d: can't swap, stack too short\n", jay->line_count);
	if (error_code == ADD_FAIL)
		printf("L%d: can't add, stack too short\n", jay->line_count);
	if (error_code == PUSH_FAIL)
		printf("L%d: usage: push integer\n", jay->line_count);
	free_line();
	free_dlist(jay->head);
	free_opcode_tkn();
	if (jay->file)
		fclose(jay->file);
	exit(EXIT_FAILURE);
}
