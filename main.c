#include "monty.h"

jay_t *jay;

/**
 * main - entry point
 * @argc: count of arguments passed to the program from the command line
 * @argv: double pointer to the arguments passed to the program from the
 * command line
 *
 * Description: controls the flow of the program
 * Return: Always EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	jay_t temp = {NULL, NULL, NULL, NULL, NULL, 0};

	jay = &temp;
	jay->file_name = argv[1];
	if (argc != 2)
		error_check(INCORRECT_ARGS);
	jay->file = fopen(jay->file_name, "r");
	if (!jay->file)
		error_check(NOT_FILE);
	while (getline(&jay->line, &len, jay->file) != -1)
	{
		jay->line_count++;
		jay->opcode_tkn = malloc(sizeof(char *) * 2);
		if (jay->opcode_tkn == NULL)
			error_check(MEM_FAIL);
		cmd_token(jay->line);
		stack_fxn();
	}
	free_line();
	free_dlist(jay->head);
	free_opcode_tkn();
	fclose(jay->file);
	return (0);
}

/**
 * args_check - checks to make sure the number of arguments passed is correct
 * @ac: the count of arguments
 * Description: checks to make sure there isn't an invalid number of
 * arguments being passed to the function
 * Return: 0 if the number of arguments is correct otherwise, INCORRECT_ARGS
 */
size_t args_check(int ac)
{
	if (ac != 2)
		return (INCORRECT_ARGS);
	else
		return (0);
}

/**
 * file_check - checks to make sure the file is valid
 * @file: the file to be checked
 * Description: checks to make sure the file passed on the command line
 * is a valid file
 * Return: 0 if file is valid otherwise,
 */
size_t file_check(FILE *file)
{
	if (!file)
		return (NOT_FILE);
	else
		return (0);
}
