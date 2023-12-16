#ifndef SHELL_H
#define SHELL_H

#define BUFF_SIZE 1024

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>

extern int errno;

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

/*
 * -----------------------------------------------------------------------
 * Parser Declarations
 * -----------------------------------------------------------------------
 */

/**
 * enum rel - enum for type of relation between commands in a single line
 * @OR: indicating relation with next command is '||' operator.
 * @AND: indicating relation with next command is '&&' operator.
 * @SEM: indicating relation with next command is ';' or end operator,
 * note that the next command can be empty or NULL, so make sure to check
 * next elem.
 */
enum rel
{
	OR,
	AND,
	SEM
};

/**
 * struct s_cmd - singly linked list of commands
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

t_cmd *add_cmd(t_cmd **head, char **cmd, char type);
void free_2d_arr(char **cmd);
void print_cmd_list(t_cmd *head);
void free_cmd_list(t_cmd *head);
int parse(char *line, t_cmd **cmd_l);

/*
 * -----------------------------------------------------------------------
 * Linked list functions and data type
 * -----------------------------------------------------------------------
 */

/**
 * struct s_list - simple linked list of strings
 *
 * @val: string
 * @next: pointer to the next node
 */
typedef struct s_list
{
	char *val;
	struct s_list *next;
} t_list;

t_list *add_elem(t_list **head, char *val);
char **list_to_arr(t_list *head);
void print_list(t_list *head);
void free_list(t_list *head);

/*
 * Implemented Builtin functions
 */
int ft_echo(char **cmd);

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

void print_pair_list(t_pair *head);
t_pair *add_pair_node(t_pair *head, char *key, char *value, int is_alias);
t_pair *remove_pair_node(t_pair *head, char *key, int is_alias);
t_pair *initialize_pair_list(char *envp[]);
void free_pair_list(t_pair *head);

/*
 * execute functions
 */

int _execute(t_cmd *cmd_l, char **env, char *prog);

#endif
