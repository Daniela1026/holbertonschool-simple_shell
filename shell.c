#include "shell.h"

/**
 * main
 *
 *
 *
 */
int main(void)
{
	char *line;
	char *tokens[1024];
	char *delim = " \n\t";
	ssize_t num_read;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line(&num_read);
		if (num_read == EOF)
			exit(EXIT_SUCCESS);

		if (num_read == 1)
			continue;

/*		tokens = token_generate(line, num_read);*/
		token_generate(tokens, line, delim);
		execute(tokens);
		free(line);

	}
	return (EXIT_SUCCESS);
}
