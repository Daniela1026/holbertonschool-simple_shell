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

/**
 *
 *
 *
 *
 */
char **_tokens(char *str)
{
	char **buffer;
	char *tkn;
	unsigned int value = 0;

	buffer = malloc(sizeof(char) * BUFFER);
	if (!buffer)
	{
		errors(1);
		exit(EXIT_FAILURE);
	}

	buffer = strtok(str, "\n\t\r");

	while (buffer != NULL)
	{
		buffer[value] = tkn;
		tkn = strtok(NULL, "\n\t\r");
		value++;
	}

	buffer[value] = NULL;

	return (buffer);
}

/**
 *
 *
 *
 */
void errors(int error)
{
	switch (error)
	{
		case 1:
			write(STDERR_FILENO, ERR_MALLOC, _strlen_(ERR_MALLOC));
			break;
		case 2:
			perror("Error");
			break;
		case 3:
			write(STDERR_FILENO, ERR_FORK, _strlen_(ERR_FORK));
			perror("Error");
			break;
		case 4: 
			write(STDERR_FILENO, ERR_PATH, _strlen_(ERR_PATH));
			break;

		default:
			return;
	}
}

/**
 *
 *
 *
 */

int _strlen_(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
