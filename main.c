#include "shell.h"

/**
* main - Display a prompt
* Return: Always 0.
*/

int main(void)
{
	char *line;
	char **token;
	ssize_t num;
	int code_return = 0;
	
	while (1)
	{
		write(2, "$ ", 2);
		
		line = get_line(&num);
		
		if (num == -1)
		{
			write(2, "Exiting shell....\n", 18);
			exit(1);
		}
		
		token = _tokens(line, num);
		
		if (token[0] != NULL)
		{
			code_return = execute(token);
		}
		
		free(token);
		free(line);

    }

    return (code_return);
}
