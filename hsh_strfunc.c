#include "shell.c"

/**
 *
 *
 *
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\n')
		i++;

	return (i);
}

/**
 *
 *
 *
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0, b = 0;

	while (s1[a] != '\0' && b == 0)
	{
		b = s1[a] - s2[a];
		a++;
	}

	return (b);
}

/**
 *
 *
 *
 */
char *_strdup(char *str)
{
	int len = 0, i = 0;
	char *buff;
	
	len = _strlen(str);

	if (!str)
		return (NULL);
	
	buff = malloc(sizeof(char) * len + 1);
	if (!buff)
		return (NULL);
	
	if (buff)
	{
		for (i = 0; str[i] != '\0'; i++)
			buff[i] = str[i];
	}

	buff[i] = '\0';
	return (buff);
}
