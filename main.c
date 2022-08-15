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
	int return_ = 0;
	int file = 0;

	while (1)
	{	
		if (isatty(STDIN_FILENO) == 1 && file == 0)
			write(STDOUT_FILENO, "$ ", 2);
		line = read_line(&num_read);

		tokens = token_generate(line, num_read);

		if (num_read == -1)
		{
			write(2, "Exiting shell....\n", 18);
			exit(1);
		}

		tokens = token_generate(line, num_read);

		if (tokens[0] != NULL)
		{
			return_ = execute(tokens);
		}

	free(tokens);
	free(line);
	}
	return (return_);
}	
