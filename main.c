#include <stdio.h>
#include <unistd.h>

int main()
{
	char *promtp = "simple_shell $";
	int status = 0;
	char *line = NULL;
	size_t line_size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", promtp);
		getline(&line, &line_size, STDIN_FILENO);
		printf("La linea leida es: %s\n",line);
		if (!isatty(STDIN_FILENO))
			break;
	}
	return (0);
}
