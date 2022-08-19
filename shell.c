#include "shell.h"
/**
*main - simple shell
*
*Return: exit success
*/

int main(void)
{
	char *line = NULL;
	int ex_status = 0;
	char *args[BUFSIZ];
	char *delim = " \n\t";

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		line = read_line(NULL);
		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(WEXITSTATUS(ex_status));
		}
		token_generate(args, line, delim);
		ex_status = execute(args);
		if (ex_status == ARG_ONLY_SPACE)
		{
			free(line);
			continue;
		}
		free(line);
	}
}                                    
