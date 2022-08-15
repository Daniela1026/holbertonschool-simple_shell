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
	char **tokens;
	ssize_t num_read;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line(&num_read);
		if (num_read == EOF)
		{
/*			write(2, "Exiting shell....\n", 18);*/
			exit(EXIT_SUCCESS);
		}

		if (num_read == 1)
			continue;

		tokens = token_generate(line, num_read);
		execute(tokens);
		free(line);	
		free(tokens);
	}
	return (EXIT_SUCCESS);
}
