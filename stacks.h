#ifndef _STACKS_H_
#define _STACKS_H_

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define DELIM " \t"
#define NOT_FILE 33
#define INCORRECT_ARGS 98
#define INVALID_CMD 93
#define ARGS_TAKEN 0
#define NO_ARGS_TAKEN 1
#define MEM_FAIL 52
#define PINT_FAIL 972
#define SWAP_FAIL 92101
#define POP_FAIL 94103
#define ADD_FAIL 25
#define PUSH_FAIL 19
#define NO_CMD 44

/**
 * struct jay_s - global variable to hold needed data for other functions
 * @line_count: the line that is being parsed
 * @head: the pointer to the head node of list
 * @n: number to be put into linked list
 * @opcode_tkn: holds the token of the opcodes and any parameters
 * @file_name: the file name to be passed in error checks
 *
 * Description: structure to be externed and used throughout program to
 * manipulate the stack
 */
typedef struct jay_s
{
	stack_t *head;
	char *opcode_tkn;
	char *file_name;
	char *line;
	unsigned int line_count;
} jay_t;

extern jay_t *jay;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

void stack_fxn(void);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void error_check(unsigned int exit_code);
void free_dlist(stack_t *head);
size_t args_check(int ac);
size_t file_check(FILE *file);
stack_t *add_dnode(void);

#endif /* _STACKS_H_ */
