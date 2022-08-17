#include "shell.h"

/**
 *main - simple shell
 *
 *Return: exit success
 */
int main(void)
{
	char *line = NULL;
/*	char copy_line[BUFSIZ];*/
	char *tokens[BUFSIZ];
	char *delim = " \n\t";

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line(NULL);
		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		token_generate(tokens, line, delim);
		if (execute(tokens) == 8)
		{
			free(line);
			continue;
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
