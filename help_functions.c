#include "shell.h"

/**
 *
 *
 *
 *
 */
char **_tokens(char *line, ssize_t num)
{
	char *copy_line;
	char *delimiter = " \n";
	int ntoken = 0;
	int i = 0;
	char *tok;
	char **tokens;
	
	copy_line = malloc(sizeof(char) * num);
	
	strcpy(copy_line, line);
	
	tok = strtok(line, delimiter);
	
	while(tok != NULL)
	{
		ntoken++;
		tok = strtok(NULL, delimiter);
	}
	ntoken++;
	
	tokens = malloc(sizeof(char *) * ntoken);
	
	tok = strtok(copy_line, delimiter);
	
	while(tok != NULL)
	{
		tokens[i] = malloc(sizeof(char) * strlen(tok));
		strcpy(tokens[i], tok);
		i++;
		tok = strtok(NULL, delimiter);
	}
	
	tokens[i] = NULL;

    return (tokens);
}

/**
 *
 *
 *
 *
 */
char *get_line(ssize_t *num)
{
	char *buffer = NULL;
	size_t i = 0;

	*num = getline(&buffer, &i, stdin);
	return (buffer);
}

/**
 *
 *
 *
 *
 */
int execute(char **tokens)
{
	char *command;
	char **intg = entorn;
	int status;

	pro_t process;
	
	builtin_execute(tokens);
	
	command = _route(tokens[0]);
	if (command == NULL)
	{
		return (-1);
	}
	
	process = fork();
	
	if (process == 0)
	{
		execve(command, tokens, intg);
		perror(tokens[0]);
		return (-1);
	}
	
	else if (process > 0)
	{
		do
		{
			waitpid(process, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("hsh");
		return (-1);
	}
	return (0);
}

/**
 *
 *
 *
 *
*/
char * _route(char *command)
{
}

/**
 *
 *
 *
 *
*/
void builtin_execute(char **args)
{
}

