  #include "shell.h"

/**
 * 
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
 		write(STDOUT_FILENO, "$ ", 2);
 		line = read_line(&num_read);
 		tokens = split_line(line);

		tokens = token_generate(line, num_read);

		if (num_read == -1)
		{
			write(2, "Exiting shell....\n", 18);
			exit(1);
		}
 
		if (tokens[0] != NULL)
		execute(tokens);

 		free(tokens);
		free(line);
 	}
 	free(line);
	return (EXIT_SUCCESS);
 }
