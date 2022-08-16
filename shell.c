#include "shell.h"

/**
 *main - simple shell
 *
 *Return: exit success
 */
int main(void)
{
	char *line = NULL;
	char *tokens[1024];
	char *delim = " \n\t";

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line(line);
		if (_strcmp(line, "exit\n") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		token_generate(tokens, line, delim);
		execute(tokens);
		free(line);
	}
	return (EXIT_SUCCESS);
}
