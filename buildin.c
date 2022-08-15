#include "shell.h"

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

void h_exit(char **args)
{
    (void)args;
    exit(0);
}

void h_cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "hsh: cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("hsh: cd");
        }
    }
}

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

void h_env(char **args)
{
    char **env = environ;

    while (*env)
      printf("%s\n", *env++);

    (void)args;
}
