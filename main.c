#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
* main - Display a prompt
* Return: Always 0.
*/

int main(void)
{
	char *promtp = "simple_shell $";
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		if (isatty(0))
			printf("%s", promtp);
		getline(&line, &line_size, stdin);
		printf("La linea leida es: %s\n",line);
		if (!isatty(0))
			break;
	}
	return (0);
}
