#ifndef SHELL_H
#define SHELL_H

#define SIZE 128

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*
 * getline function
 */
int _getline(char **line, const int fd);
int _read(int fd, char **rd, char *buff);

/*
 * Utility functions
 */
int _index(char *s, char c);

/*
 * String Utility functions
 */
char *_strdup(char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *);
void _puts(char *);
char *_strcat(char *dest, char *src);

/*
 * Parser functions
 */
char *_strtok(char *str, const char *delim);
char *_strpbrk(char *s, const char *accept);

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

#endif
