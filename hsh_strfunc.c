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

/**
 *_strcpy - copies string
 *@dest:
 *@src:
 *
 *Return:
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 *_strdup - duplicate one string
 *@str:
 *
 *Return:
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret = NULL;

	if (str == NULL)
		return (NULL);

	while (*str++)
		len++;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	
	for (len++; len--;)
		ret[len] = *--str;

	return(ret);
}

/**
 *
 *
 *
 */
int _strcmp(char *dest, char *src)
{
	while (*dest && *src)
	{
		if (*dest != *src)
			return (*dest - *src);
		dest++;
		src++;
	}
	if (*dest == *src)
		return (EXIT_SUCCESS);
	else
		return (*dest < *src ? -1 : 1);
}
