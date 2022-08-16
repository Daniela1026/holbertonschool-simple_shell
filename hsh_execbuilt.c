#include "shell.h"

/**
 *
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
		free(args);
		perror("hsh");
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
 *
 *
 *
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
 *
 *
 */
char *_which(char *command)
{
	char *path = NULL, *copy_path = NULL;
	char *path_token = NULL, *dir = NULL;
	int command_length = 0, directory_length = 0;
	struct stat testfile;

	/* check if the command given is a directory and pass it directly to execve */
	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &testfile) == 0)
			return (command);
	}
	path = getenv("PATH");
	if (path)
	{
		copy_path = strdup(path);
		command_length = strlen(command);
		path_token = strtok(copy_path, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
/* add 2 for the slash and null character to be added to the path */
			dir = malloc(directory_length + command_length + 2);
			strcpy(dir, path_token);
			strcat(dir, "/");
			strcat(dir, command);
			strcat(dir, "\0");
/* check to see if the file that the path gotten points to actually exists */
			if (stat(dir, &testfile) == 0)
			{
				free(copy_path);
				return (dir);
			}
			free(dir);
			path_token = strtok(NULL, ":");
		}
		free(copy_path);
		if (stat(command, &testfile) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
