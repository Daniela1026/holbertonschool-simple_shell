#include "shell.h"

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

	buffer = malloc(sizeof(char) *buffer);
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
