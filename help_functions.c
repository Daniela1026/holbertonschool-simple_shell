#include "shell.h"
 
 /**
  *
  *
  *
  *
  */
 char *read_line(void)
 {
 	char *line = NULL;
	size_t buflen = 0;
 
	getline(&line, &buflen, stdin);
 
	return (line);
 }
 
 /**
  *
  *
  *
  */
 char **split_line(char *line)
 {
	int len = 0;
	int buffer = 16;
	char **tokens;
	char *delim = "\n\t\r";
	char *token = strtok(line, delim);
 
	tokens = malloc(buffer * sizeof(char*));
	if (!tokens)
	{
		perror("Error malloc");
		exit(1);
	}
	while (token != NULL)
	{
		tokens[len] = token;
		len++;
 
		if (len >= buffer)
		{
			buffer = (int) (buffer * 1.5);
			tokens = realloc(tokens, buffer * sizeof(char*));
			if (!tokens)
			{
 				perror("Error alloc");
				exit(1);
 			}
		}
 		token = strtok(NULL, delim);
	}
	tokens[len] = NULL;
	return (tokens);
}
void execute(char **args)
 {
 	pid_t my_pid;
 	int status;

 	my_pid = fork();

 	if (my_pid == 0)
 	{
 		_args(args);
 		perror ("Error arguments");
 		exit(1);
	}
	if (my_pid > 0)
	{
		do {
		waitpid(my_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
 	else
	perror("Error status");
 }
