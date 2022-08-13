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

/*int _args(void)
{
        char *args[2];
	char *environ[] = NULL;

        args[0] = "/bin/ls";
        args[1] = "ls";
        execve(args[0], args, NULL);

        return (EXIT_SUCCESS);
}*/

int execute(char **args)
{
	pid_t my_pid;
	int status;

	if (strncmp("exit", args[0], 4) == 0)
		return (-1);

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (my_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);

	return (0);
}
