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

 	while (true)
 	{
 		write(STDOUT_FILENO, "$ ", 2);
 		line = read_line();
 		tokens = split_line(line);
 
		if (tokens[0] != NULL)
		execute(tokens);

 		free(tokens);
		free(line);
 	}
 	free(line);
	return (EXIT_SUCCESS);
 }
