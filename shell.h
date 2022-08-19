#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define ARG_ONLY_SPACE 8

extern char **environ;

typedef struct builtin
{
	char *name;
	void (*func)(char **args);
} builtin;

int main(void);
char *read_line(char *line);
int execute(char **args);
void token_generate(char **args, char *line, char *delim);
char *cmd(char *command);

/* string functions */
int _strlen(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *dest, char *src);

int builtin_cmd(char **args);
void h_exit(char **args);
void h_cd(char **args);
void h_help(char **args);
void h_env(char **args);


#endif /* SHELL_H */
