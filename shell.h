#ifndef _SHELL_H_
#define _SHELL_H_

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

extern char **process;
int main (void);
int hell(void);
char **_tokens(char *line, ssize_t num);
char *get_line(ssize_t *num);
int execute(char **tokens);
char * _route(char *command);
void builtin_execute(char **args);

#endif /* _SHELL_H_ */
