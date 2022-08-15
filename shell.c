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
		{
			write(STDOUT_FILENO, "$ ", 2);
			line = read_line(&num_read);
			tokens = token_generate(line, num_read);
			execute(tokens);
			free(line);	
			free(tokens);

			if (num_read == EOF)
			{
				write(2, "Exiting shell....\n", 18);
				exit(0);
			}
			if (num_read == 1)
				continue;
		}
		else
		{
			line = read_line(&num_read);
			write(STDOUT_FILENO, line, num_read);
			break;
		}
	}
	return (EXIT_SUCCESS);
}
