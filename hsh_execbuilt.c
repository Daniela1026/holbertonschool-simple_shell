#include "shell.h"

/**
 *read_line - use getline
 *@line: argumens of the line
 *
 *Return: getline
 */
char *read_line(char *line)
{
	int size = 0;
	size_t buflen = 0;

	if (getline(&line, &buflen, stdin) == EOF)
	{
		free(line);
		exit(EXIT_SUCCESS);

	}
	size = _strlen(line);
	line[size - 1] = '\0';

	return (line);
}

/**
 *token_generate - generete token
 *@tokens: tokens of the line
 *@line: argumens of the line
 *@delim: delimiters
 *
 *Return: void
 */
void token_generate(char **tokens, char *line, char *delim)
{
	ssize_t i = 0;
	char *token = NULL;

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;
}

/**
 *execute - execute new process
 *@args: argumens input
 *
 *Return: EXIT_SUCCESS
 */
int execute(char **args)
{
	pid_t my_pid;
	int status = 0;

	if (!args[0])
		return (ARG_ONLY_SPACE);


	if (builtin_cmd(args) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);

	args[0] = _which(args[0]);
	if (!args[0])
		return (EXIT_FAILURE);

	my_pid = fork();

	if (my_pid == 0)
	{
		execve(args[0], args, environ);
		exit(EXIT_SUCCESS);
	}
	else if (my_pid > 0)
	{
		do {waitpid(my_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(args[0]);
	}

	else
		perror("hsh");

	return (status);
}

/**
 *_which - parse command
 *@command: input command
 *
 *Return: NULL
 */
char *_which(char *command)
{
	char *path = getenv("PATH"), *copy_path = NULL;
	char *path_token = NULL, *dir = NULL;
	int command_len = _strlen(command), directory_len = 0;
	struct stat testfile;

	if (stat(command, &testfile) == 0)
		return (command);

	if (path)
	{
		copy_path = _strdup(path);
		if (!copy_path)
			return (NULL);
		
		path_token = strtok(copy_path, ":");
		while (path_token != NULL)
		{
			directory_len = _strlen(path_token) + command_len + 1;
			dir = malloc(sizeof(char) * directory_len + 1);
			if (!dir)
				return (NULL);
			_strcpy(dir, path_token);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");
			if (stat(dir, &testfile) == 0)
			{
				free(copy_path);
				return (dir);
			}
			free(dir);
			path_token = strtok(NULL, ":");
		}
		free(copy_path);
		return (NULL);
	}
	return (NULL);
}
