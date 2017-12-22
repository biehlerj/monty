#include "monty.h"

/**
 * add_dnode - adds a doubly linked node to the stack
 *
 * Description: creates a node for push to put on the stack
 * Return: pointer to the new node or NULL if fails
 */
stack_t *add_dnode(void)
{
	stack_t *new;
	stack_t *temp = jay->head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = 0;
	if (temp == NULL)
		new->next = NULL;
	else
		new->next = temp;
	new->prev = NULL;
	if (temp)
		temp->prev = new;
	jay->head = new;
	return (new);
}

/**
 * cmd_token - tokenizes the command on the current line
 * @line: the line being parsed
 * Description: takes the line from the file being passed as the argument
 * and tokenizes it to check if it a valid function
 * Return: Nothing (void)
 */
void cmd_token(char *line)
{
	char *opcode_tkn = NULL;
	int i;

	jay->opcode_tkn[0] = NULL;
	jay->opcode_tkn[1] = NULL;
	opcode_tkn = strtok(line, DELIM);
	for (i = 0; opcode_tkn != NULL && i < 2; i++)
	{
		jay->opcode_tkn[i] = strdup(opcode_tkn);
		if (jay->opcode_tkn[i] == NULL)
			error_check(MEM_FAIL);
		opcode_tkn = strtok(NULL, DELIM);
	}
}

/**
 * free_dlist - frees nodes in the stack
 * @head: pointer to the first node in the stack
 * Description: frees the node(s) as needed
 * Return: Nothing (void)
 */
void free_dlist(stack_t *head)
{
	if (head)
	{
		if (head->next != NULL)
			free_dlist(head->next);
		free(head);
	}
}

/**
 * free_line - frees the pointer holding the line currently being looked at
 * Description: Frees the pointer pointing to the line being parsed
 * Return: Nothing (void)
 */
void free_line(void)
{
	if (jay->line)
	{
		free(jay->line);
		jay->line = NULL;
	}
}

/**
 * free_token - frees the token if the program is exiting
 * Description: frees the token stored currently on exit or other failure
 * Return: Nothing (void)
 */
void free_opcode_tkn(void)
{
	if (jay->opcode_tkn)
	{
		if (jay->opcode_tkn[0])
			free(jay->opcode_tkn[0]);
		if (jay->opcode_tkn[1])
			free(jay->opcode_tkn[1]);
		free(jay->opcode_tkn);
	}
	jay->opcode_tkn = NULL;
}
