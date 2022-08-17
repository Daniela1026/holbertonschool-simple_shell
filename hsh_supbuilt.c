#include "shell.h"

/**
 *builtin_cmd - We get the commands
 *@args: Character Pointer
 *
 *return: args
 */

void builtin_cmd(char **args)
{
	int num = 0;
	int i;

	builtin builtins[] = {
		{"exit", h_exit},
		{"cd", h_cd},
		{"help", h_help},
		{"env", h_env},
	};
	num = sizeof(builtins) / sizeof(struct builtin);

	for (i = 0; i < num; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}
}

/**
 *h_exit - Commands the builtin
 *@args: Character Pointer
 */

void h_exit(char **args)
{
	(void)args;
	exit(0);
}

/**
 *h_cd - Commands the builtin
 *@args: Character Pointer
 */

void h_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: cd: missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh: cd");
		}
	}
}

/**
 *h_help - Commands the builtin
 *@args: Character Pointer
 */

void h_help(char **args)
{
	char *helptext =
		"The following commands are available:\n"
		"  cd       Change the working directory.\n"
		"  exit     Exit the shell.\n"
		"  help     Print this help text.\n";
	printf("%s", helptext);

	(void)args;
}

/**
 *h_env - Commands the builtin
 *@args: aguments
 */

void h_env(char **args)
{
	char **env = environ;
	int i = 0;

	while (env[i])
		printf("%s\n", env[i]), i++;

	(void) args;
}
