#ifndef _SHELL_H_
#define _SHELL_H_

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

extern char **environ;

struct builtin {
    char *name;
    void (*func)(char **args);
};

int main(void);
char *read_line(char *line);
int execute(char **args);
void token_generate(char **tokens, char *line, char *delim);
char *_which(char *command);

/* string functions */
int _strlen(char *str);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *dest, char *src);

void builtin_cmd(char **args);
void h_exit(char **args);
void h_cd(char **args);
void h_help(char **args);
void h_env(char **args);


#endif /* _SHELL_H_ */
