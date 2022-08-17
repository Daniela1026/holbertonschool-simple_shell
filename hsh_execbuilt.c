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
 *execute - execute new process
 *@args: argumens input
 *
 *Return: EXIT_SUCCESS
 */
int execute(char **args)
{
	pid_t my_pid;
	int status = 0;
	char **envp = NULL;
	char *command = NULL;

	envp = environ;

	builtin_cmd(args);

	command = _which(args[0]);
	if (command == NULL)
		return (-1);

	my_pid = fork();

	if (my_pid == 0)
	{
		execve(args[0], args, envp);
		exit(EXIT_SUCCESS);
	}
	else if (my_pid > 0)
	{
		do {waitpid(my_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	else
		perror("hsh");

	return (EXIT_SUCCESS);
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
 *_which - parse command
 *@command: input command
 *
 *Return: NULL
 */
char *_which(char *command)
{
	char *path = NULL, *copy_path = NULL;
	char *path_token = NULL, *dir = NULL;
	int command_length = 0, directory_length = 0;
	struct stat testfile;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &testfile) == 0)
			return (command);
	}
	path = getenv("PATH");
	if (path)
	{
		copy_path = _strdup(path);
		command_length = _strlen(command);
		path_token = strtok(copy_path, ":");
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			dir = malloc(directory_length + command_length + 2);
			_strcpy(dir, path_token);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");
			if (stat(dir, &testfile) == 0)
			{
				free(copy_path);
				return (dir);
			}
			path_token = strtok(NULL, ":");
			free(dir);
		}
		free(copy_path);
		if (stat(command, &testfile) == 0)
			return (command);
		return (NULL);
		free(path_token);
	}
	return (NULL);
}
