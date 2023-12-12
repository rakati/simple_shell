#ifndef SHELL_H
#define SHELL_H

#define SIZE 128

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int _getline(char **line, const int fd);
int _read(int fd, char **rd, char *buff);
int _strchr(char *s, char c);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strtok(char *str, const char *delim);
char *_strpbrk(char *s, const char *accept);

#endif
