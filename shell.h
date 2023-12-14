#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/*
 * String Utility functions
 */

int _strlen(char *);
void _puts(char *);
int _getline(const int fd, char **line);
static int process_line(char **line, char **rd, int pos);
int _strcmp(char *, char *);
char *_strncpy(char *, const char *, size_t);
char *_strdup(const char *);
char *_strcat(char *, char *);

/*
 * General Utility functions
 */

int _index(const char *, const char);
void *_realloc(void *, size_t);

/*
 * Parser functions
 */

char *_strpbrk(char *s, const char *accept);
char *_strtok(char *str, const char *delim);

/**
 * enum rel - enum for type of relation between commands in a single line
 * @OR: indicating relation with next command is '||' operator.
 * @AND: indicating relation with next command is '&&' operator.
 * @SEM: indicating relation with next command is ';' operator.
 * @END: means no command after current command.
 */
enum rel
{
	OR,
	AND,
	SEM,
	END
};

/**
 * struct cmd_s - singly linked list of commands
 * @cmd: NULL terminated array of strings - hold the cmd in index 0, and it's
 * arguments starting from index 1.
 * @type: enum rel - indicate the relationship between commands if there are
 * other commands, the rel can be '&&', ';' or ||.
 * @next: points to the next node
 *
 * Description: this data structure store info about parsed line, that can have
 * one or multiple commands related with each other by '&&', ';' or '||'.
 * Example:
 * ========
 * simple_cmd = "ls -l"
 * => {cmd=["/bin/ls", "-l"], type=END, next=NULL};
 *
 * two_cmd = "ls; cat filename"
 * => {cmd=["/bin/ls"], type=SEM, next=ptr_next}
 *		=> {cmd=["/bin/cat", "file_name"], type=END, next=NULL};
 */
typedef struct cmd_s
{
	char **cmd;
	enum rel type;
	struct cmd_s *next;
} t_cmd;

/*
 * execute functions
 */

/*
 * Implemented Builtin functions
 */

/*
 * the linked list node and functions for environment variables.
 */

/**
 * struct s_pair - Represents a node in a linked list.
 * @key: The key associated with the node.
 * @value: The value associated with the key.
 * @next: Pointer to the next node in the linked list.
 * @is_alias: Flag to indicate whether it's an alias (1)
 * or environment variable (0)
 */

typedef struct s_pair
{
	char *key;
	char *value;
	struct s_pair *next;
	int is_alias;
} t_pair;

void print_list(t_pair *head);
t_pair *add_Node(t_pair *head, char *key, char *value, int is_alias);
t_pair *remove_Node(t_pair *head, char *key, int is_alias);
t_pair *initialize_list(char *envp[]);
void free_list(t_pair *head);

#endif
