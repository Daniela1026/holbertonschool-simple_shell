#ifndef shell_h
#define shell_h
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stddef.h>
extern char **environ;
#define ARG_ONLY_SPACE 8

char *read_line(char *line);
void token_generate(char **args, char *line, char *delim);
int execute(char **args);
char *cmd(char *command);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *dest, char *src);
int builtin_cmd(char **args);
void h_exit(char **args __attribute__((unused)));
void h_cd(char **args);
void h_help(char **args __attribute__((unused)));
void h_env(char **args __attribute__((unused)));
#endif
