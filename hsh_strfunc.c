#include "shell.h"

/**
 *_strlen - length of the string
 *@string:
 *
 *Return: 
 */
int _strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;

	return (i);
}

/**
 *_strcat - concatenates two strings
 *@dest:
 *@src:
 *Return:
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
