#include "shell.c"

/**
* builtin_cmd - We get the commands
* struct builtin - struct
* @args:  Character Pointer
* return: args
*/

void builtin_cmd(char **args)
{
	int num = 0;
	int i;

	struct builtin builtins[] = {
		{"exit", h_exit},
		{"cd", h_cd},
		{"help", h_help},
		{"env", h_env},
	};
	num = sizeof(builtins) / sizeof(struct builtin);

	for (i = 0; i < num; i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}
}

/**
* h_exit - Commands the builtin
* @args: Character Pointer
*/

void h_exit(char **args)
{
	(void)args;
	exit(0);
}

/**
* h_cd - Commands the builtin
* @args: Character Pointer
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
* h_help - Commands the builtin
* @args: Character Pointer
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
* h_env - Commands the builtin
* @args: Character Pointer
*/

void h_env(char **args)
{
	char **env = environ;

	while (*env)
		printf("%s\n", *env++);

	(void)args;
}
