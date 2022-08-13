#include "shell.h"
 
 /**
  *
  *
  *
  *
  */
 char *read_line(ssize_t *line)
 {
 	char *buffer = NULL;
	size_t buflen = 0;
 
	*line = getline(&buffer, &buflen, stdin);
 
	return (buffer);
 }
 
 /**
  *
  *
  *
  */
 char **split_line(char *line)
 {
	int len = 0;
	int buffer = 16;
	char **tokens;
	char *delim = "\n\t\r";
	char *token = strtok(line, delim);
 
	tokens = malloc(buffer * sizeof(char*));
	if (!tokens)
	{
		perror("Error malloc");
		exit(1);
	}
	while (token != NULL)
	{
		tokens[len] = token;
		len++;
 
		if (len >= buffer)
		{
			buffer = (int) (buffer * 1.5);
			tokens = realloc(tokens, buffer * sizeof(char*));
			if (!tokens)
			{
 				perror("Error alloc");
				exit(1);
 			}
		}
 		token = strtok(NULL, delim);
	}
	tokens[len] = NULL;
	return (tokens);
}


int execute(char **args)
{
	pid_t my_pid;
	int status;
	char **envp;
	
	envp = environ;
	
	my_pid = fork();
	
	if (my_pid == 0)
	{
		execve(args[0], args, envp);
		perror("ERROR");
		return (-1);
	}
	else if (my_pid > 0)
	{
		do
		{
			waitpid(my_pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("hsh");
		return (-1);
	}
	return (0);
}

char** token_generate(char *line_read, ssize_t num)
{
	char *copy_line;
	char *delimi = "\n";
	int numtokens = 0;
	int i = 0;
	char *token;
	char **tokens;

	copy_line = malloc(sizeof(char) * num);
			
			strcpy(copy_line, line_read);
			
			token = strtok(line_read, delimi);
			
			while(token != NULL)
			{
			numtokens++;
			token = strtok(NULL, delimi);
			}
			numtokens++;
			
			tokens = malloc(sizeof(char *) * numtokens);

    token = strtok(copy_line, delimi);
    
    while(token != NULL)
    {
    tokens[i] = malloc(sizeof(char) * strlen(token));
    strcpy(tokens[i], token);
    i++;
    token = strtok(NULL, delimi);
    }
    tokens[i] = NULL;
    return (tokens);
}

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
