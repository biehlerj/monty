#include "stacks.h"

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
	FILE *file;
	char *data_tkn = malloc(sizeof(char *));
	size_t len;
	unsigned int exit_code = 0;
	jay_t dummy = {NULL, NULL, NULL, NULL, 1};

	jay = &dummy;
	exit_code = args_check(argc);
	if (exit_code == INCORRECT_ARGS)
		error_check(exit_code);
	jay->file_name = argv[1];
	file = fopen(jay->file_name, "r");
	exit_code = file_check(file);
	if (exit_code == NOT_FILE)
		error_check(exit_code);
	while (getline(&(jay->line), &len, file) != -1)
	{
		jay->line_count++;
		jay->opcode_tkn = malloc(sizeof(char *));
		if (jay->opcode_tkn == NULL || data_tkn == NULL)
		{
			exit_code = MEM_FAIL;
			error_check(exit_code);
		}
		jay->opcode_tkn = strtok(jay->line, DELIM);
		data_tkn = strtok(NULL, DELIM);
		if (jay->opcode_tkn == NULL)
		{
			exit_code = NO_CMD;
			error_check(exit_code);
		}
		stack_fxn();
		free(jay->opcode_tkn);
		free(data_tkn);

	}
	free(jay->line);
	free_dlist(jay->head);
	fclose(file);
	return (0);
}

/**
 * add_dnode - adds a doubly linked node to the stack
 *
 * Description: creates a node for push to put on the stack
 * Return: pointer to the new node or NULL if fails
 */
stack_t *add_dnode(void)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);
	new->n = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * free_dlist - frees nodes in the stack
 * @head: pointer to the first node in the stack
 * Description: frees the node(s) as needed
 * Return: Nothing (void)
 */
void free_dlist(stack_t *head)
{
	if (head == NULL)
	{
		if (head->next != NULL)
			free_dlist(head->next);
		free(head);
	}
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
