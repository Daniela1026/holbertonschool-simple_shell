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

int _args(void);
int main(void);
char *read_line(ssize_t *line);
char **split_line(char *line);
int execute(char **args);
char** token_generate(char *line_read, ssize_t num);
void builtin_cmd(char **args);
void h_exit(char **args);
void h_cd(char **args);
void h_help(char **args);
void h_env(char **args);
char * _which(char *command);


#endif /* _SHELL_H_ */
