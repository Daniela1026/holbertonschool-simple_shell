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

int execute(char **args)
{
	pid_t my_pid;
	int status;
	char **envp;
	char *command;
	
	envp = environ;

	builtin_cmd(args);

	command = _which(args[0]);
	if (command == NULL)
		return (-1);

	my_pid = fork();
	
	if (my_pid == 0)
	{
		execve(command, args, envp);
		perror(args[0]);
		return(-1);
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


char *_which(char *command)
{
    char *path, *copy_path, *path_token, *dir;
    int command_length, directory_length;
    struct stat testfile;

    /* check if the command given is a directory and pass it directly to execve */
    if (command[0] == '/' || command[0] == '.')
    {
        if (stat(command, &testfile) == 0)
        {
            return (command);
        }
    }

    path = getenv("PATH");
    if (path)
    {
        copy_path = strdup(path);
        command_length = strlen(command);

        path_token = strtok(copy_path, ":");

        while (path_token != NULL)
        {
            directory_length = strlen(path_token);
            dir = malloc(directory_length + command_length + 2); /* add 2 for the slash and null character to be added to the path */
            strcpy(dir, path_token);
            strcat(dir, "/");
            strcat(dir, command);
            strcat(dir, "\0");

            /* check to see if the file that the path gotten points to actually exists */
            if (stat(dir, &testfile) == 0)
            {
                free(copy_path);
                return (dir);
            }

            free(dir);
            path_token = strtok(NULL, ":");
        }

        free(copy_path);
        if (stat(command, &testfile) == 0)
        {
            return (command);
        }

        return (NULL);
    }

    return (NULL);
}
