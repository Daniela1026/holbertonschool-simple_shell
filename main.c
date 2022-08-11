#include "shell.h"

/**
* main - Display a prompt
* Return: Always 0.
*/

int main(void)
{
	char *promtp = "simple_shell $";
	char *line = NULL;
	char **token;
	int execute;
	size_t line_size = 0;
	size_t input;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", promtp);

		write(STDIN_FILENO, "$", 2);
		getline(&line, &line_size, stdin);
		printf("La linea leida es: %s\n",line);

		token = _tokens(line);
		if (!token[0])
			continue;

		execute = builtin_execute(token);
	
		if (execute == 0 && execute == -1)
		{
			free(token);
			free(line);
		}

		if (execute == 0)
			continue;
		if (execute == -1)
			break;

		if (!isatty(0))
			break;
	}
	return (0);
}
