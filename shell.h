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

int _strlen(const char *);
int _puts(char *);
int _getline(char **line, const int fd);
int _strcmp(char *, char *);
char *_strncpy(char *, const char *, size_t);
char *_strdup(const char *);
char *_strcat(char *, char *);
char *ltrim(char *s, char *to_skip);

/*
 * General Utility functions
 */

int _index(const char *, const char);
void *_realloc(void *, size_t);

/* -----------------------------------------------------------------------
 * Parser Declarations
 * -----------------------------------------------------------------------
 */

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
typedef struct s_cmd
{
	char **cmd;
	enum rel type;
	struct s_cmd *next;
} t_cmd;

char *_strtok(char *str, const char *delim);
t_cmd *add_cmd(t_cmd *head, char **cmd, enum rel type);

/* -----------------------------------------------------------------------
 * Linked list functions and data type
 * -----------------------------------------------------------------------
 */

typedef struct s_list
{
	char *val;
	struct s_list *next;
} t_list;

t_list *add_elem(t_list **head, char *val);
char **list_to_arr(t_list *head);

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
 * struct s_env - Represents a node in a linked list.
 * @key: The key associated with the node.
 * @value: The value associated with the key.
 * @next: Pointer to the next node in the linked list.
 */

typedef struct s_env
{
	char *key;
	char *value;
	struct Node *next;
} t_env;

void print_list(t_env *head);
t_env *add_Node(t_env *head, char *key, char *value);
t_env *remove_Node(t_env *head, char *key);
t_env *initialize_list(char *envp[]);
void free_list(t_env *head);

#endif
