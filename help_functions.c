#include "shell.h"
 
 /**
  *
  *
  *
  *
  */
 char *read_line(ssize_t *line)
 {
 	char *buffer = NULL;
	size_t buflen = 0;
 
	*line = getline(&buffer, &buflen, stdin);
 
	return (buffer);
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

char** token_generate(char *line_read, ssize_t num)
{
	char *copy_line;
	char *delimi = "\n";
	int numtokens = 0;
	int i = 0;
	char *token;
	char **tokens;

	copy_line = malloc(sizeof(char) * num);
			
			strcpy(copy_line, line_read);
			
			token = strtok(line_read, delimi);
			
			while(token != NULL)
			{
			numtokens++;
			token = strtok(NULL, delimi);
			}
			numtokens++;
			
			tokens = malloc(sizeof(char *) * numtokens);

    token = strtok(copy_line, delimi);
    
    while(token != NULL)
    {
    tokens[i] = malloc(sizeof(char) * strlen(token));
    strcpy(tokens[i], token);
    i++;
    token = strtok(NULL, delimi);
    }
    tokens[i] = NULL;
    return (tokens);
}
